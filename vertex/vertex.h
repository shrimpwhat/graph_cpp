#pragma once

#include "edge_iterator/edge_iterator.h"

class vertex {
public:
    char name;
    int mark;
    std::shared_ptr<edge> head;

    vertex() : name(), mark() {};

    vertex(const char name, const int mark) : name(name), mark(mark) {
    }

    void add_edge(int w, int c);

    void delete_edge(const std::shared_ptr<edge> &curr, const std::shared_ptr<edge> &prev);

    void delete_edge(int v, bool decrement = false);

    void edit_edge(int v, int value) const;

    int first() const;

    int next(int i_from) const;

    edge_iterator begin();
};
