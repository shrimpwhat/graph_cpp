#pragma once

#include "vertex/vertex.h"
#include <vector>
#include <vertex/vertex.h>


class graph {
    std::vector<vertex> list_;

public:
    graph();

    int first(int v);

    int next(int v, int i);

    vertex &get_vertex(int i);

    int vertex_count() const;

    int index_of_vertex(char v) const;

    void add_vertex(char name, int mark = 0);

    void add_edge(char v, char w, int value);

    void delete_vertex(char v);

    void delete_edge(char v, char w);

    void edit_vertex(char name, int mark);

    void edit_edge(char v, char w, int value);

    edge_iterator begin(char v);

    edge_iterator begin(int v);

    static edge_iterator end();

    friend std::ostream &operator<<(std::ostream &os, graph &g);
};
