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
CMAKE_SOURCE_DIR = /home/galen/Development/OpenGL/Galen/OpenGLTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/galen/Development/OpenGL/Galen/OpenGLTest/build

# Include any dependencies generated for this target.
include vendors/glfw/examples/CMakeFiles/splitview.dir/depend.make

# Include the progress variables for this target.
include vendors/glfw/examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include vendors/glfw/examples/CMakeFiles/splitview.dir/flags.make

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o: vendors/glfw/examples/CMakeFiles/splitview.dir/flags.make
vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o: ../vendors/glfw/examples/splitview.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/splitview.c.o   -c /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/examples/splitview.c

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/examples/splitview.c > CMakeFiles/splitview.dir/splitview.c.i

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/examples/splitview.c -o CMakeFiles/splitview.dir/splitview.c.s

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires:

.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides: vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires
	$(MAKE) -f vendors/glfw/examples/CMakeFiles/splitview.dir/build.make vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build
.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides

vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build: vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o


vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o: vendors/glfw/examples/CMakeFiles/splitview.dir/flags.make
vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o: ../vendors/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/__/deps/glad.c.o   -c /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c

vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/__/deps/glad.c.i"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c > CMakeFiles/splitview.dir/__/deps/glad.c.i

vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/__/deps/glad.c.s"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c -o CMakeFiles/splitview.dir/__/deps/glad.c.s

vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires:

.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires

vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides: vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires
	$(MAKE) -f vendors/glfw/examples/CMakeFiles/splitview.dir/build.make vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides.build
.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides

vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.provides.build: vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o


# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.o" \
"CMakeFiles/splitview.dir/__/deps/glad.c.o"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

vendors/glfw/examples/splitview: vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o
vendors/glfw/examples/splitview: vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o
vendors/glfw/examples/splitview: vendors/glfw/examples/CMakeFiles/splitview.dir/build.make
vendors/glfw/examples/splitview: vendors/glfw/src/libglfw3.a
vendors/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
vendors/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/librt.so
vendors/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
vendors/glfw/examples/splitview: /usr/lib/x86_64-linux-gnu/libX11.so
vendors/glfw/examples/splitview: vendors/glfw/examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable splitview"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendors/glfw/examples/CMakeFiles/splitview.dir/build: vendors/glfw/examples/splitview

.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/build

vendors/glfw/examples/CMakeFiles/splitview.dir/requires: vendors/glfw/examples/CMakeFiles/splitview.dir/splitview.c.o.requires
vendors/glfw/examples/CMakeFiles/splitview.dir/requires: vendors/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad.c.o.requires

.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/requires

vendors/glfw/examples/CMakeFiles/splitview.dir/clean:
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/splitview.dir/cmake_clean.cmake
.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/clean

vendors/glfw/examples/CMakeFiles/splitview.dir/depend:
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/galen/Development/OpenGL/Galen/OpenGLTest /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/examples /home/galen/Development/OpenGL/Galen/OpenGLTest/build /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/examples/CMakeFiles/splitview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vendors/glfw/examples/CMakeFiles/splitview.dir/depend
