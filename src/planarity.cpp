#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#include <CLI11.hpp>

#include "readwrite/graph_io.hpp"

std::string const PROGRAM_NAME = "planarity";
std::string const PROGRAM_VERSION = "0.0.1-SNAPSHOT";

/**
 * @brief Entry point of the program.
 *
 * @param argc argument count
 * @param argv argument strings
 * @return int status code
 */
int main(int argc, char* argv[]) {
  // parameters and flags
  bool print_version = false;

  // parse arguments
  CLI::App app{"Exact solver for PACE 2023"};
  app.add_flag("--version", print_version, "Print program's version number and exit");
  CLI11_PARSE(app, argc, argv);

  // show version
  if (print_version) {
    printf("%s %s\n", PROGRAM_NAME.c_str(), PROGRAM_VERSION.c_str());
    return 0;
  }

  // load graph
  auto g = readwrite::read_pace_2023(std::cin);

  // planarity test
  bool is_planar = boost::boyer_myrvold_planarity_test(g);
  printf("%d\n", is_planar);  // 1: planar, 0: not planar

  return 0;
}
