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

#include "sick_safetyscanners_base/cola2/ContaminationDetectionDiagnosticsVariableCommand.h"

#include "sick_safetyscanners_base/cola2/Cola2Session.h"
#include "sick_safetyscanners_base/cola2/Command.h"

namespace sick {
namespace cola2 {

ContaminationDetectionDiagnosticsVariableCommand::ContaminationDetectionDiagnosticsVariableCommand(Cola2Session& session, datastructure::ContaminationDetectionDiagnostics& contamination_detection_diagnostics)
  : VariableCommand(session, 373)
  , m_contamination_detection_diagnostics(contamination_detection_diagnostics)
{
  m_contamination_detection_diagnostics_parser_ptr =
    std::make_shared<sick::data_processing::ParseContaminationDetectionDiagnostics>();
}

bool ContaminationDetectionDiagnosticsVariableCommand::canBeExecutedWithoutSessionID() const
{
  return true;
}

bool ContaminationDetectionDiagnosticsVariableCommand::processReply()
{
  if (!base_class::processReply())
  {
    return false;
  }
  m_contamination_detection_diagnostics_parser_ptr->parseTCPSequence(getDataVector(), m_contamination_detection_diagnostics);
  return true;
}


} // namespace cola2
} // namespace sick
