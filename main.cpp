#include "graph/graph.h"
#include <iostream>

using namespace std;

int main() {
    // Проверка работы методов
    const char vertexes[] = "ABCDE";
    graph my_graph;
    for (char c: vertexes)
        if (c != '\0')
            my_graph.add_vertex(c);

    my_graph.add_edge('A', 'B', 1);
    my_graph.add_edge('A', 'C', 2);
    my_graph.add_edge('B', 'C', 3);
    my_graph.add_edge('C', 'D', 4);
    my_graph.add_edge('D', 'A', 5);
    my_graph.add_edge('A', 'D', 1);
    my_graph.add_edge('E', 'B', 9);
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

    // Для проверки функций first и next
//    my_graph.add_edge('C', 'E', 5);
//    for (auto i = my_graph.first('C'); i != nullptr; i = my_graph.next('C', i))
//        cout << i->name << " ";
}
