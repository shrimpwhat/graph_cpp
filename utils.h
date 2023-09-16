#include "graph/graph.h"
#include <queue>
#include <iostream>
#include <string>
#include <fstream>

void bfs(graph &g) {
    short vertex_count = 0, edge_count = 0;
    std::queue<vertex *> q;
    auto vertex_ptr = g.get_unvisited_vertex();

    // Пока есть непосещенные вершины
    while (vertex_ptr != nullptr) {
        ++vertex_count;
        q.push(vertex_ptr);

        // Сам BFS
        while (!q.empty()) {
            vertex *current = q.front();
            for (edge_iterator it = g.begin(*current), end = graph::end(); it != end; ++it, ++edge_count) {
                vertex &v = it->node;
                if (v.mark == 0) {
                    ++vertex_count;
                    v.mark = 1;
                    q.push(&v);
                }
            }
            current->mark = 2;
            q.pop();
        }

        // Берем следующую непосещённую вершину, если BFS куда-то не дошел
        vertex_ptr = g.get_unvisited_vertex();
    }

    std::cout << "Graph's cyclomatic complexity is " << edge_count - vertex_count + 2;
}

graph read_graph(char file_name[]) {
    std::ifstream file(file_name);
    graph g;
    std::string vertexes;
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
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