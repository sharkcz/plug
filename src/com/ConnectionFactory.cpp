/*
 * PLUG - software to operate Fender Mustang amplifier
 *        Linux replacement for Fender FUSE software
 *
 * Copyright (C) 2017-2019  offa
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "com/ConnectionFactory.h"
#include "com/UsbComm.h"
#include "com/MustangConstants.h"

namespace plug::com
{
    namespace
    {
        inline constexpr std::uint16_t usbVID{0x1ed8};

        namespace usbPID
        {
            inline constexpr std::uint16_t smallAmps{0x0004};   //Mustang I and II
            inline constexpr std::uint16_t bigAmps{0x0005};     //Mustang III, IV and V
            inline constexpr std::uint16_t miniAmps{0x0010};    //Mustang Mini
            inline constexpr std::uint16_t floorAmps{0x0012};   //Mustang Floor
            inline constexpr std::uint16_t smallAmpsV2{0x0014}; //Mustang II (and I?) V2
            inline constexpr std::uint16_t bigAmpsV2{0x0016};   //Mustang III+ V2
        }

        inline constexpr std::initializer_list<std::uint16_t> pids{
            usbPID::smallAmps,
            usbPID::bigAmps,
            usbPID::miniAmps,
            usbPID::floorAmps,
            usbPID::smallAmpsV2,
            usbPID::bigAmpsV2};
    }

    std::shared_ptr<Connection> createUsbConnection()
    {
        auto conn = std::make_shared<UsbComm>();
        conn->openFirst(usbVID, pids);
        return conn;
    }
}
