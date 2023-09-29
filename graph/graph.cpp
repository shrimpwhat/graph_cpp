#include "graph.h"
#include <iostream>
#include <algorithm>

graph::graph() {
    list_ = {};
}

void graph::add_vertex(char name, int mark) {
    list_.emplace_front(name, mark);
}

void graph::add_edge(char v, char w, int value) {
    auto w_vertex = get_vertex(w);
    get_vertex(v)->add_edge(*w_vertex, value);
}

void graph::delete_edge(char v, char w) {
    auto w_vertex = get_vertex(w);
    auto v_vertex = get_vertex(v);
    v_vertex->delete_edge(*w_vertex);
}

void graph::delete_vertex(char v) {
    for (auto &i: list_)
        if (i.name != v)
            delete_edge(i.name, v);
    list_.remove_if([&v](const vertex &i) { return i.name == v; });
}

void graph::edit_vertex(char name, int mark) {
    auto v = get_vertex(name);
    v->mark = mark;
}

void graph::edit_edge(char v, char w, int value) {
    auto w_vertex = get_vertex(w);
    get_vertex(v)->edit_edge(*w_vertex, value);
}


std::forward_list<vertex>::iterator graph::get_vertex(char v) {
    auto it = std::find_if(
            list_.begin(),
            list_.end(),
            [&v](const vertex &w) { return w.name == v; }
    );
    if (it != list_.end())
        return it;
    std::string name{v};
    throw std::runtime_error("Missing vertex " + name + " in graph");
}

std::ostream &operator<<(std::ostream &os, graph &g) {
    g.list_.reverse();
    for (auto &v: g.list_)
        os << v << '\n';
    return os;
}

std::forward_list<edge>::iterator graph::first(char v) {
    auto it = get_vertex(v);
    return it->first();
}

std::forward_list<edge>::iterator graph::next(const std::forward_list<edge>::iterator &from) {
    return vertex::next(from);
}

std::forward_list<edge>::iterator graph::end(char v) {
    return get_vertex(v)->end();
}