package Doc;
use strict;
use DocUtils;
use Cwd;
use File::Basename;
use File::Spec;

BEGIN {
    our $inSubDef      = undef;
    our $inParagraph   = undef;
    our $inPurpSection = undef;
    our $inArgsSection = undef;
    our $addEmptyLine  = undef;

    our @subdef       = ();
    our @arguments    = ();
    our $argStartPos  = undef;
    our $argDescrPos  = 0;
    our %crash        = ();
    our %hasDoc       = ();

    our $srcFile   = undef;
    our $srcDir    = undef;
    our $subName   = undef;
}

sub HasDoc
{
    my $class = shift;
    my %args = (sourceFile => undef,
                @_);

    my $file = $args{sourceFile};

    if (defined $Doc::hasDoc{$file}) {
        if ($Doc::hasDoc{$file}==1) {
            return 1;
        } else {
            return undef;
        }
    } else {
        my $linebuffer = DocUtils->LoadLinebuffer(file => $file);
        if (_hasEmbeddedDoc($linebuffer)) {
            $Doc::hasDoc{$file} = 1;
            return 1;
        } else {
            $Doc::hasDoc{$file} = 0;
            return undef;
        }
    }
    return 1;
}

sub Extract
{
    my $class = shift;
    my %args = (sourceFile => undef,
                crashFile  => undef,
                cwd        => cwd(),
                @_);

    my ($srcfilename, $srcdir) = fileparse($args{sourceFile});

    $Doc::base    = $args{cwd};
    $Doc::srcFile = File::Spec->catfile($srcdir, $srcfilename . ".html");
    $Doc::srcFile = File::Spec->abs2rel($Doc::srcFile, $Doc::base);
    $Doc::srcDir  = $srcdir;
    $Doc::subName = undef;

    unless ($class->HasDoc(sourceFile => $args{sourceFile})) {
        return undef;
    }

    my $linebuffer = DocUtils->LoadLinebuffer(file => $args{sourceFile});
    $linebuffer = _getEmbeddedDoc($linebuffer);

    if ($#{$linebuffer}<0) {
        printf STDERR "[WARNING]  File '$args{sourceFile}' seems to contain ".
                      "documentation which could not be extracted.\n";
    }

    if ($args{crashFile}) {
        _crashImport($args{crashFile});
    }

    my @html;
    for (my $i=0; $i<=$#{$linebuffer}; ++$i) {
        my $line      = $linebuffer->[$i];
        my $firstChar = substr($line, 0, 1);


        if ($firstChar && $firstChar eq '*') {
#
#           We are in a comment
#
            if ($Doc::inSubDef) {
                _flushSubDef(htmlRef => \@html);
                $Doc::inSubDef = undef;
            }
            if (length($line)<=3) {
                _addEmptyLine(htmlRef => \@html);
                next;
            }

            #$line = substr($line, 3);
            $line =~ s/^\*\s{1,2}//;

            if ($line =~ /^\s*\.\./) {
                next;
            }

            if ($line =~ /^\s*--/) {
                next;
            }

            if ($i<$#{$linebuffer}
             && $linebuffer->[$i+1] =~ /^\*  (=+\s*=+)$/)
            {
#
#               We might have found a section
#
                if (length($1)>=length($line)) {
                    _closeParagraph(htmlRef => \@html);
                    _addSection(name => $line, htmlRef => \@html);
                    ++$i;
                    next;
                }
            }
            _openParagraph(htmlRef => \@html);
            _addLine(htmlRef => \@html, line => $line);
        } else {
            if ($line =~ /SUBROUTINE\s*(\w+)/
             || $line =~ /FUNCTION\s*(\w+)/
             || $line =~ /PROGRAM\s*(\w+)/)
            {
                $Doc::subName = $1;
                $Doc::inSubDef = 1;
                push(@Doc::subdef, $line);
                next;
            }
            if ($Doc::inSubDef && $line =~ /^\s\s\s\s\s\S/) {
                push(@Doc::subdef, $line);
                next;
            }
            if ($Doc::inSubDef) {
                _flushSubDef(htmlRef => \@html);
                $Doc::inSubDef = undef;
            }
        }
    }
    _closeParagraph(htmlRef => \@html);
    _flushArgs(\@html);

    return \@html;
}

