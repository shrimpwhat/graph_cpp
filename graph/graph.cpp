#include "graph.h"
#include <iostream>

graph::graph() {
    list_ = std::vector<vertex>(0);
}

int graph::vertex_count() const {
    return list_.size();
}

int graph::index_of_vertex(char v) const {
    for (auto i = list_.begin(); i < list_.end(); ++i)
        if (i->name == v)
            return i - list_.begin();
    return -1;
}

void graph::add_vertex(char name, int mark) {
    list_.emplace_back(name, mark);
}

void graph::add_edge(char v, char w, int value) {
    int v_index = index_of_vertex(v);
    int w_index = index_of_vertex(w);
    list_.at(v_index).add_edge(w_index, value);
}

void graph::delete_vertex(char v) {
    int index = index_of_vertex(v);

    for (auto i = list_.begin(); i < list_.end(); ++i)
        if (i->name != v) {
            i->delete_edge(index, true);
        }

    list_.erase(index + list_.begin());
}

void graph::delete_edge(char v, char w) {
    int v_index = index_of_vertex(v);
    int w_index = index_of_vertex(w);
    list_.at(v_index).delete_edge(w_index);
}

void graph::edit_vertex(char name, int mark) {
    int index = index_of_vertex(name);
    list_.at(index).mark = mark;
}

void graph::edit_edge(char v, char w, int value) {
    int v_index = index_of_vertex(v);
    int w_index = index_of_vertex(w);
    list_.at(v_index).edit_edge(w_index, value);
}

int graph::first(int v) {
    return get_vertex(v).first();
}

int graph::next(int v, int i_from) {
    return list_.at(v).next(i_from);
}

vertex &graph::get_vertex(int i) {
    return list_.at(i);
}

edge_iterator graph::begin(int v) {
    return list_.at(v).begin();
}

edge_iterator graph::begin(char v) {
    return list_.at(index_of_vertex(v)).begin();
}

edge_iterator graph::end() {
    return {};
}

std::ostream &operator<<(std::ostream &os, graph &g) {
    for (int i = 0; i < g.list_.size(); ++i) {
        os << g.list_.at(i).name << ": ";
        for (edge_iterator it = g.begin(i), end = graph::end(); it != end; ++it) {
            std::cout << g.list_.at(it->node).name << "(" << it->value << "), ";
        }
        os << std::endl;
    }
    return os;
}



