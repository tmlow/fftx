##
## Copyright (c) 2018-2021, Carnegie Mellon University
## All rights reserved.
##
## See LICENSE file for full information
##

include ( ../ExamplesCommon.cmake )

cmake_minimum_required ( VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION} )

##  ===== For most examples you should not need to modify anything ABOVE this line =====

##  Set the project name.  Preferred name is just the *name* of the example folder 
project ( compare ${_lang_add} ${_lang_base} )

##  Test program name is:  test<project name>.{cpp|cu}

set ( _stem fftx )
set ( _prefixes )
set ( BUILD_PROGS testcompare_device testconstant testimpulse )

##  One .cpp file is coded with device_macros and should build for CUDA & HIP
set ( _desired_suffix cpp )

##  ===== For most examples you should not need to modify anything BELOW this line =====

##  message ( STATUS "${BUILD_PROGS}: Library include dirs = ${_library_includes}" )
##  message ( STATUS "${BUILD_PROGS}: Library names = ${_library_names}" )

foreach ( _prog ${BUILD_PROGS} )
    ##  Build the dependencies and get the include directories / libraries for each program
    if ( ${_codegen} STREQUAL "HIP" )
	set_source_files_properties ( ${_prog}.${_desired_suffix} PROPERTIES LANGUAGE CXX )
    elseif ( ${_codegen} STREQUAL "CUDA" )
	set_source_files_properties ( ${_prog}.${_desired_suffix} PROPERTIES LANGUAGE CUDA )
    endif ()
    manage_deps_codegen ( ${_codegen} ${_stem} "${_prefixes}" )
    add_includes_libs_to_target ( ${_prog} ${_stem} "${_prefixes}" )
endforeach ()
