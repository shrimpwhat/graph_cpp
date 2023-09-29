#include "graph/graph.h"
#include "utils.h"
#include <iostream>

using namespace std;

// Проверка работы методов
void test(graph &my_graph) {
    // Удаление дуг
    my_graph.delete_edge('B', 'E');
    my_graph.delete_edge('A', 'B');

    // Удаление вершин
    my_graph.delete_vertex('A');
    my_graph.delete_vertex('B');

    // Редактирование дуги
    my_graph.edit_edge('C', 'D', 10);

    cout << my_graph << endl;

    // Для проверки функций first и next
    char v = 'D';
    my_graph.add_edge('C', 'A', 5);
    for (auto i = my_graph.first(v); i != my_graph.end(v); i = graph::next(i))
        cout << i->node.name << "(" << i->value << ") ";
}

int main() {
    graph my_graph = read_graph((char *) "graph1.txt");
    cout << my_graph << endl;
    bfs(my_graph);
//    test(my_graph);
}
