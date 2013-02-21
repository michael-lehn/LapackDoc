package Config;
use strict;
use File::Spec;

BEGIN {

our $f77crash     = File::Spec->catfile($ENV{LAPACKDOC}, "f77crash", "f77crash");
our $templateDir  = File::Spec->catdir($ENV{LAPACKDOC}, "templates");
our $tmpDir       = File::Spec->tmpdir();
our $htmlDir      = File::Spec->catdir($ENV{HOME}, "Sites", "Fortran");
our $graphsSubdir = File::Spec->catdir("graphs");
our $graphsDir    = File::Spec->catdir($htmlDir, "graphs");

our $css         = File::Spec->catfile("default.css");
our $tooltip     = File::Spec->catfile("wz_tooltip.js");

}

1;
