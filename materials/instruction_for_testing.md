#*** How to check with cppcheck ***

# Check pong.cpp, enable all checks:
  cppcheck --enable=all --suppress=missingIncludeSystem pong.cpp

# Check all files in directory, enable all checks:
  cppcheck --enable=all --suppress=missingIncludeSystem src/

