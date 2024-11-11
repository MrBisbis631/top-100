#pragma once

#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>

class Graph
{
private:
    std::unordered_multimap<int, int> graph;

public:
    void add_vertex(int v);
    void add_edge(std::pair<int, int> e);
    void remove_vertex(int v);
    void remove_edge(std::pair<int, int> e);
    bool has_vertex(int v);
    bool has_edge(std::pair<int, int> e);
};
