# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nowcoder/Tao

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nowcoder/Tao/build

# Include any dependencies generated for this target.
include CMakeFiles/tao.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tao.dir/flags.make

CMakeFiles/tao.dir/tao/log.cpp.o: CMakeFiles/tao.dir/flags.make
CMakeFiles/tao.dir/tao/log.cpp.o: ../tao/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tao.dir/tao/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tao.dir/tao/log.cpp.o -c /home/nowcoder/Tao/tao/log.cpp

CMakeFiles/tao.dir/tao/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tao.dir/tao/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nowcoder/Tao/tao/log.cpp > CMakeFiles/tao.dir/tao/log.cpp.i

CMakeFiles/tao.dir/tao/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tao.dir/tao/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nowcoder/Tao/tao/log.cpp -o CMakeFiles/tao.dir/tao/log.cpp.s

CMakeFiles/tao.dir/tao/log.cpp.o.requires:

.PHONY : CMakeFiles/tao.dir/tao/log.cpp.o.requires

CMakeFiles/tao.dir/tao/log.cpp.o.provides: CMakeFiles/tao.dir/tao/log.cpp.o.requires
	$(MAKE) -f CMakeFiles/tao.dir/build.make CMakeFiles/tao.dir/tao/log.cpp.o.provides.build
.PHONY : CMakeFiles/tao.dir/tao/log.cpp.o.provides

CMakeFiles/tao.dir/tao/log.cpp.o.provides.build: CMakeFiles/tao.dir/tao/log.cpp.o


CMakeFiles/tao.dir/tao/fiber.cpp.o: CMakeFiles/tao.dir/flags.make
CMakeFiles/tao.dir/tao/fiber.cpp.o: ../tao/fiber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tao.dir/tao/fiber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tao.dir/tao/fiber.cpp.o -c /home/nowcoder/Tao/tao/fiber.cpp

CMakeFiles/tao.dir/tao/fiber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tao.dir/tao/fiber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nowcoder/Tao/tao/fiber.cpp > CMakeFiles/tao.dir/tao/fiber.cpp.i

CMakeFiles/tao.dir/tao/fiber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tao.dir/tao/fiber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nowcoder/Tao/tao/fiber.cpp -o CMakeFiles/tao.dir/tao/fiber.cpp.s

CMakeFiles/tao.dir/tao/fiber.cpp.o.requires:

.PHONY : CMakeFiles/tao.dir/tao/fiber.cpp.o.requires

CMakeFiles/tao.dir/tao/fiber.cpp.o.provides: CMakeFiles/tao.dir/tao/fiber.cpp.o.requires
	$(MAKE) -f CMakeFiles/tao.dir/build.make CMakeFiles/tao.dir/tao/fiber.cpp.o.provides.build
.PHONY : CMakeFiles/tao.dir/tao/fiber.cpp.o.provides

CMakeFiles/tao.dir/tao/fiber.cpp.o.provides.build: CMakeFiles/tao.dir/tao/fiber.cpp.o


CMakeFiles/tao.dir/tao/util.cpp.o: CMakeFiles/tao.dir/flags.make
CMakeFiles/tao.dir/tao/util.cpp.o: ../tao/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tao.dir/tao/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tao.dir/tao/util.cpp.o -c /home/nowcoder/Tao/tao/util.cpp

CMakeFiles/tao.dir/tao/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tao.dir/tao/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nowcoder/Tao/tao/util.cpp > CMakeFiles/tao.dir/tao/util.cpp.i

CMakeFiles/tao.dir/tao/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tao.dir/tao/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nowcoder/Tao/tao/util.cpp -o CMakeFiles/tao.dir/tao/util.cpp.s

CMakeFiles/tao.dir/tao/util.cpp.o.requires:

.PHONY : CMakeFiles/tao.dir/tao/util.cpp.o.requires

CMakeFiles/tao.dir/tao/util.cpp.o.provides: CMakeFiles/tao.dir/tao/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/tao.dir/build.make CMakeFiles/tao.dir/tao/util.cpp.o.provides.build
.PHONY : CMakeFiles/tao.dir/tao/util.cpp.o.provides

CMakeFiles/tao.dir/tao/util.cpp.o.provides.build: CMakeFiles/tao.dir/tao/util.cpp.o


CMakeFiles/tao.dir/tao/config.cpp.o: CMakeFiles/tao.dir/flags.make
CMakeFiles/tao.dir/tao/config.cpp.o: ../tao/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tao.dir/tao/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tao.dir/tao/config.cpp.o -c /home/nowcoder/Tao/tao/config.cpp

