/*!
  \file finter_reader_gzip.h
  \brief gzip-specific reader class definitions
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#ifndef FINTER_FINTER_READER_GZIP_H_
#define FINTER_FINTER_READER_GZIP_H_

#include "finter/config.h"
#ifdef FINTER_HAVE_LIBZ
#include "finter/finter_reader_parent.h"

#include <zlib.h>
#include <cstdio>
#include <stdexcept>
#include <string>

#include "finter/helper.h"

namespace finter {
/*!
  \class finter_reader_gzip
  \brief interface for zlib (gzip) file input that doesn't break my brain
 */
class finter_reader_gzip : public finter_reader {
 public:
  /*!
    \brief constructor
   */
  finter_reader_gzip();
  /*!
    \brief destructor

    This cleanly handles memory allocation problems, so it's safe to just delete
    the allocated object in userspace.
   */
  ~finter_reader_gzip() throw() {
    close();
    delete[] _buf;
  }
  /*!
    \brief open a specified file
    @param filename name of file to open
   */
  void open(const char *filename);
  /*!
    \brief close the file
   */
  void close();
  /*!
    \brief clear internal state flags
   */
  void clear();
  /*!
    \brief determine whether a file is currently open
    \return whether a file is currently open
   */
  bool is_open() const;
  /*!
    \brief get a single character from file
    \return the next single character from file
   */
  char get();
  /*!
    \brief read a newline-delimited line from file
    @param s where the read line will be stored
    \return whether the line read operation was successful
   */
  bool getline(std::string *s);
  /*!
    \brief determine whether the stream is at the end of the file
    \return whether the stream is at the end of the file
   */
  bool eof() const { return _eof; }
  /*!
    \brief determine whether the stream is in a valid state
    \return whether the stream is in a valid state
   */
  bool good() const { return _good; }
  /*!
    \brief determine whether the stream is in an invalid state
    \return whether the stream is in an invalid state
   */
  bool bad() const { return _bad; }
  /*!
    \brief read a specified number of characters from file
    @param buf allocated array of characters to which to write result
    @param n number of characters to attempt to read
   */
  void read(char *buf, std::streamsize n);

 private:
  gzFile _gz_input;  //!< zlib library interface for file input
  bool _eof;   //!< internal state flag: whether end of file has been reached
  char *_buf;  //!< internal character buffer for file read operations
  unsigned _buf_max;  //!< size of allocated internal character buffer
};
}  // namespace finter

#endif  // HAVE_LIBZ

#endif  // FINTER_FINTER_READER_GZIP_H_
