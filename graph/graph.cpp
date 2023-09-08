#include "graph.h"
#include <iostream>

graph::graph() {
    list_ = std::vector<vertex>(0);
}

int graph::index_of_vertex(char v) const {
    for (auto i = list_.begin(); i < list_.end(); ++i)
        if (i->name == v)
            return i - list_.begin();
    return -1;
}

void graph::add_vertex(char name, int mark) {
    list_.emplace_back(name);
}

void graph::add_edge(char v, char w, int value) {
    vertex &w_vertex = get_vertex(w);
//    std::shared_ptr<vertex> p1 =
    auto w_ptr = std::shared_ptr<vertex>(&w_vertex);
    get_vertex(v).add_edge(w_ptr, value);
}

void graph::delete_vertex(char v) {
    auto v_ptr = std::make_shared<vertex>(v);
    for (auto i = list_.begin(); i < list_.end(); ++i)
        if (i->name != v) {
            vertex &w_vertex = get_vertex(i->name);
            w_vertex.delete_edge(v_ptr);
        }
    list_.erase(index_of_vertex(v) + list_.begin());
}

void graph::delete_edge(char v, char w) {
    vertex &w_vertex = get_vertex(w);
    auto w_ptr = std::make_shared<vertex>(w_vertex);
    get_vertex(v).delete_edge(w_ptr);
}

void graph::edit_vertex(char name, int mark) {
    vertex &v = get_vertex(name);
    v.mark = mark;
}

void graph::edit_edge(char v, char w, int value) {
    auto w_ptr = std::make_shared<vertex>(get_vertex(w));
    get_vertex(v).edit_edge(w_ptr, value);
}

std::shared_ptr<vertex> graph::first(char v) {
    return get_vertex(v).first();
}

std::shared_ptr<vertex> graph::next(char v, std::shared_ptr<vertex> &i_from) {
    return get_vertex(v).next(i_from);
}

vertex &graph::get_vertex(char v) {
    int index = index_of_vertex(v);
    return list_.at(index);
}

edge_iterator graph::begin(int v) {
    return list_.at(v).begin();
}

edge_iterator graph::begin(char v) {
    return get_vertex(v).begin();
}

std::ostream &operator<<(std::ostream &os, graph &g) {
    for (int i = 0; i < g.list_.size(); ++i) {
        os << g.list_.at(i).name << ": ";
        for (edge_iterator it = g.begin(i), end = vertex::end(); it != end; ++it) {
            std::cout << it->node->name << "(" << it->value << "), ";
        }
        os << std::endl;
    }
    return os;
}




