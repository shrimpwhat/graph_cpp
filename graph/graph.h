#pragma once

#include "vertex/vertex.h"
#include <list>


class graph {
    std::list<vertex> list_;

    // Возвращают итератор на вершину из текущего списка вершин
    std::list<vertex>::const_iterator get_iterator(char v) const;

    std::list<vertex>::const_iterator get_iterator(const vertex &v) const;

public:
    graph();

    vertex &get_vertex(char v);

    void add_vertex(char name, int mark = 0);

    void add_edge(char v, char w, int value);

    void delete_vertex(char v);

    void delete_edge(char v, char w);

    void edit_vertex(char name, int mark);

    void edit_edge(char v, char w, int value);

    // Методы first и next из задания(не использую)
    std::shared_ptr<vertex> first(char v);

    std::shared_ptr<vertex> next(char v, std::shared_ptr<vertex> &i_from);

    // Альтернативное решение через итераторы(для обхода по всем узлам вершины)
    edge_iterator begin(char v);

    edge_iterator begin(const vertex &v);

    static edge_iterator end();

    friend std::ostream &operator<<(std::ostream &os, graph &g);
};
