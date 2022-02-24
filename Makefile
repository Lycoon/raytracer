# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/lycoon/image_s8/tp1-isim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lycoon/image_s8/tp1-isim

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lycoon/image_s8/tp1-isim/CMakeFiles /home/lycoon/image_s8/tp1-isim/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lycoon/image_s8/tp1-isim/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named raytracer

# Build rule for target.
raytracer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 raytracer
.PHONY : raytracer

# fast build rule for target.
raytracer/fast:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/build
.PHONY : raytracer/fast

core/camera.o: core/camera.cc.o

.PHONY : core/camera.o

# target to build an object file
core/camera.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/camera.cc.o
.PHONY : core/camera.cc.o

core/camera.i: core/camera.cc.i

.PHONY : core/camera.i

# target to preprocess a source file
core/camera.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/camera.cc.i
.PHONY : core/camera.cc.i

core/camera.s: core/camera.cc.s

.PHONY : core/camera.s

# target to generate assembly for a file
core/camera.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/camera.cc.s
.PHONY : core/camera.cc.s

core/color.o: core/color.cc.o

.PHONY : core/color.o

# target to build an object file
core/color.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/color.cc.o
.PHONY : core/color.cc.o

core/color.i: core/color.cc.i

.PHONY : core/color.i

# target to preprocess a source file
core/color.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/color.cc.i
.PHONY : core/color.cc.i

core/color.s: core/color.cc.s

.PHONY : core/color.s

# target to generate assembly for a file
core/color.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/color.cc.s
.PHONY : core/color.cc.s

core/image.o: core/image.cc.o

.PHONY : core/image.o

# target to build an object file
core/image.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/image.cc.o
.PHONY : core/image.cc.o

core/image.i: core/image.cc.i

.PHONY : core/image.i

# target to preprocess a source file
core/image.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/image.cc.i
.PHONY : core/image.cc.i

core/image.s: core/image.cc.s

.PHONY : core/image.s

# target to generate assembly for a file
core/image.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/core/image.cc.s
.PHONY : core/image.cc.s

graphics/sphere.o: graphics/sphere.cc.o

.PHONY : graphics/sphere.o

# target to build an object file
graphics/sphere.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/sphere.cc.o
.PHONY : graphics/sphere.cc.o

graphics/sphere.i: graphics/sphere.cc.i

.PHONY : graphics/sphere.i

# target to preprocess a source file
graphics/sphere.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/sphere.cc.i
.PHONY : graphics/sphere.cc.i

graphics/sphere.s: graphics/sphere.cc.s

.PHONY : graphics/sphere.s

# target to generate assembly for a file
graphics/sphere.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/sphere.cc.s
.PHONY : graphics/sphere.cc.s

graphics/uniform-texture.o: graphics/uniform-texture.cc.o

.PHONY : graphics/uniform-texture.o

# target to build an object file
graphics/uniform-texture.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/uniform-texture.cc.o
.PHONY : graphics/uniform-texture.cc.o

graphics/uniform-texture.i: graphics/uniform-texture.cc.i

.PHONY : graphics/uniform-texture.i

# target to preprocess a source file
graphics/uniform-texture.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/uniform-texture.cc.i
.PHONY : graphics/uniform-texture.cc.i

graphics/uniform-texture.s: graphics/uniform-texture.cc.s

.PHONY : graphics/uniform-texture.s

# target to generate assembly for a file
graphics/uniform-texture.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/graphics/uniform-texture.cc.s
.PHONY : graphics/uniform-texture.cc.s

math/point3.o: math/point3.cc.o

.PHONY : math/point3.o

# target to build an object file
math/point3.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/point3.cc.o
.PHONY : math/point3.cc.o

math/point3.i: math/point3.cc.i

.PHONY : math/point3.i

# target to preprocess a source file
math/point3.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/point3.cc.i
.PHONY : math/point3.cc.i

math/point3.s: math/point3.cc.s

.PHONY : math/point3.s

# target to generate assembly for a file
math/point3.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/point3.cc.s
.PHONY : math/point3.cc.s

math/vector3.o: math/vector3.cc.o

.PHONY : math/vector3.o

# target to build an object file
math/vector3.cc.o:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/vector3.cc.o
.PHONY : math/vector3.cc.o

math/vector3.i: math/vector3.cc.i

.PHONY : math/vector3.i

# target to preprocess a source file
math/vector3.cc.i:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/vector3.cc.i
.PHONY : math/vector3.cc.i

math/vector3.s: math/vector3.cc.s

.PHONY : math/vector3.s

# target to generate assembly for a file
math/vector3.cc.s:
	$(MAKE) -f CMakeFiles/raytracer.dir/build.make CMakeFiles/raytracer.dir/math/vector3.cc.s
.PHONY : math/vector3.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... raytracer"
	@echo "... core/camera.o"
	@echo "... core/camera.i"
	@echo "... core/camera.s"
	@echo "... core/color.o"
	@echo "... core/color.i"
	@echo "... core/color.s"
	@echo "... core/image.o"
	@echo "... core/image.i"
	@echo "... core/image.s"
	@echo "... graphics/sphere.o"
	@echo "... graphics/sphere.i"
	@echo "... graphics/sphere.s"
	@echo "... graphics/uniform-texture.o"
	@echo "... graphics/uniform-texture.i"
	@echo "... graphics/uniform-texture.s"
	@echo "... math/point3.o"
	@echo "... math/point3.i"
	@echo "... math/point3.s"
	@echo "... math/vector3.o"
	@echo "... math/vector3.i"
	@echo "... math/vector3.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

