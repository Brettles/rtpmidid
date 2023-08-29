/**
 * Real Time Protocol Music Instrument Digital Interface Daemon
 * Copyright (C) 2019-2023 David Moreno Montero <dmoreno@coralbits.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "midipeer.hpp"
#include "rtpmidid/signal.hpp"

namespace rtpmidid {
class rtppeer_t;
class io_bytes_reader;
} // namespace rtpmidid

namespace rtpmididns {

class rtppeer_t : public midipeer_t {
public:
  std::shared_ptr<rtpmidid::rtppeer_t> peer;
  connection_t<const rtpmidid::io_bytes_reader &> midi_connection;
  int packets_sent = 0;
  int packets_recv = 0;

  rtppeer_t(std::shared_ptr<rtpmidid::rtppeer_t> peer);
  ~rtppeer_t();

  void send_midi(midipeer_id_t from, const mididata_t &) override;
  json_t status() override;
};
} // namespace rtpmididns
