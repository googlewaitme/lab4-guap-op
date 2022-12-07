//
// Created by bulat on 02.12.22.
//


template<typename T>
void ShakeSort(MyVector<T> & vec) {
    std::size_t last_swap_idx = vec.size()-1;
    std::size_t right = vec.size() - 1;
    std::size_t left = 0;
    while (left < right) {
        for (std::size_t i=left; i < right; i++) {
            if (vec[i] > vec[i+1]) {
                vec.swap_elements(i, i+1);
                last_swap_idx = i;
            }
        }
        right = last_swap_idx;
        for (std::size_t i=right; i > left; i--) {
            if (vec[i] < vec[i-1]) {
                vec.swap_elements(i, i-1);
                last_swap_idx = i;
            }
        }
        left = last_swap_idx;
    }
}

