# Copyright 2009 University Corporation for Atmospheric Research
#
# This file is part of the LDM package.  See the file COPYRIGHT
# in the top-level source-directory of the package for copying and
# redistribution conditions.
#
## Process this file with automake to produce Makefile.in

PQ_SUBDIR	= @PQ_SUBDIR@

bin_PROGRAMS	= pqcheck
CPPFLAGS	= \
    -I$(top_srcdir)/ulog \
    -I$(top_srcdir)/protocol \
    -I$(top_srcdir)/pq \
    -I$(top_srcdir)/misc \
    -I$(top_srcdir)
pqcheck_LDADD	= $(top_builddir)/lib/libldm.la
dist_man1_MANS	= pqcheck.1
TAGS_FILES	= \
    ../$(PQ_SUBDIR)/*.c ../$(PQ_SUBDIR)/*.h \
    ../protocol/*.c ../protocol/*.h \
    ../ulog/*.c ../ulog/*.h \
    ../misc/*.c ../misc/*.h \
    ../rpc/*.c ../rpc/*.h

if MAINTAINER
pqcheck.1:	pqcheck.1.in
	$(top_srcdir)/registry/substPaths <$< >$@.tmp
	mv $@.tmp $@
endif

valgrind:	pqcheck
	$(TESTS_ENVIRONMENT) $(LIBTOOL) --mode=execute valgrind \
	    --leak-check=full --show-reachable=yes ./pqcheck
