/* -*- c++ -*- */
/*
 * Copyright 2022 Mubashira Zaman.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "get_time_impl.h"

#include <uhd/utils/thread.hpp>
#include <uhd/utils/safe_main.hpp>
#include <uhd/usrp/multi_usrp.hpp>
#include <boost/program_options.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <complex>


namespace gr {
  namespace test3 {
    get_time::sptr
    get_time::make(std::string arguments, int period)
    {
      return gnuradio::get_initial_sptr
        (new get_time_impl(arguments, period));
    }


    /*
     * The private constructor
     */
    get_time_impl::get_time_impl(std::string arguments, int period)
      : gr::sync_block("get_time",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      args = arguments;
      time_period = period;
    }

    /*
     * Our virtual destructor.
     */
    get_time_impl::~get_time_impl()
    {
    }

    int
    get_time_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      unsigned char *out = (unsigned char *) output_items[0];

      out[0] = 0xF;

      uhd::set_thread_priority_safe();
      // uhd::usrp::multi_usrp::sptr usrp = uhd::usrp::multi_usrp::make(args);
      // Tell runtime system how many output items we produced.
      return 1;
    }

  } /* namespace test3 */
} /* namespace gr */

