package DocUtils;
use strict;
use DirHandle;
use Encode;
use FileHandle;
use File::Basename;
use File::Spec;
use File::Path qw(make_path remove_tree);

#######
##
##  System Tools
##
#######

sub Mkdir
{
    my $class = shift;
    my %args = (path => undef,
                file => undef,
                @_);

    if (defined $args{path} and defined $args{file}) {
        die;
    }

    if (defined $args{file}) {
        my ($filename, $directories) = fileparse($args{file});
        $args{path} = $directories;
    }

    return if $args{path} eq "";
    make_path($args{path});
}

sub Rm
{
    my $class = shift;
    my %args = (file => undef,
                @_);

    remove_tree($args{file});
}

sub IsNewerThan
{
    my $class = shift;
    my %args = (file1 => undef,
                file2 => undef,
                @_);

    die unless ($args{file1});

    if ($args{file2}) {
        unless (-e $args{file2}) {
            return 1;
        }

        my $time1 = (stat "$args{file1}")[9];
        my $time2 = (stat "$args{file2}")[9];

        if ($time1 > $time2) {
            return 1;
        }
        return undef;
    }
    die;
}

sub Copy
{
    my $class = shift;
    my %args = (file => undef,
                to => undef,
                @_);

    DocUtils->Mkdir(file => $args{file});

    my $filename = fileparse($args{file});
    my $newfile  = File::Spec->catfile($args{to}, $filename);

    printf STDERR "cp $args{file} $newfile\n";
    system("cp $args{file} $newfile");
    system("chmod ug+w $newfile");
}

sub FindFiles
{
    my $class = shift;
    my %args = (path => undef,
                pattern => undef,
                @_);

    my $dh = DirHandle->new($args{path})
          || die ("cannot open dir: $args{path}");

    my @filelist;

    while (my $file = $dh->read()) {

        next if ($file eq "..");
        next if ($file eq ".");
        next if ($file =~ /^\./);

        push(@filelist, $file) if $file =~ /$args{pattern}/;

        my $subdir = File::Spec->catdir($args{path}, $file);

        if (-d $subdir) {
            my $relsubdir = $file;
            foreach my $file ($class->FindFiles(path => $subdir,
                                                pattern => $args{pattern}))
            {
                push(@filelist, File::Spec->catdir($relsubdir, $file));
            }
        }
    }
    return @filelist;
}

sub ParentDirectory
{
    my $class = shift;
    my %args = (path => undef,
                @_);

    my @paths = split("/", $args{path});
    pop(@paths);
    return join("/", @paths);
}

sub ParentDirectories
{
    my $class = shift;
    my %args = (path => undef,
                @_);

    my @paths = split("/", $args{path});

    my @dirs;
    for (my $i=0; $i<$#paths; ++$i) {
        push(@dirs, join("/", @paths[0..$i]));
    }
    return @dirs;
}

sub ExtractDirectories
{
    my $class = shift;
    my %args = (files                => undef,
                allParentDirectories => 0,
                @_);

    my %dirs;
    foreach my $file (@{$args{files}}) {
        my $dir = $class->Path(fullpath => $file);
        next if defined $dirs{$dir};

        $dirs{$dir} = 1;

        if ($args{allParentDirectories}) {
            foreach my $parent ($class->ParentDirectories(path => $dir)) {
                $dirs{$parent} = 1;
            }
        }
    }
    return sort keys %dirs;
}

######
##
## HANDLING OF FILENAMES, PATHS, ...
##
######

sub Path
{
    my $class = shift;
    my %args = (fullpath => undef,
                @_);

    if (($args{fullpath}) && ($args{fullpath}=~/\//)) {
        $args{fullpath} =~ s/\/[^\/]*$//;
        return $args{fullpath};
    }
    return "";
}

#######
##
##  File IO
##
#######

sub SaveLinebuffer
{
    my $class = shift;
    my %args = (file          => undef,
                path          => undef,
                linesRef      => undef,
                appendNewLine => 1,
                append        => undef,
                filter        => undef,
                @_);

    if ($args{path}) {
        $args{file} = File::Spec->catfile($args{path}, $args{file});
    }

    DocUtils->Mkdir(path => dirname($args{file}));

    my $op = ($args{append}) ? ">>" : ">";
    my $fh = FileHandle->new("$op $args{file}")
          || die "cannot open $args{file}";

    foreach my $line (@{$args{linesRef}}) {
        if ($args{filter}) {
            if (index($line, "#_")>=0) {
                my $str = $line;
                for my $key (keys %{$args{filter}}) {
                    while (my $i = index($str, "#_${key}_#")) {
                        last if $i<0;
                        substr($str, $i, length($key)+4, $args{filter}->{$key});
                    }
                }
                print $fh "$str";
                print $fh "\n" if $args{appendNewLine};
                next;
            }
        }
        print $fh "$line";
        print $fh "\n" if $args{appendNewLine};
    }
    $fh->close();
}

sub LoadLinebuffer
{
    my $class = shift;
    my %args = (file => undef,
                path => undef,
                removeTrailingSpaces => undef,
                removeNewlines => 1,
                @_);

    if ($args{path}) {
        $args{file} = File::Spec->catfile($args{path}, $args{file});
    }

    my $fh = FileHandle->new("< $args{file}");

    unless (defined $fh) {
        die "[ERROR] can not open \"$args{file}\" for reading.\n";
        return;
    }

    my @linebuffer;
    while (my $line = <$fh>) {
        $line = Encode::decode("utf-8", $line);
        if ($args{removeNewlines}) {
            chomp($line);
        }
        if ($args{removeTrailingSpaces}) {
            $line =~ s/^(.*?)\s*$/$1/;
        }
        push(@linebuffer, $line);
    }
    $fh->close();
    return \@linebuffer
}

sub Install
{
    my $class = shift;
    my %args = (file => undef,
                to => undef,
                @_);

    unless (-e $args{file}) {
        die;
    }

    my $filename = fileparse($args{file});
    my $newfile  = File::Spec->catfile($args{to}, $filename);

    unless (DocUtils->IsNewerThan(file1 => $args{file}, file2 => $newfile)) {
        return undef;
    }

    DocUtils->Copy(%args);
    return 1;
}

1;
