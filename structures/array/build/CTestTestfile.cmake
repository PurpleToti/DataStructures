# CMake generated Testfile for 
# Source directory: C:/Users/Arthur/Code/DataStructures/structures/array
# Build directory: C:/Users/Arthur/Code/DataStructures/structures/array/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(array_test_test "C:/Users/Arthur/Code/DataStructures/structures/array/build/Debug/array_test.exe")
  set_tests_properties(array_test_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;23;add_test;C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(array_test_test "C:/Users/Arthur/Code/DataStructures/structures/array/build/Release/array_test.exe")
  set_tests_properties(array_test_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;23;add_test;C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(array_test_test "C:/Users/Arthur/Code/DataStructures/structures/array/build/MinSizeRel/array_test.exe")
  set_tests_properties(array_test_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;23;add_test;C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(array_test_test "C:/Users/Arthur/Code/DataStructures/structures/array/build/RelWithDebInfo/array_test.exe")
  set_tests_properties(array_test_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;23;add_test;C:/Users/Arthur/Code/DataStructures/structures/array/CMakeLists.txt;0;")
else()
  add_test(array_test_test NOT_AVAILABLE)
endif()
