[![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg)](http://choosealicense.com/licenses/apache-2.0/)

# Planarity

Linear-time graph planarity testing. Uses the Boost Graph Library (BGL).

### Dependencies

- C++ compiler supporting the C++14 standard ([GCC](https://gcc.gnu.org/) recommended)
- [GNU Make](https://www.gnu.org/software/make/)
- [CMake](https://cmake.org/) Version 3.14 or later
- [CLI11](https://github.com/CLIUtils/CLI11) (included in this repository)
- [Boost C++ Libraries](https://www.boost.org/) (tested with version 1.83.0)

### Build Usage

Use `make` in this project directory. To make this work, the environment variable `BOOST_ROOT` must be set.

| Operation | Command |
|:---|:---|
|Build release version | `make build` $\to$ executable `planarity` will be generated in the `dist` directory|
|Build debug version | `make build-debug` $\to$ creates `build/Debug/planarity`|
|Clean build files | `make clean` |

### Program Usage

| Operation | Command |
|:---|:---|
|Print help message | `planarity --help`|
|Print version | `planarity --version`|
|Test planarity | `planarity < PATH` (PATH: path to an instance file)<br>Currently, only the [PACE 2023 input format](https://pacechallenge.org/2023/io/) is supported. Program outputs `1` if the input graph is planar and `0` otherwise.|

### Getting Started

1. Download and install the [Boost C++ Libraries](https://www.boost.org/).

Example on Mac (installing to `/usr/local/lib/boost_1_83_0`):

```bash
$ wget https://boostorg.jfrog.io/artifactory/main/release/1.83.0/source/boost_1_83_0.tar.bz2
$ sudo tar -xf boost_1_83_0.tar.bz2 -C /usr/local/lib
```

2. Create a file `.env` in this directory.

Example content:

```bash
CC=/opt/homebrew/bin/gcc-13
CXX=/opt/homebrew/bin/g++-13
BOOST_ROOT=/usr/local/lib/boost_1_83_0
```

3. Build the `planarity` program.

```bash
$ make
```

4. Make sure that the build succeeded.

```bash
$ dist/planarity --version
```

The program version should be displayed.

5. Test the planarity of graphs.

```bash
$ dist/planarity
(input the following)
p tww 3 3
1 2
1 3
2 3
(press Ctrl-D)
1
```

The output `1` means that the given graph is planar.

```bash
$ dist/planarity
(input the following)
p tww 6 9
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6
(press Ctrl-D)
0
```

The output `0` means that the given graph is not planar.
