# Copyright 1989 by Norman Ramsey, Odyssey Research Associates
# To be used for research purposes only
# For more information, see file COPYRIGHT in the parent directory

OBJECTDIRS=sun3 vax

clean:
	-rm -f *.tex *.dvi *.log *.wlog *~ *.toc
	@-for i in $(OBJECTDIRS); do \
		rm -f $$i/*.o; \
	done
	-rm -f *.o

superclean:
	-rm -f sun3/*.o vax/*.o *.o
	-rm -f *.c
	-rm -f *.tex *.dvi *.log *~ *.toc

