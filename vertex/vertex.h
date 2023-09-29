#pragma once

#include <forward_list>
#include <iostream>

class vertex;

// Класс дуги
class edge {
public:
    vertex &node; // Ссылка на вершину
    int value;

    edge(vertex &v, int c) : node(v), value(c) {}
};

// Класс вершины
class vertex {
public:
    char name;
    int mark;
    std::forward_list<edge> edges; // Однонаправленный линейно-связанный список дуг, исходящих из данной вершины

    vertex() : name(), mark() {};

    explicit vertex(char name, int mark = 0) : name(name), mark(mark) {
    }

    void add_edge(vertex &v, int c);

    void delete_edge(const vertex &v);

    void edit_edge(const vertex &v, int value);

    std::forward_list<edge>::iterator first();

    static std::forward_list<edge>::iterator next(const std::forward_list<edge>::iterator &from);

    friend std::ostream &operator<<(std::ostream &os, vertex &v);

    std::forward_list<edge>::iterator end();
};
