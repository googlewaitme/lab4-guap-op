//
// Created by bulat on 02.12.22.
//

#include "myvector.h"
#include "GnomSort.hpp"
#include "ShakeSort.hpp"
#include <random>

int randint(int max_size)
{
    return std::rand() % max_size;
}


void generateTest(MyVector<int> & vec, std::size_t vector_size, int max_integer=100)
{
    vec.clear();
    vec.resize(vector_size);

    int randi;
    for (int i=0; i < vector_size; i++) {
        randi = randint(max_integer);
        vec[i] = randi;
    }
}


void run_tests(MyVector<int> &vec)
{
    int n = vec.size();
    clock_t start_time, gnom_time, shake_time;
    MyVector<int> vec1(n);
    MyVector<int> vec2(n);
    for (int i=0; i<vec.size(); i++) {
        vec1[i] = vec[i];
        vec2[i] = vec[i];
    }

    start_time = clock();
    GnomSort(vec1);
    gnom_time = clock() - start_time;

    start_time= clock();
    ShakeSort(vec2);
    shake_time = clock() - start_time;
    std::cout << "count elements: " << vec.size() << std::endl;
    std::cout << "gnom_time: " << gnom_time << std::endl;
    std::cout << "shake_time: " << shake_time << std::endl;
}


void testGnomSort()
{
    int n = 100;
    MyVector<int> vec(n);

    for (int i=0; i < n; i++) {
        vec[i] = randint(10);
    }
    // vec.print_data();
    GnomSort(vec);
    // vec.print_data();
    for (int i=0; i < n-1; i++) {
        assert(vec[i] <= vec[i+1]);
    }
    std::cout << "GNOM SORT IS RIGHT" << std::endl;
}


void testShakeSort()
{
    int n = 100;
    MyVector<int> vec(n);

    for (int i=0; i < n; i++) {
        vec[i] = randint(10);
    }
    // vec.print_data();
    ShakeSort(vec);
    // vec.print_data();
    for (int i=0; i < n-1; i++) {
        assert(vec[i] <= vec[i+1]);
    }
    std::cout << "SHAKE SORT IS RIGHT" << std::endl;
}


void test()
{
    std::size_t n = 20;
    MyVector<int> vec(n);
    assert(vec.size() == n);
    n = 14;
    vec.resize(n);
    assert(vec.size() == n);

    n = 19;
    int default_value=60;
    vec.resize(n, default_value);
    assert(vec.size() == n);
    assert(vec.back() == default_value);
    for (int i=15; i<n; i++)
        assert(vec[i] == default_value);

    vec.clear();
    assert(vec.empty());
    assert(vec.allocated_memory_size() == 0);

    n = 8;
    vec.resize(n);
    assert(vec.size() == n);
    for (int i=0; i<n; i++)
        vec[i] = i;
    for (int i=0; i<n; i++)
        assert(vec[i] == i);


    std::size_t first_el=4, second_el=5;
    vec[first_el] = first_el + n;
    vec[second_el] = second_el + n;
    vec.swap_elements(4, 5);
    assert(vec[second_el] == first_el+n);
    assert(vec[first_el] == second_el+n);

    assert(vec.front() == 0);
    assert(vec.back() == 7);

    int deleted_element = vec.erase(first_el);
    assert(deleted_element == second_el+n);
    assert(vec.size() == n - 1);

    vec.push_back(100);
    assert(vec.size() == n);
    assert(vec.back() == 100);
    assert(vec[n-1] == 100);


    deleted_element = vec.pop_back();
    assert(deleted_element == 100);
    assert(vec.size() == n-1);
    assert(vec.back() == 7);




    int count_of_new_elements=5;
    n = vec.size();
    vec.insert(0, count_of_new_elements, -10);
    assert(vec.size() == n+count_of_new_elements);
    for (int i=0; i < 5; i++)
        assert(-10 == vec[i]);
    assert(vec.back() == 7);

    n = vec.size();
    vec.insert(10);
    assert(vec.size() == n+1);
    assert(vec.front() == 10);
    assert(vec.back() == 7);


    MyVector<int> test_vector(10, 10);
    for (int i=0; i < 10; i++)
        assert(test_vector[i] == 10);

    std::cout << "ALL TESTS ARE PASSED" << std::endl;
}
