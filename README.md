# NHL++

This project is a simple web API processor written using [C++](https://cplusplus.com/), [libcurl](https://curl.se/libcurl/) and [nlohmann/json](https://github.com/nlohmann/json). It fetches JSON data from a public NHL Stats API, and then outputs a schedule of 2022-23 regular season games that have been played.

## Provided Files

- main.cpp (Main file for running the program)
- game.cpp and game.h (Game class with header)
- request.cpp and request.h (Request class with header)
- json.hpp (Header for the nlohmann/json library)
- Makefile (Build script for program compilation and clean up)
- README.md (Project information)

## Deployment

To build and compile the main program:

```
  make
```

To run the main program:

```
  ./main
```

To clean up the program:

```
  make clean
```
