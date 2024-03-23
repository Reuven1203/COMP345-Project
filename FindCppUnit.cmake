# Attempt to find CppUnit
# This module sets the following variables:
# CPPUNIT_FOUND - True if CppUnit headers and libraries were found
# CPPUNIT_INCLUDE_DIRS - CppUnit include directories
# CPPUNIT_LIBRARIES - CppUnit libraries to link against

find_path(CPPUNIT_INCLUDE_DIR NAMES cppunit/TestRunner.h)
find_library(CPPUNIT_LIBRARY NAMES cppunit cppunitd)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CppUnit DEFAULT_MSG CPPUNIT_LIBRARY CPPUNIT_INCLUDE_DIR)

if(CPPUNIT_FOUND)
    set(CPPUNIT_INCLUDE_DIRS ${CPPUNIT_INCLUDE_DIR})
    set(CPPUNIT_LIBRARIES ${CPPUNIT_LIBRARY})
endif()

mark_as_advanced(CPPUNIT_INCLUDE_DIR CPPUNIT_LIBRARY)
