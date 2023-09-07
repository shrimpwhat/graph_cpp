#include "vertex.h"

void vertex::add_edge(int w, int c) {
    std::shared_ptr<edge> new_edge = std::make_shared<edge>(w, c);
    new_edge->next = head;
    head = new_edge;
}

void vertex::delete_edge(const std::shared_ptr<edge> &curr, const std::shared_ptr<edge> &prev) {
    if (prev != nullptr)
        prev->next = curr->next;
    else
        head = curr->next;
}

void vertex::delete_edge(int v, bool decrement) {
    std::shared_ptr<edge> curr = head;
    std::shared_ptr<edge> prev = nullptr;

    while (curr != nullptr) {
        if (decrement && curr->node > v) {
            --(curr->node);
        } else if (curr->node == v) {
            delete_edge(curr, prev);
        }
        prev = curr;
        curr = curr->next;
    }
}

void vertex::edit_edge(int v, int value) const {
    std::shared_ptr<edge> curr = head;
    while (curr != nullptr) {
        if (curr->node == v) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
}

int vertex::first() const {
    return head != nullptr ? head->node : -1;
}

int vertex::next(int i_from) const {
    std::shared_ptr<edge> tmp = head;
    while (tmp != nullptr) {
        if (tmp->node == i_from)
            break;
        tmp = tmp->next;
    }
    return tmp != nullptr && tmp->next != nullptr ? tmp->next->node : -1;
}

edge_iterator vertex::begin() {
    return edge_iterator(head);
}