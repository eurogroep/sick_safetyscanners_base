^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package sick_safetyscanners_base
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.0.0 (2023-09-19)
------------------
* fix(parse-config-metadata): read checksums
* fix: fix clang warnings.
* fix: fix clang warnings.
* Merge branch 'DasRoteSkelett-fix/missingInclude' into cpp_standalone
* UDPPacketMerger: fixing missing include
  While std::map is used, it is not included in this header. This leads to
  this error with gcc 11.2:
  | In file included from /yocto/sf-build/BUILD-ros2-humble-honister/work/core2-64-oe-linux/sick-safetyscanners-base/1.0.2-1-r0/git/src/data_processing/UDPPacketMerger.cpp:35:
  | /yocto/sf-build/BUILD-ros2-humble-honister/work/core2-64-oe-linux/sick-safetyscanners-base/1.0.2-1-r0/git/include/sick_safetyscanners_base/data_processing/UDPPacketMerger.h:87:8: error: 'map' in namespace 'std' does not name a template type
  |    87 |   std::map<uint32_t, sick::datastructure::ParsedPacketBuffer::ParsedPacketBufferVector>
  |       |        ^~~
  | /yocto/sf-build/BUILD-ros2-humble-honister/work/core2-64-oe-linux/sick-safetyscanners-base/1.0.2-1-r0/git/include/sick_safetyscanners_base/data_processing/UDPPacketMerger.h:42:1: note: 'std::map' is defined in header '<map>'; did you forget to '#include <map>'?
  |    41 | #include "sick_safetyscanners_base/data_processing/ParseDatagramHeader.h"
  |   +++ |+#include <map>
  |    42 |
* Merging fix for missing using statement
* Added missing 'using' statement to UDPClient.cpp
* Merge branch 'Kooiman-kooiman-fix-memory-leak' into cpp_standalone
* Fix memory leak in createAndExecuteCommand
* added multicast possibily to readme
* constructor for multicast adresses
* overloaded udpclient for multicast adresses
* updated examples in readme
* changed to constant values for the field data
* changed the write command method so used signed int isntead of unsigend int
* fixed parsing error of current measurement config data
* include check if number beams is higher then expected
* included check if expected size matches actual size of parsed data
* fixed bug with wrong angle configuration
  missing multiplication required from cola2 procoll included
* formatting
* adjusted readme for fix for boost 1.70+
* Merge PR`#3 <https://github.com/eurogroep/sick_safetyscanners_base/issues/3>`_
* fix compilation with boost 1.7
* adjusted readme for boost version
  There are breaking changes in ASIO with boost 1.70.
