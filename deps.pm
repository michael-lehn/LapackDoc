package Deps;

BEGIN {
    our %external;
    our %call;
    our %caller;
}

use strict;
use DocUtils;
use File::Basename;

sub Reset
{
    my $class = shift;

    %Deps::external = ();
}

sub Update
{
    my $class = shift;
    my %args = (depsFile => undef,
                @_);

    my $linebuffer = DocUtils->LoadLinebuffer(file => $args{depsFile});

    foreach my $line (@{$linebuffer}) {
        my @field  = split(',', $line, 4);

        if ($field[0] eq "") {
            printf STDERR "ERROR: line=$line\n";
            printf STDOUT "ERROR: line=$line\n";
            die "line";
        }

        unless ($field[1]) {
            printf STDERR "ERROR: line=$line file=$args{depsFile}\n";
            printf STDOUT "ERROR: line=$line file=$args{depsFile}\n";
            die;
        }

        if ($field[1] eq "CALLS") {

#
#           $Deps::call{A} = B;   #  A calls B
#
            unless ($Deps::call{$field[0]}) {
                $Deps::call{$field[0]} = [];
            }
            push(@{$Deps::call{$field[0]}}, $field[2]);

#
#           $Deps::caller{A} = B;   # B is caller of A <=> B calls A
#
            unless ($Deps::caller{$field[2]}) {
                $Deps::caller{$field[2]} = [];
            }
            push(@{$Deps::caller{$field[2]}}, $field[0]);

        } else {

            unless ($Deps::external{$field[0]}) {
                $Deps::external{$field[0]} = [];
            }

            my $entry= {type => $field[1],
                        file => $field[3],
                        line => $field[2]};

            push(@{$Deps::external{$field[0]}}, $entry);
        }
    }
}

sub Dump
{
    my $class = shift;
    my %args = (call     => undef,
                caller   => undef,
                frame    => 1,
                edge     => {},
                node     => {},
                @_);


    my $root;
    if ($args{call}) {

        $root = $args{call} . ".call";
        $args{node}->{$args{call}} = 1;

        foreach my $sub (@{$Deps::call{$args{call}}}) {
            $args{edge}->{"$args{call} -> $sub"} = 1;

            $class->Dump(call  => $sub,
                         frame => undef,
                         edge  => $args{edge},
                         node  => $args{node});
        }

    } elsif ($args{caller}) {

        $root = $args{caller} . ".caller";
        $args{node}->{$args{caller}} = 1;

        foreach my $sub (@{$Deps::caller{$args{caller}}}) {
            my $key = "$sub -> $args{caller}";
            $args{edge}->{$key} = 1;

            $class->Dump(caller => $sub,
                         frame  => undef,
                         edge   => $args{edge},
                         node  => $args{node});
        }

    }

    if ($args{frame}) {
        my @linebuffer;

        if ($args{call}) {
            push(@linebuffer, "digraph $args{call}_CallGraph {");
        } elsif ($args{caller}) {
            push(@linebuffer, "digraph $args{caller}_CallerGraph {");
        } else {
            push(@linebuffer, "digraph Graph {");
        }

        foreach my $p (keys %{$args{edge}}) {
            push(@linebuffer, "    $p;");
        }
        foreach my $p (keys %{$args{node}}) {
            if ($Deps::external{$p}) {
                my $file = $Deps::external{$p}->[0]->{file};
                my $doc = Doc->HasDoc(sourceFile => $file);

                if ($doc) {
                    $file =~ s/\.f$//;
                    $file .= ".html";
                } else {
                    $file .= ".html";
                    $file .= "#" . $Deps::external{$p}->[0]->{line};
                }

                my $url = $file;
                $url = File::Spec->abs2rel($url, $Config::graphsSubdir);

                push(@linebuffer, "    $p [URL=\"$url\" target=\"_top\"];");
            }
        }
        push(@linebuffer, "}");

        my $dotFile  = File::Spec->catfile($Config::graphsDir, "${root}.dot");
        my $svgFile  = File::Spec->catfile($Config::graphsDir, "${root}.svg");

        if ($#linebuffer<1000) {
            DocUtils->SaveLinebuffer(file     => $dotFile,
                                     linesRef => \@linebuffer);
            system("dot -Tsvg -o $svgFile $dotFile");
        }

    }

}

1;
