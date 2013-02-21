package Convert;

BEGIN {

    our $sourcefile;

}

use strict;
use Deps;
use DocUtils;
use File::Basename;

sub Fortran
{
    my $class = shift;
    my %args = (sourcefile  => undef,
                crashfile   => undef,
                linenumbers => 1,
                @_);

    $Convert::sourcefile = $args{sourcefile};

    my @linebuffer = @{DocUtils->LoadLinebuffer(file => $args{sourcefile})};
    my @html;

    my %crash = _crashImport($args{crashfile});

    for (my $line=0; $line<=$#linebuffer; ++$line) {
        my $str = $linebuffer[$line];

        my $tpos = index($str, "\t");
        if ($tpos>=0 && $tpos<6) {
            substr($str, $tpos, 1, " " x (6-$tpos));
        }

        if ($crash{$line}) {
            my @col = sort {$a <=> $b} keys(%{$crash{$line}});

            my $col = 0;
            my $newstr;
            for (my $i=0; $i<=$#col; ++$i) {
                my $end  = $crash{$line}->{$col[$i]}->{end};
                if ($end<0) {
                    $end = length($str)-1;
                }

                if ($i==0) {
                    $newstr .= _lineStart(substr($str, $col, $col[$i]-$col));
                } else {
                    $newstr .= _string(substr($str, $col, $col[$i]-$col));
                }
                $newstr .= _highlight(substr($str, $col[$i], $end-$col[$i]+1),
                                      $crash{$line}->{$col[$i]});
                $col = $end+1;
            }
            $str = $newstr . _string(substr($str, $col, length($str)-$col));
        } else {
            $str = _lineStart($str);
        }

        push(@html, "$str<br>");
    }


    my $css = ($args{linenumbers}) ? " code_with_linenumbers" : "";
    my $startMonospace = "<div class=\"code_content\">" .
                         "<span class=\"code_content\">\n";
    my $endMonospace   = "</span></div><!--code_content-->\n";

    if ($args{linenumbers}) {
        @html = ("<table class=\"$css\"><tr><td class=\"code_linenumbers\">\n",
                 $startMonospace,
                 _makeLineNumbers(scalar(@linebuffer)),
                 $endMonospace,
                 "</td><td class=\"code_content\">\n",
                 $startMonospace,
                 @html,
                 $endMonospace,
                 "</td></tr></table>\n");
    }

    push(@html, "<br>" x 100);

    return \@html;
}

sub _lineStart
{
    my $str = shift;

    if (length($str)>=6) {
        my $col6 = substr($str, 5, 1);

        if ($col6 eq " ") {
            $col6 = _string($col6);
        } else {
            $col6 = "<span class=\"COL6\">$col6</span>";
        }

        return "<span class=\"STATEMENTNUMBER\">" .
               _string(substr($str, 0, 5)) .
               "</span>" . $col6 .
               _string(substr($str,6));

    }
    return "<span class=\"STATEMENTNUMBER\">" . _string($str) . "</span>";
}

sub _string
{
    my $str = shift;
    $str =~ s/ /&nbsp;/g;
    return $str;
}

