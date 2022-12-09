//
// Created by bulat on 02.12.22.
//


template<typename T>
void ShakeSort(MyVector<T> &vec, int &swap_count, int &ifes_count)
{
    std::size_t last_swap_idx = vec.size()-1;
    std::size_t right = vec.size() - 1;
    std::size_t left = 0;
    while (left < right) {
        for (std::size_t i=left; i < right; i++) {
            ifes_count++;
            if (vec[i] > vec[i+1]) {
                swap_count++;
                vec.swap_elements(i, i+1);
                last_swap_idx = i;
            }
        }
        right = last_swap_idx;
        for (std::size_t i=right; i > left; i--) {
            ifes_count++;
            if (vec[i] < vec[i-1]) {
                swap_count++;
                vec.swap_elements(i, i-1);
                last_swap_idx = i;
            }
        }
        left = last_swap_idx;
    }
}

