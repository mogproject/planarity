#pragma once
#include <fstream>
#include <sstream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>

typedef boost::adjacency_list<                    //
    boost::vecS,                                  //
    boost::vecS,                                  //
    boost::undirectedS,                           //
    boost::property<boost::vertex_index_t, int>,  //
    boost::property<boost::edge_index_t, int>>
    Graph;

namespace readwrite {
Graph read_pace_2023(std::istream &is);

Graph load_pace_2023(char const *path);
}  // namespace readwrite
