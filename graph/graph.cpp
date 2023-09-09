#include "graph.h"
#include <iostream>

graph::graph() {
    list_ = {};
}

void graph::add_vertex(char name, int mark) {
    list_.emplace_back(name);
}

void graph::add_edge(char v, char w, int value) {
    vertex &w_vertex = get_vertex(w);
    get_vertex(v).add_edge(w_vertex, value);
}

void graph::delete_edge(char v, char w) {
    vertex &w_vertex = get_vertex(w);
    get_vertex(v).delete_edge(w_vertex);
}

void graph::delete_vertex(char v) {
    for (auto &i: list_)
        if (i.name != v)
            delete_edge(i.name, v);
    list_.erase(get_iterator(v));
}

void graph::edit_vertex(char name, int mark) {
    vertex &v = get_vertex(name);
    v.mark = mark;
}

void graph::edit_edge(char v, char w, int value) {
    get_vertex(v).edit_edge(get_vertex(w), value);
}

std::shared_ptr<vertex> graph::first(char v) {
    return get_vertex(v).first();
}

std::shared_ptr<vertex> graph::next(char v, std::shared_ptr<vertex> &i_from) {
    return get_vertex(v).next(i_from);
}

std::list<vertex>::const_iterator graph::get_iterator(char v) const {
    for (auto i = list_.begin(); i != list_.end(); ++i)
        if (i->name == v)
            return i;
    std::string name{v};
    throw std::runtime_error("Missing vertex " + name + " int graph");
}

std::list<vertex>::const_iterator graph::get_iterator(const vertex &v) const {
    return get_iterator(v.name);
}

vertex &graph::get_vertex(char v) {
    for (vertex &node: list_)
        if (node.name == v)
            return node;
    std::string name{v};
    throw std::runtime_error("Missing vertex " + name + " int graph");
}

edge_iterator graph::begin(char v) {
    return get_vertex(v).begin();
}

edge_iterator graph::begin(const vertex &v) {
    return begin(v.name);
}

edge_iterator graph::end() {
    return vertex::end();
}

std::ostream &operator<<(std::ostream &os, graph &g) {
    for (auto i = g.list_.begin(); i != g.list_.end(); ++i) {
        os << i->name << ": ";
        for (edge_iterator it = g.begin(*i), end = vertex::end(); it != end; ++it) {
            std::cout << it->node.name << "(" << it->value << "), ";
        }
        os << std::endl;
    }
    return os;
}

