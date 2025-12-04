# CMake generated Testfile for 
# Source directory: /home/mrnob0dy666/purl_diver_PUBLIC
# Build directory: /home/mrnob0dy666/purl_diver_PUBLIC/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(help_output "/home/mrnob0dy666/purl_diver_PUBLIC/build/purl_diver" "--help")
set_tests_properties(help_output PROPERTIES  _BACKTRACE_TRIPLES "/home/mrnob0dy666/purl_diver_PUBLIC/CMakeLists.txt;153;add_test;/home/mrnob0dy666/purl_diver_PUBLIC/CMakeLists.txt;0;")
add_test(shell_test_suite "/usr/bin/bash" "/home/mrnob0dy666/purl_diver_PUBLIC/test_suite.sh")
set_tests_properties(shell_test_suite PROPERTIES  WORKING_DIRECTORY "/home/mrnob0dy666/purl_diver_PUBLIC/build" _BACKTRACE_TRIPLES "/home/mrnob0dy666/purl_diver_PUBLIC/CMakeLists.txt;161;add_test;/home/mrnob0dy666/purl_diver_PUBLIC/CMakeLists.txt;0;")
