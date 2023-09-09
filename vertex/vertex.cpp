#include "vertex.h"

void vertex::add_edge(const vertex &w, int c) {
    auto new_edge = std::make_shared<edge>(w, c);
    new_edge->next = head;
    head = new_edge;
}

void vertex::delete_edge(std::shared_ptr<edge> &curr, std::shared_ptr<edge> &prev) {
    if (prev != nullptr)
        prev->next = curr->next;
    else
        head = curr->next;
}

void vertex::delete_edge(const vertex &v) {
    std::shared_ptr<edge> prev = nullptr;
    // Перебор всех узлов у данной вершины
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (v.name == it->node.name) {
            auto i = it.get_pointer();
            delete_edge(i, prev);
            return;
        }
        prev = it.get_pointer();
    }
}

void vertex::edit_edge(const vertex &v, int value) {
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (v.name == it->node.name) {
            it->value = value;
            return;
        }
    }
}

std::shared_ptr<vertex> vertex::first() {
    return head != nullptr ? std::make_shared<vertex>(head->node) : nullptr;
}

std::shared_ptr<vertex> vertex::next(const std::shared_ptr<vertex> &i_from) {
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (it->node.name == i_from->name) {
            ++it;
            return std::make_shared<vertex>(it->node);
        }
    }
    return nullptr;
}

edge_iterator vertex::begin() const {
    return edge_iterator(head);
}

edge_iterator vertex::end() {
    return {};
}