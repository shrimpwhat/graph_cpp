#include "graph/graph.h"
#include <queue>
#include <iostream>
#include <string>
#include <fstream>

void bfs(graph &g) {
    short vertex_count = 0, edge_count = 0;
    std::queue<vertex *> q;

    // Цикл, чтобы обойти все вершины, если вдруг в какую-либо не зайдем за первый обход
    for (auto &v: g.list_) {
        if (v.mark != 0)
            continue;

        ++vertex_count;
        q.push(&v);

        // Сам BFS
        while (!q.empty()) {
            vertex *current = q.front();
            for (auto &e: current->edges) {
                ++edge_count;
                if (e.node.mark == 0) {
                    ++vertex_count;
                    e.node.mark = 1;
                    q.push(&e.node);
                }
            }
            current->mark = 2;
            q.pop();
        }
    }

    std::cout << "Graph's cyclomatic complexity is " << edge_count - vertex_count + 2;
}

graph read_graph(char file_name[]) {
    std::ifstream file(file_name);
    graph g;
    std::string vertexes;
    if (!file.is_open()) {
        throw std::runtime_error("Error opening the file.");
    }
    getline(file, vertexes);
    for (char c: vertexes)
        g.add_vertex(c);
    char v1, v2;
    int value;
    while (file >> v1 >> v2 >> value) {
        g.add_edge(v1, v2, value);
    }
    file.close();
    return g;
}