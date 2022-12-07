//
// Created by bulat on 02.12.22.
//

#include "myvector.h"


template <typename T>
void GnomSort(MyVector<T> &vec)
{
    std::size_t sorted=2, index=1;
    while (index < vec.size()) {
        if (vec[index] > vec[index-1]) {
            index = sorted;
            sorted++;
        } else {
            vec.swap_elements(index, index-1);
            index--;
            if (index == 0) {
                index = sorted;
                sorted++;
            }
        }
    }
}