INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TEST3 test3)

FIND_PATH(
    TEST3_INCLUDE_DIRS
    NAMES test3/api.h
    HINTS $ENV{TEST3_DIR}/include
        ${PC_TEST3_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TEST3_LIBRARIES
    NAMES gnuradio-test3
    HINTS $ENV{TEST3_DIR}/lib
        ${PC_TEST3_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/test3Target.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TEST3 DEFAULT_MSG TEST3_LIBRARIES TEST3_INCLUDE_DIRS)
MARK_AS_ADVANCED(TEST3_LIBRARIES TEST3_INCLUDE_DIRS)
