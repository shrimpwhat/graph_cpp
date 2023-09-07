#include "edge_iterator.h"

edge_iterator::edge_iterator(std::shared_ptr<edge> &ptr) : ptr(ptr) {
}

std::shared_ptr<edge> edge_iterator::operator->() const {
    return ptr;
}

edge_iterator &edge_iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

bool edge_iterator::operator!=(const edge_iterator &a) {
    return a.ptr != ptr;
}

