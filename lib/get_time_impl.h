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

#ifndef INCLUDED_TEST3_GET_TIME_IMPL_H
#define INCLUDED_TEST3_GET_TIME_IMPL_H
#include <string>

#include <test3/get_time.h>

namespace gr {
  namespace test3 {

    class get_time_impl : public get_time
    {
     private:
      std::string args;
      int time_period;

     public:
      get_time_impl(std::string arguments, int period);
      ~get_time_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace test3
} // namespace gr

#endif /* INCLUDED_TEST3_GET_TIME_IMPL_H */

