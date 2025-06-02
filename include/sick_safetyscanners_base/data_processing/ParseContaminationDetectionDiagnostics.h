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

#ifndef SICK_SAFETYSCANNERS_BASE_DATA_PROCESSING_PARSECONTAMINATIONDETECTIONDIAGNOSTICS_H
#define SICK_SAFETYSCANNERS_BASE_DATA_PROCESSING_PARSECONTAMINATIONDETECTIONDIAGNOSTICS_H

#include <cstdint>
#include "sick_safetyscanners_base/datastructure/ContaminationDetectionDiagnostics.h"
#include "sick_safetyscanners_base/datastructure/Data.h"
#include "sick_safetyscanners_base/datastructure/PacketBuffer.h"

#include "sick_safetyscanners_base/data_processing/ReadWriteHelper.hpp"

namespace sick {

namespace data_processing {


/*!
 * \brief Parser to read the contamination detection diagnostics of a tcp sequence.
 */
class ParseContaminationDetectionDiagnostics
{
public:
  /*!
   * \brief Constructor of the parser.
   */
  ParseContaminationDetectionDiagnostics() = default;

  /*!
   * \brief Parses a tcp sequence to read the contamination detection diagnostics of the sensor.
   *
   * \param buffer The incoming tcp sequence.
   * \param contamination_detection_diagnostics Reference to the contamination detection diagnostics, which will be
   * written while parsing.
   *
   * \returns If parsing was successful.
   */
  bool parseTCPSequence(const datastructure::PacketBuffer& buffer,
                        datastructure::ContaminationDetectionDiagnostics& contamination_detection_diagnostics) const;

private:
  uint16_t readStatus(std::vector<uint8_t>::const_iterator data_ptr) const;
  int16_t readLevel(std::vector<uint8_t>::const_iterator data_ptr) const;
  uint16_t readEProcessingState(std::vector<uint8_t>::const_iterator data_ptr) const;
  uint16_t readSectorContaminationDetectionDiagnostics(std::vector<uint8_t>::const_iterator data_ptr) const;
};

} // namespace data_processing
} // namespace sick

#endif // SICK_SAFETYSCANNERS_BASE_DATA_PROCESSING_PARSECONTAMINATIONDETECTIONDIAGNOSTICS_H