CMakeFiles/tao.dir/tao/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tao.dir/tao/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nowcoder/Tao/tao/config.cpp > CMakeFiles/tao.dir/tao/config.cpp.i

CMakeFiles/tao.dir/tao/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tao.dir/tao/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nowcoder/Tao/tao/config.cpp -o CMakeFiles/tao.dir/tao/config.cpp.s

CMakeFiles/tao.dir/tao/config.cpp.o.requires:

.PHONY : CMakeFiles/tao.dir/tao/config.cpp.o.requires

CMakeFiles/tao.dir/tao/config.cpp.o.provides: CMakeFiles/tao.dir/tao/config.cpp.o.requires
	$(MAKE) -f CMakeFiles/tao.dir/build.make CMakeFiles/tao.dir/tao/config.cpp.o.provides.build
.PHONY : CMakeFiles/tao.dir/tao/config.cpp.o.provides

CMakeFiles/tao.dir/tao/config.cpp.o.provides.build: CMakeFiles/tao.dir/tao/config.cpp.o


CMakeFiles/tao.dir/tao/thread.cpp.o: CMakeFiles/tao.dir/flags.make
CMakeFiles/tao.dir/tao/thread.cpp.o: ../tao/thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tao.dir/tao/thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tao.dir/tao/thread.cpp.o -c /home/nowcoder/Tao/tao/thread.cpp

CMakeFiles/tao.dir/tao/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tao.dir/tao/thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nowcoder/Tao/tao/thread.cpp > CMakeFiles/tao.dir/tao/thread.cpp.i

CMakeFiles/tao.dir/tao/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tao.dir/tao/thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nowcoder/Tao/tao/thread.cpp -o CMakeFiles/tao.dir/tao/thread.cpp.s

CMakeFiles/tao.dir/tao/thread.cpp.o.requires:

.PHONY : CMakeFiles/tao.dir/tao/thread.cpp.o.requires

CMakeFiles/tao.dir/tao/thread.cpp.o.provides: CMakeFiles/tao.dir/tao/thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/tao.dir/build.make CMakeFiles/tao.dir/tao/thread.cpp.o.provides.build
.PHONY : CMakeFiles/tao.dir/tao/thread.cpp.o.provides

CMakeFiles/tao.dir/tao/thread.cpp.o.provides.build: CMakeFiles/tao.dir/tao/thread.cpp.o


# Object files for target tao
tao_OBJECTS = \
"CMakeFiles/tao.dir/tao/log.cpp.o" \
"CMakeFiles/tao.dir/tao/fiber.cpp.o" \
"CMakeFiles/tao.dir/tao/util.cpp.o" \
"CMakeFiles/tao.dir/tao/config.cpp.o" \
"CMakeFiles/tao.dir/tao/thread.cpp.o"

# External object files for target tao
tao_EXTERNAL_OBJECTS =

../lib/libtao.so: CMakeFiles/tao.dir/tao/log.cpp.o
../lib/libtao.so: CMakeFiles/tao.dir/tao/fiber.cpp.o
../lib/libtao.so: CMakeFiles/tao.dir/tao/util.cpp.o
../lib/libtao.so: CMakeFiles/tao.dir/tao/config.cpp.o
../lib/libtao.so: CMakeFiles/tao.dir/tao/thread.cpp.o
../lib/libtao.so: CMakeFiles/tao.dir/build.make
../lib/libtao.so: CMakeFiles/tao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nowcoder/Tao/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../lib/libtao.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tao.dir/build: ../lib/libtao.so

.PHONY : CMakeFiles/tao.dir/build

CMakeFiles/tao.dir/requires: CMakeFiles/tao.dir/tao/log.cpp.o.requires
CMakeFiles/tao.dir/requires: CMakeFiles/tao.dir/tao/fiber.cpp.o.requires
CMakeFiles/tao.dir/requires: CMakeFiles/tao.dir/tao/util.cpp.o.requires
CMakeFiles/tao.dir/requires: CMakeFiles/tao.dir/tao/config.cpp.o.requires
CMakeFiles/tao.dir/requires: CMakeFiles/tao.dir/tao/thread.cpp.o.requires

.PHONY : CMakeFiles/tao.dir/requires

CMakeFiles/tao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tao.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tao.dir/clean

CMakeFiles/tao.dir/depend:
	cd /home/nowcoder/Tao/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nowcoder/Tao /home/nowcoder/Tao /home/nowcoder/Tao/build /home/nowcoder/Tao/build /home/nowcoder/Tao/build/CMakeFiles/tao.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tao.dir/depend

