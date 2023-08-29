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
#include "rtpmidid/rtpserver.hpp"
#include <memory>
#include <string>

namespace rtpmidid {
class aseq;
}

namespace rtpmididns {

class midirouter_t;

class rtpmidinetwork_t : public midipeer_t {
public:
  std::shared_ptr<rtpmidid::aseq> aseq;
  rtpmidid::rtpserver_t server;
  connection_t<const rtpmidid::io_bytes_reader &> midi_connection;
  connection_t<std::shared_ptr<rtpmidid::rtppeer_t>> connected_connection;

  rtpmidinetwork_t(const std::string &name, const std::string &port,
                   std::shared_ptr<rtpmidid::aseq> aseq);
  void send_midi(midipeer_id_t from, const mididata_t &) override;
  json_t status() override;
};
} // namespace rtpmididns
