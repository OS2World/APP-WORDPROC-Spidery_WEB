# Copyright 1989 by Norman Ramsey, Odyssey Research Associates
# To be used for research purposes only
# For more information, see file COPYRIGHT in the parent directory

# This is a SUN OS 4 Makefile.  Sorry.  Makefiles in subdirectories
# should work under any reasonable Make.

MAKE=make $(MFLAGS)
DIRECTORIES=ada awk c c++ dijkstra larch penelope ssl doc master

# Removes excess junk from the world, except it doesn't remove
# common object files from ./master
# This destroys the sources, so don't make clean until you've made boot.
clean:
	@for i in $(DIRECTORIES); do \
		cd $$i; \
		echo making $$i clean...; \
		$(MAKE) clean ; \
		cd ..; \
	done
	rm -f *~
	@echo "All done."

# This creates the minimum sources in preparation for `make distribution'
source:
	cd c ; $(MAKE) source ; cd ..
	cd awk ; $(MAKE) source ; cd ..

# Put everything into a tar file.  Must `make source' first, and should clean
distribution:
#	$(MAKE) clean
#	$(MAKE) source
	tar cvhf spiderweb.tar README COPYRIGHT BUGS webkernel.tex \
                 Makefile $(DIRECTORIES)

# Used to bring up the system when first installing it.  Requires sources,
# either from the distribution tarfile or from `make source'
boot:
	cd c; $(MAKE) boot; cd ..
	cd awk; $(MAKE) boot; cd ..

# Make all known webs.  For lunatics only.
all:
	@for i in $(DIRECTORIES); do \
		cd $$i; \
		$(MAKE) web ; \
		cd ..; \
	done
	@echo "All done."
	
