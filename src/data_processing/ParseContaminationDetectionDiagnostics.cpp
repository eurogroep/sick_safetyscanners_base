// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------

/*!
*  Copyright (C) 2025, Lowpad, Bleskensgraaf, Netherlands*
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.

*/

// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!
 * \file ContaminationDetectionDiagnostics.h
 *
 * \author  Yannick de Hoop <yannick.dehoop@lowpad.com>
 * \date    2025-04-09
 */
//----------------------------------------------------------------------


#include "sick_safetyscanners_base/data_processing/ParseContaminationDetectionDiagnostics.h"

#include "sick_safetyscanners_base/cola2/Command.h"

namespace sick {
namespace data_processing {

bool ParseContaminationDetectionDiagnostics::parseTCPSequence(
  const datastructure::PacketBuffer& buffer,
  sick::datastructure::ContaminationDetectionDiagnostics& contamination_detection_diagnostics) const
{
  // Keep our own copy of the shared_ptr to keep the iterators valid
  const std::shared_ptr<std::vector<uint8_t> const> vec_ptr = buffer.getBuffer();
  std::vector<uint8_t>::const_iterator data_ptr             = vec_ptr->begin();
  contamination_detection_diagnostics.setEProcessingState(readEProcessingState(data_ptr) == 14);

  contamination_detection_diagnostics.clearContaminationStatusMap();
  for (uint8_t i = 0; i < 18; i++)
  {
    const auto status = readStatus(data_ptr + 64 + 36 * i);
    sick::datastructure::ContaminationDetectionDiagnostics::ContaminationStatus::PollutionDetectedLevel pollution_detected_level = sick::datastructure::ContaminationDetectionDiagnostics::ContaminationStatus::PollutionDetectedLevel::OK;
    if (static_cast<bool>(status& (0x01 << 1)))
    {
      pollution_detected_level = sick::datastructure::ContaminationDetectionDiagnostics::ContaminationStatus::PollutionDetectedLevel::ERROR;
    }
    else if (static_cast<bool>(status & (0x01 << 0)))
    {
      pollution_detected_level = sick::datastructure::ContaminationDetectionDiagnostics::ContaminationStatus::PollutionDetectedLevel::WARNING;
    }
    contamination_detection_diagnostics.setContaminationStatus({pollution_detected_level, static_cast<uint8_t>(readLevel(data_ptr + 64 + 36 * i) / 256)}, i);
  }
  return true;
}

uint16_t ParseContaminationDetectionDiagnostics::readEProcessingState(std::vector<uint8_t>::const_iterator data_ptr) const
{
  return read_write_helper::readUint16LittleEndian(data_ptr + 4);
}

uint16_t ParseContaminationDetectionDiagnostics::readStatus(std::vector<uint8_t>::const_iterator data_ptr) const
{
  return read_write_helper::readUint16LittleEndian(data_ptr + 0);
}

int16_t ParseContaminationDetectionDiagnostics::readLevel(std::vector<uint8_t>::const_iterator data_ptr) const
{
  return read_write_helper::readInt16LittleEndian(data_ptr + 2);
}
} // namespace data_processing
} // namespace sick
