cmake_minimum_required(VERSION 3.5.0)
project(top-100 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(top-100 main.cpp)
add_executable(playground playground/main.cpp)
add_executable(BinarySearchTree 14/BinarySearchTree/main.cpp 14/BinarySearchTree/BinarySearchTree.cpp) 
add_executable(graph 15/graph/main.cpp 15/graph/Graph.cpp)
add_executable(zoom_exercise_23_1 23/zoom-exercise-1.cpp)
add_executable(tic_tac_toe cpp-exam-tic-tac-toe/main.cpp cpp-exam-tic-tac-toe/game-exceptions.cpp cpp-exam-tic-tac-toe/Game.cpp)
add_executable(linked_list 28/zoom-exercise-linked-list.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
