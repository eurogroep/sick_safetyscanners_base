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

#ifndef SICK_SAFETYSCANNERS_BASE_DATASTRUCTURE_CONTAMINATIONDETECTIONDIAGNOSTICS_H
#define SICK_SAFETYSCANNERS_BASE_DATASTRUCTURE_CONTAMINATIONDETECTIONDIAGNOSTICS_H

#include <cstdint>
#include <map>

namespace sick {
namespace datastructure {

/*!
 * \brief The application io class, bundles application input and output.
 */
class ContaminationDetectionDiagnostics
{
public:
  /*!
   * \brief Constructor of the contamination detection diagnostics
   */
  ContaminationDetectionDiagnostics() = default;

  struct ContaminationStatus
  {
    enum PollutionDetectedLevel : uint8_t
    {
      WARNING = 0,
      ERROR = 1
    };

    ContaminationStatus(const PollutionDetectedLevel& status, uint8_t pollution_percentage);
    ContaminationStatus() = default;
    PollutionDetectedLevel status = WARNING;
    uint8_t pollution_percentage = 0;
  };

  /*!
   * \brief Sets contamination status for a sector
   *
   * \param status Status of the contamination
   * \param sector specifies the sector of the status
   *
   */
  void setContaminationStatus(const ContaminationStatus& status, uint8_t sector);

  /*!
   * \brief Clears the contamination status map
   */
  void clearContaminationStatusMap();

  /*!
   * \brief Sets if application data is empty.
   *
   * \param running whether the contamination measurement is running true, false otherwise
   */
  void setEProcessingState(bool running);
  bool getEProcessingState() const;

  std::map<uint8_t, ContaminationStatus> getContaminationStatusMap() const;
private:
  bool m_e_processing_state_running = false;
  std::map<uint8_t, ContaminationStatus> m_contamination_status_map;
};


} // namespace datastructure
} // namespace sick

#endif // SICK_SAFETYSCANNERS_BASE_DATASTRUCTURE_CONTAMINATIONDETECTIONDIAGNOSTICS_H
