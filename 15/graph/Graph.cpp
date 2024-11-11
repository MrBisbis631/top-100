#include "Graph.h"

#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>

void Graph::add_vertex(int v)
{
    // any vertex has v->(-1) to indicate it exists
    graph.insert({v, -1});
}

void Graph::add_edge(std::pair<int, int> e)
{
    // any edge v1->v2 should keep v1 > v2, and v1 != v2
    if (e.first == e.second)
    {
        return;
    }

    if (e.first > e.second)
    {
        std::swap(e.first, e.second);
    }

    // add edge and insure vertexes e: v1->v2 exist

    graph.insert({e.first, e.second});

    add_vertex(e.second);
    add_vertex(e.first);
}

void Graph::remove_vertex(int v)
{
    graph.erase(v);
}

void Graph::remove_edge(std::pair<int, int> e)
{
    if (e.first == e.second)
    {
        return;
    }
    else if (e.first < e.second)
    {
        std::swap(e.first, e.second);
    }

    auto range = graph.equal_range(e.first);
    auto it = std::find_if(range.first, range.second, [&](const auto &pair)
                           { return pair.second == e.second; });

    if (it != range.second)
    {
        graph.erase(it);
    }
}

bool Graph::has_vertex(int v)
{
    return graph.find(v) != graph.end();
}

bool Graph::has_edge(std::pair<int, int> e)
{
    if (e.first < e.second)
    {
        std::swap(e.first, e.second);
    }

    auto range = graph.equal_range(e.first);
    return std::any_of(range.first, range.second, [&](const std::pair<int, int> &v)
                       { return v.second == e.second; });
}
