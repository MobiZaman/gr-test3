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

#ifndef INCLUDED_TEST3_GET_TIME_H
#define INCLUDED_TEST3_GET_TIME_H

#include <test3/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace test3 {

    /*!
     * \brief <+description of block+>
     * \ingroup test3
     *
     */
    class TEST3_API get_time : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<get_time> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of test3::get_time.
       *
       * To avoid accidental use of raw pointers, test3::get_time's
       * constructor is in a private implementation
       * class. test3::get_time::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string arguments, int period);
    };

  } // namespace test3
} // namespace gr

#endif /* INCLUDED_TEST3_GET_TIME_H */

