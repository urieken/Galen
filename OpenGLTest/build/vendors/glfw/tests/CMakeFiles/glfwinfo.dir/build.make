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
include vendors/glfw/tests/CMakeFiles/glfwinfo.dir/depend.make

# Include the progress variables for this target.
include vendors/glfw/tests/CMakeFiles/glfwinfo.dir/progress.make

# Include the compile flags for this target's objects.
include vendors/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: ../vendors/glfw/tests/glfwinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/glfwinfo.c.o   -c /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/tests/glfwinfo.c

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/glfwinfo.c.i"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/tests/glfwinfo.c > CMakeFiles/glfwinfo.dir/glfwinfo.c.i

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/glfwinfo.c.s"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/tests/glfwinfo.c -o CMakeFiles/glfwinfo.dir/glfwinfo.c.s

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires:

.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
	$(MAKE) -f vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build.make vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build
.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o


vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: ../vendors/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o   -c /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/getopt.c

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/getopt.c > CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/getopt.c -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires:

.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build.make vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build
.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o


vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/flags.make
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o: ../vendors/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad.c.o   -c /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad.c.i"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c > CMakeFiles/glfwinfo.dir/__/deps/glad.c.i

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad.c.s"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/deps/glad.c -o CMakeFiles/glfwinfo.dir/__/deps/glad.c.s

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.requires:

.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.requires

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.provides: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.requires
	$(MAKE) -f vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build.make vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.provides.build
.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.provides

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.provides.build: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o


# Object files for target glfwinfo
glfwinfo_OBJECTS = \
"CMakeFiles/glfwinfo.dir/glfwinfo.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad.c.o"

# External object files for target glfwinfo
glfwinfo_EXTERNAL_OBJECTS =

vendors/glfw/tests/glfwinfo: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o
vendors/glfw/tests/glfwinfo: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o
vendors/glfw/tests/glfwinfo: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o
vendors/glfw/tests/glfwinfo: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build.make
vendors/glfw/tests/glfwinfo: vendors/glfw/src/libglfw3.a
vendors/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
vendors/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/librt.so
vendors/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
vendors/glfw/tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libX11.so
vendors/glfw/tests/glfwinfo: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/galen/Development/OpenGL/Galen/OpenGLTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable glfwinfo"
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build: vendors/glfw/tests/glfwinfo

.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/build

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/requires: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/requires: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
vendors/glfw/tests/CMakeFiles/glfwinfo.dir/requires: vendors/glfw/tests/CMakeFiles/glfwinfo.dir/__/deps/glad.c.o.requires

.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/requires

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/clean:
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/glfwinfo.dir/cmake_clean.cmake
.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/clean

vendors/glfw/tests/CMakeFiles/glfwinfo.dir/depend:
	cd /home/galen/Development/OpenGL/Galen/OpenGLTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/galen/Development/OpenGL/Galen/OpenGLTest /home/galen/Development/OpenGL/Galen/OpenGLTest/vendors/glfw/tests /home/galen/Development/OpenGL/Galen/OpenGLTest/build /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests /home/galen/Development/OpenGL/Galen/OpenGLTest/build/vendors/glfw/tests/CMakeFiles/glfwinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vendors/glfw/tests/CMakeFiles/glfwinfo.dir/depend

