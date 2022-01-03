/* -*- c++ -*- */

#define TEST3_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "test3_swig_doc.i"

%{
#include "test3/get_time.h"
%}

%include "test3/get_time.h"
GR_SWIG_BLOCK_MAGIC2(test3, get_time);
