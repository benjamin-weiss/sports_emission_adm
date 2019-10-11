cmake_minimum_required(VERSION 3.5)
project(sports_emission VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(submodules/libadm)

add_executable(sports_emission_stage_01 sports_emission_stage_01.cpp)
target_link_libraries(sports_emission_stage_01 PRIVATE adm)
