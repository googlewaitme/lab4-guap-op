//
// Created by bulat on 23.11.22.
//

#include <iostream>
#include <cassert>


template<typename T>
MyVector<T>::MyVector()
{
    _allocated_memory = 0;
    _size = 0;
    _array = nullptr;
}

template<typename T>
MyVector<T>::MyVector(std::size_t size)
{
    _allocated_memory = size + size / 2;
    _array = new T[_allocated_memory];
    _size = size;
}

template<typename T>
MyVector<T>::MyVector(std::size_t size, T default_value): MyVector(size)
{
    for (int i=0; i < _size; i++)
        _array[i] = default_value;
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete [] _array;
}

template<typename T>
T& MyVector<T>::operator [](std::size_t idx)
{
    assert((idx >= 0) && (idx < _size));
    return _array[idx];
}

template<typename T>
std::size_t MyVector<T>::size() { return _size; }

template<typename T>
std::size_t MyVector<T>::allocated_memory_size() { return _allocated_memory; }

template<typename T>
void MyVector<T>::resize(std::size_t new_size)
{
    resize(new_size, T());
}

template<typename T>
void MyVector<T>::resize(std::size_t new_size, T default_value)
{
    std::size_t old_size = _size;
    resize_memory(new_size);
    for (int i=old_size; i < new_size; i++)
        _array[i] = default_value;
    _size = new_size;
}

template<typename T>
void MyVector<T>::resize_memory(const std::size_t new_size) {
    if ((new_size * 2 > _allocated_memory) && (new_size <= _allocated_memory))
        return;

    size_t new_allocated_memory = new_size + new_size / 2;
    T *new_array = new T[new_allocated_memory];
    for (int i = 0; (i < _size) && (i < new_allocated_memory); i++)
        new_array[i] = _array[i];

    delete[] _array;
    _array = new_array;
    _allocated_memory = new_allocated_memory;
    new_array = nullptr;
}

template<typename T>
bool MyVector<T>::empty() { return _size == 0; }


template<typename T>
void MyVector<T>::push_back(T new_element)
{
    resize(_size+1, new_element);
}

template<typename T>
T MyVector<T>::pop_back()
{
    resize(_size-1);
    return _array[_size];
}

template<typename T>
void MyVector<T>::insert(T new_element)
{
    insert(0, 1, new_element);
}

template<typename T>
void MyVector<T>::insert(std::size_t start_index, std::size_t count_elements, T default_element)
{
    std::size_t old_size = _size;
    resize(_size+count_elements);
    for (int i=old_size-1; i >= 0; i--) {
        _array[i + count_elements] = _array[i];
    }
    for (int i=0; i < count_elements; i++) {
        _array[i] = default_element;
    }
}

template<typename T>
T MyVector<T>::back()
{
    assert(_size>0);
    return _array[_size-1];
}


template<typename T>
T MyVector<T>::front()
{
    assert(_size>0);
    return _array[0];
}


template<typename T>
T MyVector<T>::erase(std::size_t idx)
{
    assert((idx>=0) && (idx < _size) && (_size > 0));
    resize(_size-1);
    T deleted_element = _array[idx];
    for (int i=0; i < _size; i++)
    {
        if (i >= idx)
            _array[i] = _array[i+1];
    }
    return deleted_element;
}

template<typename T>
void MyVector<T>::clear()
{
    _size = 0;
    _allocated_memory = 0;
    delete [] _array;
    _array = nullptr;
}

template<typename T>
void MyVector<T>::swap_elements(std::size_t first_ind, std::size_t second_ind)
{
    T temp = _array[first_ind];
    _array[first_ind] = _array[second_ind];
    _array[second_ind] = temp;
}

template<typename T>
void MyVector<T>::print_data()
{
    for (int i=0; i < _size; i++)
    {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
