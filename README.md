# README

An simple 2D C++ game engine.

## Platforms

* Tested on Ubuntu Linux only.
* Should, *in theory* build and run MacOS without modificatins.
* Should, *in theory* build and run on Windows
  - Inclusion of SDL2 components will likely need to be modified to conform to
    the local SDL2 directory structure.
  - You will likely have the most luck building with WSL2 or mingw tools.
  - Could be compiled with `nmake`, and if the makefile is modified to conform
    to the limited subset of the make language supported by `nmake`.
  - Could be packaged into a simple Visual Studio 

## Dependencies

* A C++ compiler supporting C++14 (e.g. clang++, g++)
* GNU make
* SDL2
* SDL2\_image
* SDL2\_mixer
* SDL2\_ttf

## Compilation

```
$ make
```
