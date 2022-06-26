ADD_EXECUTABLE(
  run-tests

  point-suite.cpp
  rectangle-suite.cpp
)

TARGET_LINK_LIBRARIES(
  run-tests

  PUBLIC

  shapes
  gtest_main
)

