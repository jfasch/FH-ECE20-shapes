 add_library(
   shapes STATIC 

   point.h
   point.cpp

   rectangle.h
   rectangle.cpp

   point3d.h
   point3d.cpp
   
   cuboid.h
   cuboid.cpp
)
target_include_directories(shapes PUBLIC .)
