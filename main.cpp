#include "graph/graph.h"
#include "utils.h"
#include <iostream>

using namespace std;

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
    graph my_graph = read_graph((char *) "graph2.txt");
    cout << my_graph;
    bfs(my_graph);
}
