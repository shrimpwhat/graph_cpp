#include "edge_iterator.h"

edge_iterator::edge_iterator(std::shared_ptr<edge> &ptr) : ptr(ptr) {
}

edge &edge_iterator::operator*() {
    return *ptr;
}

std::shared_ptr<edge> edge_iterator::operator->() {
    return ptr;
}

edge_iterator &edge_iterator::operator++() {
    if (ptr != nullptr)
        ptr = ptr->next;
    return *this;
}

bool edge_iterator::operator!=(const edge_iterator &a) const {
    return a.ptr != ptr;
}

std::shared_ptr<edge> edge_iterator::get_pointer() {
    return ptr;
}
