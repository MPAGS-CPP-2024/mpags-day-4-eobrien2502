# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/mpags-day-4-eobrien2502/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/mpags-day-4-eobrien2502

# Utility rule file for doc.

# Include any custom commands dependencies for this target.
include Documentation/CMakeFiles/doc.dir/compiler_depend.make

# Include the progress variables for this target.
include Documentation/CMakeFiles/doc.dir/progress.make

Documentation/CMakeFiles/doc: Documentation/html/index.html

Documentation/html/index.html: /workspaces/mpags-day-4-eobrien2502/src/Documentation/Doxyfile.in
Documentation/html/index.html: MPAGSCipher/libMPAGSCipher.a
Documentation/html/index.html: /workspaces/mpags-day-4-eobrien2502/src/README.md
Documentation/html/index.html: /workspaces/mpags-day-4-eobrien2502/src/CMakeLists.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/workspaces/mpags-day-4-eobrien2502/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Doxygenating MPAGSCipher"
	cd /workspaces/mpags-day-4-eobrien2502/Documentation && /usr/bin/doxygen

doc: Documentation/CMakeFiles/doc
doc: Documentation/html/index.html
doc: Documentation/CMakeFiles/doc.dir/build.make
.PHONY : doc

# Rule to build all files generated by this target.
Documentation/CMakeFiles/doc.dir/build: doc
.PHONY : Documentation/CMakeFiles/doc.dir/build

Documentation/CMakeFiles/doc.dir/clean:
	cd /workspaces/mpags-day-4-eobrien2502/Documentation && $(CMAKE_COMMAND) -P CMakeFiles/doc.dir/cmake_clean.cmake
.PHONY : Documentation/CMakeFiles/doc.dir/clean

Documentation/CMakeFiles/doc.dir/depend:
	cd /workspaces/mpags-day-4-eobrien2502 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/mpags-day-4-eobrien2502/src /workspaces/mpags-day-4-eobrien2502/src/Documentation /workspaces/mpags-day-4-eobrien2502 /workspaces/mpags-day-4-eobrien2502/Documentation /workspaces/mpags-day-4-eobrien2502/Documentation/CMakeFiles/doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Documentation/CMakeFiles/doc.dir/depend

