# Automake file

ACLOCAL_AMFLAGS = -I m4
# Build rules for libraries.
lib_LTLIBRARIES = libfinter.la
library_includedir = $(includedir)/finter

libfinter_la_SOURCES = finter/finter_reader_bzip2.cc \
  finter/finter_reader_flat.cc \
  finter/finter_writer_bzip2.cc \
  finter/finter_writer_flat.cc \
  finter/finter_reader_gzip.cc \
  finter/finter_writer_gzip.cc

library_include_HEADERS = \
  finter/finter_reader.h \
  finter/finter_reader_parent.h \
  finter/finter_reader_bzip2.h \
  finter/finter_reader_flat.h \
  finter/finter_reader_gzip.h \
  finter/finter_writer.h \
  finter/finter_writer_parent.h \
  finter/finter_writer_bzip2.h \
  finter/finter_writer_flat.h \
  finter/finter_writer_gzip.h \
  finter/helper.h \
  finter/finter.h \
  finter/config.h

libfinter_la_LDFLAGS = -version-info 1:0:0
