# Detect platform
EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
message( STATUS "Architecture:  ${ARCHITECTURE}" )

# Find depend libraries
find_package(PkgConfig)

pkg_check_modules(CAIRO cairo REQUIRED)
include_directories( ${CAIRO_INCLUDE_DIRS}  )
link_directories   ( ${CAIRO_LIBRARY_DIRS}  )

pkg_check_modules(ALSA alsa REQUIRED)
include_directories( ${ALSA_INCLUDE_DIRS}  )
link_directories   ( ${ALSA_LIBRARY_DIRS}  )

pkg_check_modules(JACK jack REQUIRED)
include_directories( ${JACK_INCLUDE_DIRS}  )
link_directories   ( ${JACK_LIBRARY_DIRS}  )

pkg_check_modules(SNDFILE sndfile REQUIRED)
include_directories( ${SNDFILE_INCLUDE_DIRS}  )
link_directories   ( ${SNDFILE_LIBRARY_DIRS}  )

# needed for setting icon in WM
pkg_check_modules(X11 x11 REQUIRED)
include_directories( ${X11_INCLUDE_DIRS}  )
link_directories   ( ${X11_LIBRARY_DIRS}  )

IF(RELEASE_BUILD)
  SET(CMAKE_CXX_FLAGS " -g -Wall -Wno-unused-variable ")
  SET(CMAKE_C_FLAGS " -g -Wall -W -Wno-unused-variable ")
ENDIF(RELEASE_BUILD)

if( ${ARCHITECTURE} STREQUAL "x86_64" )
  set(CMAKE_C_FLAGS   ${CMAKE_C_FLAGS}"-msse2" )
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}"-msse2" )
else()
  # Can set i686 / ARM stuff here
endif()

include_directories( "../ctlra/" )

cmake_policy(SET CMP0015 OLD)
link_directories   ( "../ctlra/" )

#####################################
### Simple
#####################################
FILE(GLOB src_simple simple/*.c )
add_executable (simple ${src_simple} )
add_dependencies(simple ctlra)
target_link_libraries( simple "-lctlra"               )
target_link_libraries( simple ${USB_LIBRARIES}        )

#####################################
### Vegas Mode
#####################################
include_directories( "../ctlra/devices/*" )
FILE(GLOB src_vegas vegas_mode/*.c )
add_executable (vegas_mode ${src_vegas} )
add_dependencies(vegas_mode ctlra)
target_link_libraries( vegas_mode "-lctlra"               )
target_link_libraries( vegas_mode ${USB_LIBRARIES}        )
target_link_libraries( vegas_mode ${JACK_LIBRARIES}       )
target_link_libraries( vegas_mode ${CAIRO_LIBRARIES}      )
target_link_libraries( vegas_mode ${SNDFILE_LIBRARIES}    )

#####################################
### TCC Scripting 
#####################################
FILE(GLOB src_tcc tcc_script/*.c )
add_executable (tcc_script ${src_tcc} )
add_dependencies(tcc_script ctlra)
target_link_libraries( tcc_script "-lctlra"               )
target_link_libraries( tcc_script ${USB_LIBRARIES}        )
target_link_libraries( tcc_script "-ltcc -ldl"            )


#####################################
### Daemon
#####################################
# RtMIDI backends
ADD_DEFINITIONS( "-D__UNIX_JACK__"  )
ADD_DEFINITIONS( "-D__LINUX_ALSA__" )
FILE(GLOB src_daemon daemon/*.cpp )
add_executable (daemon ${src_daemon} )
add_dependencies(daemon ctlra)
target_link_libraries( daemon "-lctlra"               )
target_link_libraries( daemon ${USB_LIBRARIES}        )
target_link_libraries( daemon ${ALSA_LIBRARIES}       )
target_link_libraries( daemon ${JACK_LIBRARIES}       )