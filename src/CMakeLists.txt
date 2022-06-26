 add_library(
   shapes STATIC 

   point.h
   point.cpp

   rectangle.h
   rectangle.cpp
)
target_include_directories(shapes PUBLIC .)
