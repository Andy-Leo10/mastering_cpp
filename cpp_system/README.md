# How to compile and run the C++ system

## Prerequisites
- Create folder with an structure like this containing folder.  
  - add `build` folder for the build files
  - add `src` folder and put the source files in it
  - other folders can be added as needed
- Create a CMakelists.txt file and specify the necessary things.

## Steps
1. Move to the `build` folder
2. Run `cmake ..` to generate the build files
3. Run `make` to compile the source files
4. Run the executable file generated

```
cd /home/sinso/ros2_ws/src/mastering_cpp/cpp_system/build
cmake ..
make
./main
```