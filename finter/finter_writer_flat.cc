/*!
  \file finter_writer_flat.cc
  \brief method implementation for finter uncompressed file writing
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#include "finter/finter_writer_flat.h"

void finter::finter_writer_flat::open(const char *filename) {
  _output.open(filename);
  if (!_output.is_open())
    throw std::domain_error(
        "finter::finter_writer_flat::open: cannot "
        "write file \"" +
        std::string(filename) + "\"");
}

void finter::finter_writer_flat::writeline(
    const std::string &line) {
  _output << line << get_newline();
}

void finter::finter_writer_flat::write(char *buf,
                                                   std::streamsize n) {
  _output.write(buf, n);
}
