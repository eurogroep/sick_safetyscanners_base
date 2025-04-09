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

#include "sick_safetyscanners_base/datastructure/ContaminationDetectionDiagnostics.h"

namespace sick {
namespace datastructure {

ContaminationDetectionDiagnostics::ContaminationStatus::ContaminationStatus(const PollutionDetectedLevel& status,
                                                                            uint8_t pollution_percentage)

  : status(status), pollution_percentage(pollution_percentage)
{
}

void ContaminationDetectionDiagnostics::setContaminationStatus(const ContaminationStatus& status, uint8_t sector)
{
  m_contamination_status_map[sector] = status;
}

void ContaminationDetectionDiagnostics::clearContaminationStatusMap()
{
  m_contamination_status_map.clear();
}

void ContaminationDetectionDiagnostics::setEProcessingState(bool running)
{
  m_e_processing_state_running = running;
}

std::map<uint8_t, ContaminationDetectionDiagnostics::ContaminationStatus> ContaminationDetectionDiagnostics::
getContaminationStatusMap() const
{
  return m_contamination_status_map;
}

bool ContaminationDetectionDiagnostics::getEProcessingState() const
{
  return m_e_processing_state_running;
}

} // namespace datastructure
} // namespace sick