* fixing correct offset in field geometries
* Fixed error in reading chars for device name and project name
* clang format
* Merge branch 'feature_sync_async_api' into cpp_standalone
* Removed COLA2 open/close DEBUG/INFO logs
* Each command execution will now open/close a cola2 session to work reliably in synchronous mode. Replaced LOG_ERROR with exceptions
* Merge branch 'feature_sync_async_api' into cpp_standalone
* Fixed TCP end of file error when  sending multiple commands sequentially.
* added high resolution pictures
* fixed typo in readme
* Merge branch 'feature_sync_async_api' into cpp_standalone
* Sensor settings are now transmitted on constructor call of the driver classes
* Added AsyncSickSafetyScanner to README
* Added SyncSafetyScanner section to README
* clang format
* Removed virtual destructor
* Added LOG-macro guards
* Cleaned up imports
* Removed imports of deleted files
* Applied Clang-Format (FZI-style)
* Removed AsyncTCPClient
* Compilation warnings will now result in build errors
* Cleanup and changed import style for sick_Safetyscanners_base/ headers
* Added doxygen documentation for modified/new classes
* Added Licence headers and cleanup of code
* Cleanup
* Added async asio deadline checks
* API cleanup
* Added async receive of streaming data in the new udp client
* Changed import-style to relative for sick imports
* Added constructor to Async scanner class
* Fixed minor bugs
* Removed unused dummy implementations, added pure synchronous command execution in Cola2
* Refactored Cola2Session
* Renamed Command->CommandMsg
* Added generic TCP-Client which supports sync/async communication
* Changed SafetyScannersBase constructors. Copying & deletion & assignment is now prohibited. An instance of boost::asio::io_service can now be passed to a constructor overload
* Renamed generics,types and moved them into the common sick namespace (this might be temporarily only). Added make_unique since c++11 is lacking this function.
* Renamed Command -> CommandMsg for less confusion with the Command-Pattern
* Temporary refactoring
* Moved ip and port information from CommSettings to SickSafetyScannerBase
* Added new CommSettings struct, added constants header and types header with generics (strongly typed flags and callbacks
* Moved asynchronous streaming API into child-class of the SickSafetyscannersbase and removed corresponding member variables and constructor variables from the base class
* Added log.h includes
* Ported ROS_WARN to LOG_WARN and added USE_ROS_LOGGING option to cmakelist
* Merge branch 'feature_generic_logging' into feature_sync_async_api
* Changed ROS\_<LEVEL> logging calls to LOG\_<LEVEL>
* Added some basic custom exceptions within the sick namespace
* updated readme with safetyscanners
* Added Api for Latest telegram to the readme
* Support for up to 4 channels for the latest telegram command
  The MicroScan3 currently allows only channel 0, but for future compatibility.
  Up to four channels are supported as specified in the cola2 protokol.
  For ease of use, channel 0 is set as default channel when no index is given.
* Added Latest Telegram Command
* clang format
* changed data type of for distance in scan point
  change from int16_t to uint16_t to be conform with the
  datasheet. This supports the long range devices.
* fixed reference to ros repo as example
* readme adjustments
* clang format
* adjusted readme to new name
* fixed renaming typo
* refactored package name and includes
* refactored header guards
* renamed files in repo to with suffix base
* clang format
* updated readme with api of library
* adjusted to function naming convention
* added default values to constructor of comm settings
* rewrote readme for cpp standalone
* readded explicit c11 for xenial builds
* Deleted Ros specific files
* Updated minimum cmake version number to 2.8.12
  Checked build against cmake version 2.8.12, removed the Languages option
  in project line. This is only included in later versions.
  The CMakeLists was checked against 2.8.12, 3.0.2 and 3.10.2.
  This should yield sufficent support for older cmake versions
* Removing unnecessary snippets from the CMakeLists
* moved compile options and definitions in target compile def/opt
* updated cmake to install with correct paths so that the lib can be included
* renamed package and reference to original again
* adjusted package xml to cmake as build tool
* changed ci to fla pipeline
* added config cmake
* logging not dependant on ros, set flag in cmake
* first standalone cxx cmake file
* reworked enum for interface type
* added field set variable command and parsing
* updated parsing of field header data
* added missing field data functions for datastruct
* added version to field data
* style formatting
* added find sensor method command
* updated current config variable command and parsing
* updated Persistent Config Data Parsing
* added required user action command and parsing
* added Device Status Variable Command and Parsing
* moved enums in class
  Enums are not in the class scope where they are used.
  Prevents redefinitions and pollution of namespace.
* added Status Overview Command and Parsing
* added config metadata command and parsing
* correctet variable index for username command
* added command and parsing for username
* formatting
* updated device name used in service callback to new structure
* updated parsing of application name to include  version variables
* added project name command and parsing
* refactored device name command to be consistent with the other commands
* OrderNumber command and parsing added
* typecode read and parsed from variable
* fixed static casts and removed unused variable
* formatting
* added static casts and more pass by references
* used static casts instead of implicit conversion
* Further refactoring
  passing const refs, and pass by value for booleans
* renamed namespace to namespace convention
* more renaming for naming conventions
* Code formatting
* refactoring of functions to match conventions
* added firmware and serialnumber commands and parsing
* added application name command and parsing
* added cpp for config data
* added missing header and cpp to CMake and made them buildable
* clang format
* added implementations for the sopas data
* updated header classes for sopas
* created header for all sopas variables
  Header to store the parsed variables from the sensor
* Contributors: Andrew Kooiman, Denis Taniguchi, Fay Zheng, Lennart Puck, Matthias Schoepfer, Rein Appeldoorn, crown-bdee, schulze, 张天宇

1.0.3 (2019-07-15)
------------------
* erasing completed frames from map. 
* Fixed error on startup that no scan was visualised
  The fix should prevent the node from starting without
  publishing any data. The error appears to be related to
  minor rounding errors, thus setting the resolution smaller then
  the lowest resolution. But not equal start and end angles.
  This should fix issue #11 and #12
* added initialisation of use_pers_config
* Merge Pull Request #9
  Removing the possibilities to use the angles from the sensor it self.
  Since dynamic reconfigure can only be set up for one frame.
* removed tcp port from configuration since it can not be configured in the sensor
* added parameter to use persistent config
* Added methods to request persistent data from sensor
* added all parameters to launch file
* updated persistent and current config command and parser to use config data instead of field data
* removed unused end angle from field data
* added datastructure for configs
* Fix issue with m_angle_offset.  Remove use_sick_angles
* Use C++ STL to reduce risk of memory corruption
* Change ReadWriteHelper to namespace functions instead of a stateless class
* Contributors: Chad Rockey, Jonathan Meyer, Lennart Puck, NicolasLoeffler

1.0.2 (2019-01-15)
------------------
* Read the start angle of the field data from the persistent config instead of the current config
* Changed to 0 angle being at the front of the scan
* Allow system to choose the host udp port from the ephemeral range.  Resolve typo -> IPAdress to IPAddress
* Changed default frame_id name to scan
* Change publish_frequency parameter to be skip parameter. 
* Add time_offset parameter to adjust scan system timestamps
* Added median reflector bit in message and code
* Added active case number to the service call
* Field data is returned as a vector for all fields
* Added publisher und service server for field data and output paths
* Added Start angle and beam resolution to field data

1.0.1 (2018-10-31)
------------------

* Initial Release
