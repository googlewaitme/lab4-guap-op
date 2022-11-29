//
// Created by bulat on 23.11.22.
//

#ifndef LAB4_MYVECTOR_H
#define LAB4_MYVECTOR_H

template <typename T>
class MyVector
{
private:
    T *_array;
    std::size_t _size;
    std::size_t _allocated_memory;

    void resize_memory(size_t);
public:
    MyVector();
    MyVector(std::size_t);
    MyVector(std::size_t, T);
    ~MyVector();
    T & operator[] (std::size_t);
    std::size_t size();
    std::size_t allocated_memory_size();
    void resize(std::size_t);
    void resize(std::size_t, T);
    bool empty();
    void push_back(T);
    T pop_back();
    void insert(T);
    void insert(std::size_t, std::size_t, T);
    T front();
    T back();
    T erase(std::size_t idx);
    void clear();
    void swap_elements(std::size_t, std::size_t);
    void print_data();
};

#include "myvector.tcc"
#endif //LAB4_MYVECTOR_H
