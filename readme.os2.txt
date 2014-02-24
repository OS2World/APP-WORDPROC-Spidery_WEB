This is the OS/2 2.0 port of Norman Ramsey's Spider WEB.  

Briefly, WEB is a system that allows the creation of computer source
code and typeset documentation from a single source file.  The file is
processed by tangle for input to the target compiler and the same
source is processed be weave for input to TeX for typeset
documentation.

This port includes the entire source for Ramsey's system that allows
the creation of custom tangle and weave processors for arbitrary
computer languages.  Included in the main directory of this port is a
set of OS/2 specific files:

README.OS2    -- This file
ceeweave.exe  -- C Weave executable
ceetangle.exe -- C Tangle executable
awkweave.exe  -- AWK Weave executable
awktangle.exe -- AWK Tangle executable
cweb.tex      -- include file for Woven C tex files
awkweb.tex    -- include file for Woven AWK tex files
makefile.emx  -- make for C and AWK executatables and dvi
                 documentation
common.ch     -- change file for common.web
weave.ch      -- change file for weave.web
emxlibc.dll   -- emx C dynamic link library

The only change I have made to the original files is to rename
common.c to common.c.old in order to force the makefile to create a
new common.c from the combination of common.web and common.ch.

INSTALLATION:

Copy the executables above to a directoru on your PATH.
Copy cweb.tex, awkweb.tex, and webkernel.tex to the directory that TeX
normally looks for inputs.
Copy the emxlibc.dll file to a directory on your LIBPATH.

From this point, you should be able to run the appropriate version of
tangle and weave from any location.

That it.

NOTES:

1.  I have assumed the files here are on an HPFS directory.  This means
that the capability for long filenames is assumed.

2.  The TeX include file webkernel.tex appears to be too long for
tex386, but internally tex386 processes the \input command properly
and will find webkernel.tex properly if it is in the current directory
or the proper TEXINPUT directory.  However, tex386 will not recognize
a file on the command line linger tahn the 8.3 format.

MAKING IT YOURSELF:

The makefile "makefile.emx" will create the executables and dvi files
of the sources and documentation.  The primary commands are:

    make -f makefile.emx exe    (default - makes executables)
    make -f makefile.emx docs   (makes dvi files of documentation)
    make -f makefile.emx dvi    (makes dvi files from Spider sources)
    make -f makefile.emx all    (all of the above)
    make -f makefile.emx clean  (removes all non-essential files)

It takes about 13 minutes to to a `make all' on my 386/33 + 387 + 16Mb RAM.

The makefile assumes a lot about utilities that are available.  I used
the emx 0.8f gcc compiler, gawk, sort, rm, cat, and sort.  It also
uses tex386 from the emTeX package using both plain and LaTeX styles.
All of these are available from ftp-os2.nms.edu.

If you want to develop one of the other Spider WEB languages, take a
look at the makefile closely.  You may even want to develop a Spider
Web for a new language.

  -- Bruce Dubbs
     bdubbs@neuron.tamu.edu or
     bdubsb@hal.kelly.af.mil  (after August 1993)

REFERENCES:
[1] Wayne Sewell, Weaving a Program: Literate Programming in WEB.
Van Nostrand Reinhold, New York, 1988

[2] Donald Knuth, Literate Programming.  Center for the Study of
Language and Information, Leland Stanford Junior University, CA, 1992.
