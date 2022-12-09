#include <iostream>
#include <ctime>
#include "test.cpp"



int main() {
    std::srand(std::time(nullptr));
    // test();
    // testShakeSort();
    //testGnomSort();


    std::vector<int> tests={100, 1000, 10000, 20000, 40000};
    std::cout << "random_tests" << std::endl;
    MyVector<int> vec;
    for (auto test: tests) {
        generateTest(vec, test);
        run_tests(vec);
        std::cout << "####" << std::endl;
        vec.clear();
    }
    std::cout << "bad tests" << std::endl;
    for (auto test: tests) {
        for (int i=test-1; i >= 0; i--) {
            vec.push_back(i);
        }
        run_tests(vec);
        vec.clear();
    }
    std::cout << "good tests" << std::endl;
    for (auto test: tests) {
        for (int i=0; i < test; i++) {
            vec.push_back(i);
        }
        run_tests(vec);
        vec.clear();
    }

    return 0;
}
