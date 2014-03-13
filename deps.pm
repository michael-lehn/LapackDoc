package Deps;

BEGIN {
    our %external;
    our %call;
    our %caller;
}

use strict;
use DocUtils;
use Doc;
use Cwd;
use File::Basename;
use Storable;
use Data::Dumper;

sub Reset
{
    my $class = shift;

    %Deps::external = ();
    %Deps::call = ();
    %Deps::caller = ();
}

sub SaveArchive
{
    my $class = shift;
    my %args = (file => undef,
                @_);

    die unless $args{file};

    my $cloneref = Storable::dclone({external => \%Deps::external,
                                     call     => \%Deps::call,
                                     caller   => \%Deps::caller});
    store($cloneref, $args{file});
}

sub LoadArchive
{
    my $class = shift;
    my %args = (file => undef,
                @_);

    die unless $args{file};

    my $stored = retrieve($args{file});

    %Deps::external = %{$stored->{external}};
    %Deps::call     = %{$stored->{call}};
    %Deps::caller   = %{$stored->{caller}};
}

sub Display
{
    my $class = shift;
    print Data::Dumper->Dump([\%Deps::external, \%Deps::call, \%Deps::caller],
                             ["external", "call", "caller"]);
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
                $Deps::call{$field[0]} = {};
            }
            $Deps::call{$field[0]}->{$field[2]} = 1;

#
#           $Deps::caller{A} = B;   # B is caller of A <=> B calls A
#
            unless ($Deps::caller{$field[2]}) {
                $Deps::caller{$field[2]} = {};
            }
            $Deps::caller{$field[2]}->{$field[0]} = 1;

        } else {

            unless ($Deps::external{$field[0]}) {
                $Deps::external{$field[0]} = {};
            }

            my $key = "$field[1]:$field[2]:$field[3]";
            my $entry= {type => $field[1],
                        file => $field[3],
                        line => $field[2]};

            $Deps::external{$field[0]}->{$key} = $entry;
        }
    }
}

sub Dump
{
    my $class = shift;
    my %args = (call     => undef,
                caller   => undef,
                cwd      => cwd(),
                frame    => 1,
                edge     => {},
                node     => {},
                @_);


    if ($args{call}) {

        $args{node}->{$args{call}} = 1;

        foreach my $sub (keys %{$Deps::call{$args{call}}}) {
            $args{edge}->{"$args{call} -> $sub"} = 1;

            if ($args{node}->{$sub}) {
                next;
            }

            $class->Dump(call  => $sub,
                         frame => undef,
                         edge  => $args{edge},
                         node  => $args{node});
        }

    } elsif ($args{caller}) {

        $args{node}->{$args{caller}} = 1;

        foreach my $sub (keys %{$Deps::caller{$args{caller}}}) {
            my $key = "$sub -> $args{caller}";
            $args{edge}->{$key} = 1;

            if ($args{node}->{$sub}) {
                next;
            }

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

                my @entry = values(%{$Deps::external{$p}});

                if ($#entry>0) {
                    # print STDERR "[WARNING] Multiple entries for '$p':";
                    # foreach my $entry (@entry) {
                    #     print STDERR ">    $entry\n";
                    #     print STDERR Dumper($entry);
                    #     print STDERR ">----------\n";
                    # }
                }

                my $entry = $entry[0];

                my $file = $entry->{file};
                my $doc = Doc->HasDoc(sourceFile => $file);

                if ($doc) {
                    $file =~ s/\.f$//;
                    $file .= ".html";
                } else {
                    $file .= ".html";
                    $file .= "#" . $entry->{line};
                }

                my $url = $file;
                $url = File::Spec->abs2rel($url, $args{cwd});

                push(@linebuffer, "    $p [URL=\"$url\" target=\"_top\"];");
            }
        }
        push(@linebuffer, "}");

        return \@linebuffer;
    }

}

1;
