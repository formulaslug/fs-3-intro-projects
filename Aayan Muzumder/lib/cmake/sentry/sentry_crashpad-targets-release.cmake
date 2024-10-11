#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sentry_crashpad::compat" for configuration "Release"
set_property(TARGET sentry_crashpad::compat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::compat PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_compat.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::compat )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::compat "${_IMPORT_PREFIX}/lib/crashpad_compat.lib" )

# Import target "sentry_crashpad::minidump" for configuration "Release"
set_property(TARGET sentry_crashpad::minidump APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::minidump PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_minidump.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::minidump )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::minidump "${_IMPORT_PREFIX}/lib/crashpad_minidump.lib" )

# Import target "sentry_crashpad::snapshot" for configuration "Release"
set_property(TARGET sentry_crashpad::snapshot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::snapshot PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_snapshot.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::snapshot )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::snapshot "${_IMPORT_PREFIX}/lib/crashpad_snapshot.lib" )

# Import target "sentry_crashpad::util" for configuration "Release"
set_property(TARGET sentry_crashpad::util APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::util PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "ASM_MASM;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_util.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::util )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::util "${_IMPORT_PREFIX}/lib/crashpad_util.lib" )

# Import target "sentry_crashpad::mini_chromium" for configuration "Release"
set_property(TARGET sentry_crashpad::mini_chromium APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::mini_chromium PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/mini_chromium.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::mini_chromium )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::mini_chromium "${_IMPORT_PREFIX}/lib/mini_chromium.lib" )

# Import target "sentry_crashpad::client" for configuration "Release"
set_property(TARGET sentry_crashpad::client APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::client PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_client.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::client )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::client "${_IMPORT_PREFIX}/lib/crashpad_client.lib" )

# Import target "sentry_crashpad::zlib" for configuration "Release"
set_property(TARGET sentry_crashpad::zlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::zlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_zlib.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::zlib )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::zlib "${_IMPORT_PREFIX}/lib/crashpad_zlib.lib" )

# Import target "sentry_crashpad::getopt" for configuration "Release"
set_property(TARGET sentry_crashpad::getopt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::getopt PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_getopt.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::getopt )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::getopt "${_IMPORT_PREFIX}/lib/crashpad_getopt.lib" )

# Import target "sentry_crashpad::tools" for configuration "Release"
set_property(TARGET sentry_crashpad::tools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::tools PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_tools.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::tools )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::tools "${_IMPORT_PREFIX}/lib/crashpad_tools.lib" )

# Import target "sentry_crashpad::handler" for configuration "Release"
set_property(TARGET sentry_crashpad::handler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::handler PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/crashpad_handler_lib.lib"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::handler )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::handler "${_IMPORT_PREFIX}/lib/crashpad_handler_lib.lib" )

# Import target "sentry_crashpad::crashpad_handler" for configuration "Release"
set_property(TARGET sentry_crashpad::crashpad_handler APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::crashpad_handler PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/crashpad_handler.exe"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::crashpad_handler )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::crashpad_handler "${_IMPORT_PREFIX}/bin/crashpad_handler.exe" )

# Import target "sentry_crashpad::crashpad_wer" for configuration "Release"
set_property(TARGET sentry_crashpad::crashpad_wer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sentry_crashpad::crashpad_wer PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/crashpad_wer.dll"
  )

list(APPEND _cmake_import_check_targets sentry_crashpad::crashpad_wer )
list(APPEND _cmake_import_check_files_for_sentry_crashpad::crashpad_wer "${_IMPORT_PREFIX}/bin/crashpad_wer.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
