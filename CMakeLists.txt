cmake_minimum_required(VERSION 2.8.3)
project(fast_nav_data_type)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  message_runtime
  roscpp
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
  CATKIN_DEPENDS message_generation roscpp message_runtime
  #DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
	include
	src
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(Point2DContinious src/Point2DContinious.cpp )
target_link_libraries(Point2DContinious ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Point2DDiscrete src/Point2DDiscrete.cpp )
target_link_libraries(Point2DDiscrete ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Point2DPolar src/Point2DPolar.cpp )
target_link_libraries(Point2DPolar ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Point2D src/Point2D.cpp )
target_link_libraries(Point2D Point2DDiscrete Point2DContinious Point2DPolar ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Pose2D src/Pose2D.cpp )
target_link_libraries(Pose2D Point2D ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Pose3DDiscrete src/Pose3DDiscrete.cpp )
target_link_libraries(Pose3DDiscrete Pose2D ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Pose3D src/Pose3D.cpp )
target_link_libraries(Pose3D Pose3DDiscrete ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(ControledVariable src/ControledVariable.cpp )
target_link_libraries(ControledVariable ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(VariableAt src/VariableAt.cpp )
target_link_libraries(VariableAt Point2D ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(Grid2D src/Grid2D.cpp )
target_link_libraries(Grid2D VariableAt ${catkin_LIBRARIES} )

## Declare a cpp library
add_library(BoolGrid2D src/BoolGrid2D.cpp )
target_link_libraries(BoolGrid2D Grid2D ${catkin_LIBRARIES} )

## Declare a cpp executable
add_executable(Point_Test src/Point_Test.cpp)
target_link_libraries(Point_Test BoolGrid2D Pose3D ${catkin_LIBRARIES})#Pose2D Point2D Point2DDiscrete Point2DContinious Point2DPolar ${catkin_LIBRARIES} )

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(fast_nav_data_type_node fast_nav_data_type_generate_messages_cpp)



#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS fast_nav_data_type fast_nav_data_type_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_fast_nav_data_type.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
