//
// Created by bulat on 02.12.22.
//

#include <chrono>
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
    MyVector<int> vec1(n);
    MyVector<int> vec2(n);
    for (int i=0; i<vec.size(); i++) {
        vec1[i] = vec[i];
        vec2[i] = vec[i];
    }

    int gnom_swaps = 0, shake_swaps=0;
    int gnom_ifes = 0, shake_ifes=0;


    auto begin = std::chrono::steady_clock::now();
    GnomSort(vec1, gnom_swaps, gnom_ifes);
    auto end = std::chrono::steady_clock::now();
    auto gnom_time = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

    begin = std::chrono::steady_clock::now();
    ShakeSort(vec2, shake_swaps, shake_ifes);
    end = std::chrono::steady_clock::now();
    auto shake_time = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);

    std::cout << "count elements: " << vec.size() << std::endl;
    std::cout << "gnom " << gnom_time.count() << " " << gnom_swaps << " " << gnom_ifes << std::endl;
    std::cout << "shake " << shake_time.count() << " " << shake_swaps << " " << shake_ifes << std::endl;
}


void testGnomSort()
{
    int n = 100;
    MyVector<int> vec(n);

    for (int i=0; i < n; i++) {
        vec[i] = randint(10);
    }
    // vec.print_data();
    int ifes_count=0, swap_count=0;
    GnomSort(vec, ifes_count, swap_count);
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
    int ifes_count=0, swap_count=0;
    ShakeSort(vec, ifes_count, swap_count);
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
