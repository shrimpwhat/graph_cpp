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

    explicit vertex(char name, int mark = 0) : name(name), mark(mark) {
    }

    void add_edge(vertex &v, int c);

    /**
     * Удаляет дугу curr и сдвигает оставшиеся дуги в prev
     * @param curr Дуга, которая необходимо удалить
     * @param prev Дуга перед curr
    */
    void delete_edge(std::shared_ptr<edge> &curr, std::shared_ptr<edge> &prev);

    /**
     * Удаляет дугу между данной вершиной и вершиной v
     * @param v Вершина, которая связана с данной
     */
    void delete_edge(const vertex &v);

    void edit_edge(const vertex &v, int value);

    // Методы first и next из задания(не использую)
    std::shared_ptr<vertex> first();

    std::shared_ptr<vertex> next(const std::shared_ptr<vertex> &i_from);

    // Альтернативное решение через итераторы(для обхода по всем дугам данной вершины)
    [[nodiscard]] edge_iterator begin() const;

    static edge_iterator end();
};