sub _highlight
{
    my $str   = _string(shift);
    my $entry = shift;

    if ($entry->{type} eq "VARIABLE") {
        return "<a class=\"$entry->{type}\" href=\"#$entry->{tag}\">$str</a>";
    }

    if ($entry->{type} eq "ARGDEF") {
        my ($srcfile, $srcdir) = fileparse($Convert::sourcefile);
        $srcfile = basename($srcfile, ".f") . ".html";

        my $href = $srcfile . "#" . lc($entry->{content});
        return "<a class=\"$entry->{type}\" href=\"$href\">$str</a>";
    }

    if ($entry->{type} eq "SUBROUTINE" || $entry->{type} eq "FUNCTION") {
        my ($srcfile, $srcdir) = fileparse($Convert::sourcefile);
        $srcfile = basename($srcfile, ".f") . ".html";

        return "<a class=\"$entry->{type}\" href=\"$srcfile\">$str</a>";
    }


    if ($entry->{type} eq "EXTERNAL") {
        my ($srcfilename, $srcdir) = fileparse($Convert::sourcefile);


        unless ($Deps::external{$entry->{tag}}) {
            printf STDERR "WARNING: Cannot find external " .
                          "function/subroutine $str (tag=$entry->{tag})\n";
            return "<span class=\"EXTERNAL_TIP\">$str</span>";
        }
        my @defs = @{$Deps::external{$entry->{tag}}};

        if ($#defs==0) {

            my $href = $defs[0]->{file};
            $href = File::Spec->abs2rel($href, $srcdir);
            $href = $href . ".html#" . $defs[0]->{line};
            return "<a class=\"$entry->{type}\" href=\"$href\">$str</a>";

        } elsif ($#defs>0) {
            my $tip = "onmouseover=\"Tip('#TEXT#', WIDTH, 0, " .
                      "TITLE, '#TITLE#', SHADOW, false, FADEIN, 0, " .
                      "FADEOUT, 0, STICKY, 1, CLOSEBTN, true, " .
                      "CLICKCLOSE, true)\" onmouseout=\"UnTip()\"";

            _replace($tip, "#TITLE#", $str);

            my $css = "class=\"codelink_listitem\"";
            my $text = "<table $css>";
            my $maxLen = 0;
            my $maxNum = 0;
            foreach my $defs (@defs) {
                if (length($defs->{line})>$maxNum) {
                    $maxNum = length($defs->{line});
                }
            }
            foreach my $defs (@defs) {
                my $line = sprintf("%0${maxNum}d", $defs->{line});
                my $len = length($defs->{file})+length($line) + 10;
                if ($len > $maxLen) {
                    $maxLen = $len;
                }
            }

            foreach my $defs (@defs) {
                my $href = $defs->{file};
                $href = File::Spec->abs2rel($href, $srcdir);
                $href = $href . ".html#" . $defs->{line};

                my $file = $defs->{file};
                my $line = sprintf("%0${maxNum}d", $defs->{line});
                $line =~ /^(0*)/;
                my $replace = " " x length($1); 
                $line =~ s/^0*/$replace/;
                $line = "(Line " . $line . ")";
                my $pad  = $maxLen - length($file) - length($line);
                $line =~ s/ /&nbsp;/g;

                $text .= "<tr $css><td $css><a href=\"$href\" $css>" .
                         "&nbsp;" x 2 . $file .
                         "&nbsp;" x $pad .
                         $line .
                         "&nbsp;" x 2 .
                         "</a></td></tr>";
            }
            $text .= "</table>";
            _replace($text, '"', "\\'");
            _replace($tip, "#TEXT#", $text);
            return "<span $tip class=\"EXTERNAL_TIP codelink_listitem\">$str</span>";
        }
    }

    return "<span class=\"$entry->{type}\">$str</span>";
}

sub _replace
{
    my $i = index($_[0], $_[1]);
    while ($i>=0) {
        substr($_[0], $i, length($_[1]), $_[2]);
        $i = index($_[0], $_[1]);
    }
}

sub _crashImport
{
    my $file = shift;

    my @linebuffer = @{DocUtils->LoadLinebuffer(file => $file)};
    my %crash;


    # type     = $field[0];
    foreach my $line (@linebuffer) {
        my @field  = split(',', $line, 5);
        my @cursor = split(/\.|:/, $field[1]);

        # type     = $field[0];
        # fromLine = $cursor[0];
        # fromCol  = $cursor[1];
        # toLine   = $cursor[2];
        # toCol    = $cursor[3];
        # stno/tag = $field[2];
        # tokenid  = $field[3];
        # content  = $field[4];

        for (my $line=$cursor[0]; $line<=$cursor[2]; ++$line) {

            unless ($crash{$line}) {
                $crash{$line} = {};
            }

            my $fromCol = ($line==$cursor[0]) ? $cursor[1] :  6;
            my $toCol   = ($line==$cursor[2]) ? $cursor[3] : -1;

            if ($crash{$line}->{$fromCol}) {
                printf STDERR "line=$line  fromCol=$fromCol\n";
                printf STDERR "   old type $crash{$line}->{$fromCol}->{type}\n";
                printf STDERR "   new type $field[0]\n";
#die;
            }

            $crash{$line}->{$fromCol} = {type    => $field[0],
                                         end     => $toCol,
                                         tag     => $field[2],
                                         content => $field[3]};
        }
    }
    return %crash;
}

sub _makeLineNumbers
{
    my $total = shift;

    my @html;

    my $maxStrLen = length("$total");

    for (my $number=1; $number<=$total; ++$number) {
        my $str = sprintf("%0${maxStrLen}d", $number);
        $str =~ /^(0*)/;
        my $replace = "&nbsp;" x length($1);
        $str =~ s/^0*/$replace/;

        $str = "<a name=\"$number\"></a>" .
               "<span class=\"docrefcomment\">" .
               "&nbsp;"x5 .
               "</span>" .
               "<!-- LineNumber " . sprintf("%5d", $number) . " -->" .
               "<span class=\"LINENUMBER\">$str</span><br>\n";
        push(@html, $str);
    }
    return @html;
}

1;
