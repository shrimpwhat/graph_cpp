#pragma once

#include "edge_iterator/edge_iterator.h"

class edge;

class edge_iterator;

class vertex {
public:
    char name;
    int mark;
    std::shared_ptr<edge> head;

    vertex() : name(), mark() {};

    explicit vertex(char name, const int mark = 0) : name(name), mark(mark) {
    }

    void add_edge(const std::shared_ptr<vertex> &v, int c);

    /**
     * Удаляет узел curr и сдвигает оставшиеся узлы в prev
     * @param curr Узел, который необходимо удалить
     * @param prev Узел перед curr
    */
    void delete_edge(std::shared_ptr<edge> &curr, std::shared_ptr<edge> &prev);

    /**
     *  Удаляет узел между данной вершиной и вершиной v
     * @param v Вершина, которая связана с данной
     */
    void delete_edge(const std::shared_ptr<vertex> &v);

    void edit_edge(const std::shared_ptr<vertex> &v, int value);

    std::shared_ptr<vertex> first();

    std::shared_ptr<vertex> next(const std::shared_ptr<vertex> &i_from);

    edge_iterator begin();

    static edge_iterator end();
};
