#pragma once

#include "vertex/vertex.h"
#include <forward_list>
#include <iostream>


class graph {
public:
    std::forward_list<vertex> list_;

    graph();

    std::forward_list<vertex>::iterator get_vertex(char v);

    void add_vertex(char name, int mark = 0);

    void add_edge(char v, char w, int value);

    void delete_vertex(char v);

    void delete_edge(char v, char w);

    void edit_vertex(char name, int mark);

    void edit_edge(char v, char w, int value);

    std::forward_list<edge>::iterator first(char v);

    static std::forward_list<edge>::iterator next(const std::forward_list<edge>::iterator &from);

    friend std::ostream &operator<<(std::ostream &os, graph &g);

    std::forward_list<edge>::iterator end(char v);
};

