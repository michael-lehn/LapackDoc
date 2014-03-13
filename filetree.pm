package Filetree;
use strict;
use File::Basename;
use File::Spec;

sub new
{
    my $proto = shift;
    my $class = ref($proto) || $proto;

    my $self  = {directory      => undef,
                 allFiles       => undef,

                 filesTrimmed   => undef,
                 fileTree       => undef,
                 @_};
    die unless defined($self->{directory}) && defined($self->{allFiles});

    bless ($self, $class);

    $self->_trimmDirs;
    $self->_fileTree;
    return $self;
}

sub _trimmDirs
{
    my $self = shift;

    my @directory = split("/", $self->{directory});

    my @all = ();
    foreach my $dir (@{$self->{allFiles}}) {
        my @split = split("/", $dir);
        push(@all, \@split);
    }

    for (my $i=0; $i<=$#all; ++$i) {
        my $current = $all[$i];

        if ($#{$current} > $#directory+1) {
            delete @{$current}[$#directory+2..$#{$current}];
        }
    }

    for (my $j=1; $j<=$#directory+1; ++$j) {
        for (my $i=0; $i<=$#all; ++$i) {
            my $current = $all[$i];
            next if $j>$#{$current};

            unless (${$current}[$j-1] eq $directory[$j-1]) {
                delete @{$current}[$j..$#{$current}];
            }
        }
    }

    my %dirs;
    foreach my $dir (@all) {
        $dirs{join("/", @{$dir})} = 1;
    }
    $self->{filesTrimmed} = [sort keys %dirs];
}

sub _fileTree
{
    my $self = shift;

    my %tree;

    foreach my $dir (@{$self->{filesTrimmed}}) {
        my @items = split("/", $dir);
        my $current = \%tree;
        foreach my $item (@items) {
            if ($item =~ /\[[^\]]*\]$/) {
                $current->{$item} = "files:$dir";
                last;
            }

            unless (defined $current->{$item}) {
                $current->{$item} = {};
            }
            $current = $current->{$item};
        }

    }

    $self->{fileTree} = \%tree;
}

sub html
{
    my $self = shift;

    my @html;
    $self->FileTreeHtmlDump(fileTree  => $self->{fileTree},
                            directory => $self->{directory},
                            html      => \@html);
    return \@html;
}

sub FileTreeHtmlDump
{
    my $class = shift;
    my %args = (fileTree => undef,
                html     => undef,
                path     => ".",
                @_);

    my @items = sort keys %{$args{fileTree}};
    return if scalar(@items)==0;

    my $css = "class=\"filetree\"";

    push(@{$args{html}}, "<ul $css>");

    foreach my $item (@items) {
        if (${$args{fileTree}}{$item} =~ /^files/) {
            $item =~ /(.*)\[(.*)\]/;
            my $file = $1;
            my @ext  = split(",", $2);

            my $mark = File::Spec->catfile($args{path}, $file);
            $mark = "<a name=\"$mark\"></a>";

            my @links;
            my $listItem = $file;
            foreach my $ext (sort @ext) {

                my $link = $file;
                if ($ext eq "doc") {
                    $link = $link . ".html";
                } elsif ($ext eq "source") {
                    $link = $link . ".f.html";
                }

                if ($ext eq "doc") {
                    $listItem = "<a href=\"$link\">$file</a>";
                    next;
                }
                $link = "<a href=\"$link\">$ext</a>";
                push(@links, $link);
            }

            if (scalar(@links)>0) {
                $listItem = $listItem . " [ " . join (", ", @links) . " ]";
            }
            push(@{$args{html}}, "<li $css>$mark$listItem</li>");
        }
    }
    foreach my $item (@items) {
        unless (${$args{fileTree}}{$item} =~ /^files/) {
            my $currentPath = File::Spec->catfile($args{path}, $item);
            my $mark = "<a name=\"$currentPath\"></a>";
            my $subTree = ${$args{fileTree}}{$item};
            my $css = "class=\"filetree\"";

            if (scalar(keys %{$subTree})!=0) {
                my $parent = DocUtils->ParentDirectory(path => $currentPath);
                my $link = File::Spec->catfile("..", "dir.html");
                $link = "<a href=\"$link\">$item</a>";

                push(@{$args{html}}, "<li $css>$mark$link");
                $class->FileTreeHtmlDump(fileTree  => $subTree,
                                         html      => $args{html},
                                         directory => $args{directory},
                                         path      => $currentPath);
                push(@{$args{html}}, "</li>");
            } else {
                my $link = File::Spec->catfile($currentPath, "dir.html");

                $link = File::Spec->abs2rel($link, $args{directory});

                $link = "<a href=\"$link\">$item/</a>";
                push(@{$args{html}}, "<li $css>$mark$link</li>");
            }
        }
    }

    push(@{$args{html}}, "</ul>");
}

sub CompressFileList
{
    my ($class, $files) = @_;

    my %files;
    my $type;
    foreach my $file (@{$files}) {

        my ($filename, $dir) = fileparse($file);

        if ($filename eq "dir.html") {
            next;
        }

        $type = undef;
        if ($file =~ s/\.f\.html$//) {
            $type = "source";
        }
        if ($file =~ s/\.html$//) {
            $type = "doc";
        }

        if ($type) {
            unless (defined $files{$file}) {
                $files{$file} = [];
            }
            push(@{$files{$file}}, $type);
        }
    }

    # collect different file types and add them to %all
    my %all;
    foreach my $file (keys %files) {
        my $ext = join(",", sort @{$files{$file}});
        $all{$file . "[" . $ext . "]"} = 1;
    }

    return sort(keys %all);
}

1;
