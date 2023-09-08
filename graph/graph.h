#pragma once

#include "vertex/vertex.h"
#include <vector>


class graph {
    std::vector<vertex> list_;

public:
    graph();

    vertex &get_vertex(char v);

    int index_of_vertex(char v) const;

    void add_vertex(char name, int mark = 0);

    void add_edge(char v, char w, int value);

    void delete_vertex(char v);

    void delete_edge(char v, char w);

    void edit_vertex(char name, int mark);

    void edit_edge(char v, char w, int value);

    std::shared_ptr<vertex> first(char v);

    std::shared_ptr<vertex> next(char v, std::shared_ptr<vertex> &i_from);

    edge_iterator begin(char v);

    edge_iterator begin(int v);

    friend std::ostream &operator<<(std::ostream &os, graph &g);
};
