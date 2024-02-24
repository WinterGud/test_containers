cmake_minimum_required(VERSION 3.6)

# Set the project name
project (Main)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
	main.cpp
	Test.hpp
	Test.cpp
	CheckDeque.h
	CheckDeque.cpp
	CheckList.h
	CheckList.cpp
	CheckVector.h
	CheckVector.cpp
	CheckUnorderedSet.h
	CheckUnorderedSet.cpp
	CheckSet.h
	CheckSet.cpp
)

add_executable(Main ${SOURCES})