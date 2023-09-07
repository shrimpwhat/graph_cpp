#include "graph/graph.h"
#include <iostream>

using namespace std;


int main() {
    graph my_graph;

    // Проверка работы методов
    char vertexes[] = "ABCDE";
    for (char c: vertexes)
        if (c != '\0')
            my_graph.add_vertex(c);

    my_graph.add_edge('A', 'B', 1);
    my_graph.add_edge('A', 'C', 2);
    my_graph.add_edge('B', 'C', 3);
    my_graph.add_edge('C', 'D', 4);
    my_graph.add_edge('D', 'A', 5);
    my_graph.add_edge('A', 'D', 1);
    cout << my_graph << endl;

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
}
