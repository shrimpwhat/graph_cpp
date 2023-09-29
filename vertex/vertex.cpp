#include "vertex.h"
#include <algorithm>

void vertex::add_edge(vertex &w, int c) {
    edges.emplace_front(w, c);
}

void vertex::delete_edge(const vertex &v) {
    edges.remove_if([&v](const edge &e) { return e.node.name == v.name; });
}

void vertex::edit_edge(const vertex &v, int value) {
    auto it = std::find_if(
            edges.begin(),
            edges.end(),
            [&v](edge el) { return el.node.name == v.name; }
    );
    if (it != edges.end())
        it->value = value;
}

std::forward_list<edge>::iterator vertex::first() {
    return edges.begin();
}

std::forward_list<edge>::iterator vertex::next(const std::forward_list<edge>::iterator &from) {
    return std::next(from);
}

std::forward_list<edge>::iterator vertex::end() {
    return edges.end();
}

std::ostream &operator<<(std::ostream &os, vertex &v) {
    os << v.name << ": ";
    for (const auto &e: v.edges)
        os << e.node.name << "(" << e.value << "), ";
    return os;
}