sub AddGraphs
{
    my $class = shift;
    my %args = (htmlRef    => undef,
                path       => undef,
                callDump   => undef,
                callerDump => undef,
                @_);

    my $iframeOpts = "width=\"90%\" height=\"400\" name=\"graph\"";
    $iframeOpts .= " frameborder=\"0\" scrolling=\"yes\" ";

    my $src;
    my $svg;
    my $absSrc;
    my $absSvg;

    return unless $Doc::subName;

    $src    = File::Spec->catfile($args{path}, lc($Doc::subName).".call");
    $svg    = File::Spec->catfile($args{path}, lc($Doc::subName).".call.svg");
    $absSrc = File::Spec->catfile($Config::htmlDir, $src);
    $absSvg = File::Spec->catfile($Config::htmlDir, $svg);
    if ($args{callDump}) {
        if ($#{$args{callDump}}>2000) {
            printf STDERR "  Skipping conversion (more than 2000 lines).\n";
        } else {
            DocUtils->SaveLinebuffer(file => $absSrc,
                                     linesRef => $args{callDump});

            printf STDERR "  Converting call graph to SVG ... ";
            system("dot -Tsvg -o $absSvg $absSrc");
            printf STDERR "done.\n";

            _addSection(%args, name => "Call Graph");
            $svg = File::Spec->abs2rel($svg, $Doc::base);

            push(@{$args{htmlRef}}, "<iframe src=\"$svg\" $iframeOpts>");
            push(@{$args{htmlRef}}, "</iframe>");
        }
    }

    $src    = File::Spec->catfile($args{path}, lc($Doc::subName).".caller");
    $svg    = File::Spec->catfile($args{path}, lc($Doc::subName).".caller.svg");
    $absSrc = File::Spec->catfile($Config::htmlDir, $src);
    $absSvg = File::Spec->catfile($Config::htmlDir, $svg);
    if ($args{callerDump}) {
        if ($#{$args{callerDump}}>2000) {
            printf STDERR "  Skipping conversion (more than 2000 lines).\n";
        } else {
            DocUtils->SaveLinebuffer(file => $absSrc,
                                     linesRef => $args{callerDump});

            printf STDERR "  Converting caller graph to SVG ... ";
            system("dot -Tsvg -o $absSvg $absSrc");
            printf STDERR "done.\n";

            _addSection(%args, name => "Caller Graph");
            $svg = File::Spec->abs2rel($svg, $Doc::base);

            push(@{$args{htmlRef}}, "<iframe src=\"$svg\" $iframeOpts>");
            push(@{$args{htmlRef}}, "</iframe>");
        }
    }
}

sub _crashImport
{
    my $file = shift;

    my @linebuffer = @{DocUtils->LoadLinebuffer(file => $file)};

    %Doc::crash = ();

    # type     = $field[0];
    foreach my $line (@linebuffer) {
        my @field  = split(',', $line, 5);

        # type     = $field[0];
        # cursor   = $field[1];
        # tokenid  = $field[3];
        # content  = $field[4];

        if ($field[0] eq "DEFINITION"
         || $field[0] eq "ARGDEF") {
            $Doc::crash{$field[3]} = $field[2];
        }
    }
}


sub _flushSubDef
{
    my %args = (htmlRef => undef,
                @_);

    push(@{$args{htmlRef}}, "<h1>$Doc::subName</h1>");
    push(@{$args{htmlRef}}, "<div class=\"coderef_outer\">");
    push(@{$args{htmlRef}}, "<div class=\"coderef\">");
    push(@{$args{htmlRef}}, "<div class=\"code_content\">");
    push(@{$args{htmlRef}}, "<span class=\"code_content\">");
    push(@{$args{htmlRef}}, "<a class=\"coderef\" href=\"$Doc::srcFile\"><br>");
    foreach my $line (@Doc::subdef) {
        $line =~ s/ /&nbsp;/g;
        push(@{$args{htmlRef}}, "$line<br>");
    }
    push(@{$args{htmlRef}}, "<br></a></span></div></div></div>");
    @Doc::subdef = ();
}

sub _addLine
{
    my %args = (htmlRef => undef,
                line    => undef,
                @_);

    my $p = defined($Doc::argStartPos) ? $Doc::argStartPos : 10;

    if ($Doc::inArgsSection) {
        if ($args{line} =~ /^(\s{0,$p})([A-Z0-9_]+)(\s+[\s-]*\s*)(\S.*)$/) {
            unless (defined $Doc::argStartPos) {
                $Doc::argStartPos = length($1);
            }
            $Doc::argDescrPos = length($1) + length($2) + length($3);
            my $entry = {varname     => $2,
                         type        => $4,
                         description => []
                        };
            $entry->{type} =~ s/ /&nbsp;/g;

            push(@Doc::arguments, $entry);
            $Doc::addEmptyLine = undef;
            return;
        }
        unless ($#Doc::arguments>=0) {
            printf STDERR "line=$args{line}\n";
            printf STDERR "Died in src $Doc::srcFile\n";
            printf STDERR "   \$p = $p\n";
            $args{line} =~ /^(\s{0,$p})([A-Z0-9_]+)(\s+[\s-]*\s*)(\S.*)$/;
            printf STDERR "   \$1 = $1\n";
            printf STDERR "   \$2 = $2\n";
            printf STDERR "   \$3 = $3\n";
            printf STDERR "   \$4 = $4\n";
            die;
        }
        $args{line} =~ s/^\s{0,$Doc::argDescrPos}//;
        $args{htmlRef} = $Doc::arguments[-1]->{description};
    }


    if ($Doc::addEmptyLine) {
        push(@{$args{htmlRef}}, "<br>");
        $Doc::addEmptyLine = undef;
    }
    my $line = $args{line};
    $line =~ s/ /&nbsp;/g;

    push(@{$args{htmlRef}}, "$line<br>");
}

