#include <iostream>
#include "Graph.h"

void test_add_vertex(Graph& g) {
    g.add_vertex(1);
    if (g.has_vertex(1)) {
        std::cout << "Test add_vertex passed." << std::endl;
    } else {
        std::cout << "Test add_vertex failed." << std::endl;
    }
}

void test_add_edge(Graph& g) {
    g.add_edge({1, 2});
    if (g.has_edge({1, 2})) {
        std::cout << "Test add_edge passed." << std::endl;
    } else {
        std::cout << "Test add_edge failed." << std::endl;
    }
}

void test_remove_vertex(Graph& g) {
    g.remove_vertex(1);
    if (!g.has_vertex(1)) {
        std::cout << "Test remove_vertex passed." << std::endl;
    } else {
        std::cout << "Test remove_vertex failed." << std::endl;
    }
}

void test_remove_edge(Graph& g) {
    g.remove_edge({1, 2});
    if (!g.has_edge({1, 2})) {
        std::cout << "Test remove_edge passed." << std::endl;
    } else {
        std::cout << "Test remove_edge failed." << std::endl;
    }
}

int main() {
    Graph g;

    test_add_vertex(g);
    test_add_edge(g);
    test_remove_vertex(g);
    test_remove_edge(g);

    return 0;
}