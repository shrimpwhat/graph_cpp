#pragma once

#include <iterator>
#include <memory>

class edge {
public:
    int node;
    int value;
    std::shared_ptr<edge> next;

    edge(int node, int value) : node(node), value(value), next(nullptr) {
    }
};

class edge_iterator {
    std::shared_ptr<edge> ptr;
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = edge;
    using pointer = edge *;
    using reference = edge &;

    edge_iterator() : ptr(nullptr) {}

    explicit edge_iterator(std::shared_ptr<edge> &ptr);
    
    std::shared_ptr<edge> operator->() const;

    edge_iterator &operator++();

    bool operator!=(const edge_iterator &a);
};