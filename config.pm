package Config;
use strict;
use Cwd;
use File::Spec;

BEGIN {

our $f77crash     = File::Spec->catfile($ENV{LAPACKDOC}, "f77crash", "f77crash");
our $templateDir  = File::Spec->catdir($ENV{LAPACKDOC}, "templates");
our $htmlDir      = File::Spec->catdir($ENV{HOME}, "Sites", "Fortran");
our $graphsSubdir = File::Spec->catdir("graphs");
our $graphsDir    = File::Spec->catdir($htmlDir, "graphs");

#our $tmpDir      = File::Spec->tmpdir();
our $tmpDir       = File::Spec->catdir(cwd(), "tmp");

our $css          = File::Spec->catfile("default.css");
our $tooltip      = File::Spec->catfile("wz_tooltip.js");

}

1;