sub _addEmptyLine
{
    my %args = (htmlRef => undef,
                @_);

    $Doc::addEmptyLine = 1;
}

sub _flushArgs
{
    my $html = shift;

    if ($Doc::inArgsSection) {
        $Doc::inArgsSection = undef;

        push(@{$html}, "<table class=\"ARGUMENTS\">");
        foreach my $entry (@Doc::arguments) {
            push(@{$html}, "<tr class=\"ARGUMENTS\">");

#
#           Variable name
#
            push(@{$html}, "<td class=\"ARGUMENTS VARNAME\">");
            my $link = $entry->{varname};
            if ($Doc::crash{lc($link)}) {
                $link = lc($entry->{varname});
                $link = "<a name=\"$link\"></a>" .
                        "<a class=\"ARGUMENTS VARNAME\" " .
                        "href=\"$Doc::srcFile#$Doc::crash{$link}\">" .
                        $entry->{varname} .
                        "</a>";
            } else {
            }
            push(@{$html}, "<b class=\"VARNAME\">$link</b>");
            push(@{$html}, "</td>");
            push(@{$html}, "<td class=\"ARGUMENTS DESCRIPTION\">");
#
#           Type
#
            push(@{$html}, "<div class=\"ARGUMENTS TYPE DESCRIPTION\">");
            push(@{$html}, "<span class=\"ARGUMENTS TYPE DESCRIPTION\">");
            push(@{$html}, "$entry->{type}");
            push(@{$html}, "</div></span>");
#
#           Description
#
            push(@{$html}, "<div class=\"DESCRIPTION\">");
            push(@{$html}, "<span class=\"DESCRIPTION\">");
            foreach my $line (@{$entry->{description}}) {
                push(@{$html}, "$line");
            }
            push(@{$html}, "</div></span>");

            push(@{$html}, "</td>");
            push(@{$html}, "</tr>");
        }
        push(@{$html}, "</table>");
    }
    @Doc::arguments   = ();
    $Doc::argStartPos = undef;
}

sub _addSection
{
    my %args = (htmlRef => undef,
                name    => undef,
                @_);

    if ($Doc::inArgsSection) {
        _flushArgs($args{htmlRef});
    }

    $Doc::addEmptyLine  = undef;
    $Doc::inPurpSection = undef;
    $Doc::inArgsSection = undef;

    if ($args{name} =~ /Purpose/) {
        $Doc::inPurpSection = 1;
    } elsif ($args{name} =~ /Arguments/) {
        $Doc::inArgsSection = 1;
    }

    my $section = $args{name};
    $section =~ s/\s/_/g;

    push(@{$args{htmlRef}}, "<a name=\"section_$section\"></a>");
    push(@{$args{htmlRef}}, "<h2 class=\"SECTION\">$args{name}</h2>");
}

sub _openParagraph
{
    my %args = (htmlRef => undef,
                @_);

    unless ($Doc::inParagraph) {
        push(@{$args{htmlRef}}, "<div class=\"DESCRIPTION\">");
        push(@{$args{htmlRef}}, "<span class=\"DESCRIPTION\">");
        $Doc::addEmptyLine = undef;
        $Doc::inParagraph = 1;
    }
}

sub _closeParagraph
{
    my %args = (htmlRef => undef,
                @_);

    $Doc::addEmptyLine = undef;
    if ($Doc::inParagraph) {
        push(@{$args{htmlRef}}, "</span></div>");
        $Doc::inParagraph = undef;
    }
}

sub _getEmbeddedDoc
{
    my @linebuffer = @{$_[0]};

#
#   Typically the embedded documentation is terminated by an empty line followed
#   by a line containing only '=' characters.
#
    for (my $i=0; $i<$#linebuffer; ++$i) {
        unless ($linebuffer[$i] =~ /^\*\s*$/) {
            next;
        }
        if ($linebuffer[$i+1] =~ /^\*\s*=+$/) {
            my @doc = @linebuffer[0..$i];
            _rtrim(@doc);
            return \@doc;
        }
    }
#
#   In some cases the empty line is missing in LAPACK.  So we also look
#   for a line only containing '=' characters which do not belong to the
#   underlining of a section.  That means the length of the previous line
#   must be shorter.
#
    for (my $i=0; $i<$#linebuffer; ++$i) {
        if ($linebuffer[$i+1] =~ /^\*\s*=+$/) {
            if (length($linebuffer[$i])>=length($linebuffer[$i+1])) {
                next;
            }
            my @doc = @linebuffer[0..$i];
            _rtrim(@doc);
            return \@doc;
        }
    }

    return undef;
}

sub _hasEmbeddedDoc
{
    my @linebuffer = @{$_[0]};

    for (my $i=0; $i<$#linebuffer; ++$i) {
        if ($linebuffer[$i+1] =~ /^\*\s*=+$/) {
            return 1;
        }
    }
    return undef;
}

sub _rtrim
{
    for (my $i=0; $i<=$#_; ++$i) {
        $_[$i] =~ s/\s+$//;
    }
}


1;
