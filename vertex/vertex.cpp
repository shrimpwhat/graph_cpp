#include "vertex.h"

void vertex::add_edge(const std::shared_ptr<vertex> &w, int c) {
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

void vertex::delete_edge(const std::shared_ptr<vertex> &v) {
    std::shared_ptr<edge> prev = nullptr;
    // Перебор всех узлов у данной вершины
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (v == it->node) {
            auto i = it.get_pointer();
            delete_edge(i, prev);
            return;
        }
        prev = it.get_pointer();
    }

//    std::shared_ptr<edge> curr = head;
//    std::shared_ptr<edge> prev = nullptr;
//
//    while (curr != nullptr) {
//        if (curr->node == v) {
//            delete_edge(curr, prev);
//            break
//        }
//        prev = curr;
//        curr = curr->next;
//    }
}

void vertex::edit_edge(const std::shared_ptr<vertex> &v, int value) {
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (v == it->node) {
            it->value = value;
            return;
        }
    }

//    std::shared_ptr<edge> curr = head;
//    while (curr != nullptr) {
//        if (curr->node == v) {
//            curr->value = value;
//            return;
//        }
//        curr = curr->next;
//    }
}

std::shared_ptr<vertex> vertex::first() {
    return head != nullptr ? head->node : nullptr;
}

std::shared_ptr<vertex> vertex::next(const std::shared_ptr<vertex> &i_from) {
    for (edge_iterator it = begin(); it != vertex::end(); ++it) {
        if (it->node == i_from) {
            ++it;
            return it->node;
        }
    }
    return nullptr;
//    std::shared_ptr<edge> tmp = head;
//    while (tmp != nullptr) {
//        if (tmp->node == i_from)
//            break;
//        tmp = tmp->next;
//    }
//    return tmp != nullptr && tmp->next != nullptr ? tmp->next->node : -1;
}

edge_iterator vertex::begin() {
    return edge_iterator(head);
}

edge_iterator vertex::end() {
    return {};
}