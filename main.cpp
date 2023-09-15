#include "graph/graph.h"
#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

graph read_graph(char file_name[]) {
    std::ifstream file(file_name);
    graph g;
    std::string vertexes;
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
    }
    std::getline(file, vertexes);
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


void bfs(graph &g, char start_vertex) {
    vertex &start = g.get_vertex(start_vertex);
    queue<vertex *> q({&start});
    while (!q.empty()) {
        vertex *current = q.front();
        for (edge_iterator it = g.begin(*current), end = graph::end(); it != end; ++it) {
            vertex &v = it->node;
            if (v.mark == 0) {
                v.mark = 1;
                q.push(&v);
            }
        }
        current->mark = 2;
        q.pop();
    }
}

// Проверка работы методов
void test(graph &my_graph) {
    // Удаление вершин и узлов
    my_graph.delete_edge('B', 'C');
    my_graph.delete_edge('A', 'B');
    cout << my_graph << endl;

    my_graph.delete_vertex('A');
    cout << my_graph << endl;

    my_graph.delete_vertex('B');
    cout << my_graph << endl;

    // Редактирование узла
    my_graph.edit_edge('C', 'D', 10);
    cout << my_graph << endl;

    // Для проверки функций first и next
//    my_graph.add_edge('C', 'A', 5);
//    for (auto i = my_graph.first('C'); i != nullptr; i = my_graph.next('C', i))
//        cout << i->name << " ";
}

int main() {
    graph my_graph = read_graph((char *) "graph1.txt");
    cout << my_graph;
    bfs(my_graph, 'E');
}
