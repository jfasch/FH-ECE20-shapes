ADD_EXECUTABLE(
  run-tests

  point-suite.cpp
  rectangle-suite.cpp

  point3d-suite.cpp
  cuboid-suite.cpp
)

TARGET_LINK_LIBRARIES(
  run-tests

  PUBLIC

  shapes
  gtest_main
)

