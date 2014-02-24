This file says how to install Spidery WEB.  If you want more information 
about what it is, look in the doc subdirectory, especially doc/DESCRIPTION.
Spidery WEB is not in the public domain; you are welcome to use it for
free for research purposes only.  For more details, see the file COPYRIGHT.


How to install Spidery WEB:

1) Pick a directory to install the WEB source in. Call it WEBROOT.

2) untar the distribution in WEBROOT (cd WEBROOT; tar xvf spiderweb.tar)

3) change to the master subdirectory and edit WebMakefile.
	-- Set WEBROOT to the WEBROOT directory
	-- Set DEST to the name of a directory to hold the executables
	-- Set MACROS to the name of directory to hold TeX macros
   Example:
	WEBROOT=/usr/src/local/spiderweb
	DEST=/usr/local
	MACROS=/usr/lib/tex/macros

   Make sure there are no spaces following the names.

4) If your installation doesn't have a cputype program, make one (a shell
   script is fine) following the instructions in WebMakefile.  Put it
   somewhere on your path.

5) As defaults, the names of C tangle and weave are ceetangle and ceeweave
   (to avoid confusion with Silvio Levy's ctangle and cweave).  Awk tangle
   is called awktangle.  If you want to change these names, you must change
   them in WEBROOT/master/WebMakefile, and also on WEBROOT/c/make and
   WEBROOT/awk/make

6) Make sure . is at the front of your path.  For example, csh users could
   type `set path = (. $path)' or sh users type `path=.:$path'.  (I haven't
   checked these since . is at the front of my path by default.)  If you
   don't like this security hole, you will have to change `make' to `./make'
   at the appropriate places (found by you).

   With your path set, go into WEBROOT and type `make boot'

   Once this is successful you will have executable versions of tangle for
   C and Awk, which is the minumum needed to make other things.  After you've
   done this, you can afford to `make clean', which will remove the .c and
   .awk source you used to bootstrap yourself.  You can always make them over
   again using the executable versions (`make source').

   In case it isn't clear, once you `make boot' you will never need to do
   it again.

7) Move webkernel.tex into a place where TeX can find it.  Until you do
   this you won't be able to TeX WEAVE output (or doc/spiderwebman.tex).



Spidery WEB comes with the following languages:

Directory	Description

ada		Ada
awk		AWK, a string processing language
c		Kernighan and Ritchie C
c++		C++, courtesy of Ed Kademan
dijkstra	Edsger Dijkstra's language of guarded commands  (flaky)
larch		The Larch Shared Language, used for specifying
		equational theories.
penelope	Ada, extended with formal comments for verification
ssl		The language of the Cornell Synthesizer Generator


Each of these directories has a file called 'make'.  The settings in that file
determine the name that the executable versions of WEAVE and TANGLE have
for that particular language.  The names of the Spider files are also given.
See doc/spiderman.tex for details on using Spider.

To make weave or tangle, change to the directory for the chosen language, 
and type `make weave' or `make tangle'.  `make web' will make both weave
and tangle.


Spidery WEB is available by anonymous ftp from princeton.edu:~ftp/pub.
By copying it and using it you agree to report bugs, bug fixes, and
changes to me, at the address below.

Spidery WEB is no longer in beta test.  I still respond to bug
reports, but very slowly.  When sending bug reports, please include
the last line from your copy of the file BUGS.

Norman Ramsey
Department of Computer Science
Princeton University
35 Olden Street
Princeton, New Jersey 08544
Internet: nr@princeton.edu
Telephone: (609)-258-55388
