#pragma once

#include <iterator>
#include <memory>
#include <vertex/vertex.h>

struct vertex;

class edge {
public:
    const vertex &node; // Ссылка на вершину
    int value;
    std::shared_ptr<edge> next; // Указатель на следующий узел

    edge(const vertex &node, int value) : node(node), value(value), next(nullptr) {
    }
};

// Итератор для обхода через цикл for по смежным вершинам
class edge_iterator {
    std::shared_ptr<edge> ptr;
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = edge;
    using pointer = edge *;
    using reference = edge &;

    edge_iterator() : ptr(nullptr) {}

    explicit edge_iterator(const std::shared_ptr<edge> &ptr);

    edge &operator*();

    std::shared_ptr<edge> operator->();

    edge_iterator &operator++();

    bool operator!=(const edge_iterator &a) const;

    std::shared_ptr<edge> get_pointer();
};