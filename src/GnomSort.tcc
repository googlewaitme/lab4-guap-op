//
// Created by bulat on 02.12.22.
//

#include "myvector.h"


template <typename T>
void GnomSort(MyVector<T> &vec, int &changes_count, int &ifes_count)
{
    std::size_t sorted=2, index=1;
    while (index < vec.size()) {
        ifes_count++;
        if (vec[index] > vec[index-1]) {
            index = sorted;
            sorted++;
        } else {
            changes_count++;
            vec.swap_elements(index, index-1);
            index--;
            ifes_count++;
            if (index == 0) {
                index = sorted;
                sorted++;
            }
        }
    }
}