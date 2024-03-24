#include "Source.h"
#include <iostream>
#include <vector>
#include <ctime>

template <typename T>
T Second_Max(const T* arr, int size);
template <typename T>
void func();

int main()
{    
    setlocale(LC_ALL, "Rus");
    func<int>();
    std::cout << "\n";
    func<char>();
    std::cout << "\n";
    func<double>();
    std::cout << "\n";
    func<float>();
    std::cout << "\n";
}

template <typename T>
T Second_Max(const T* arr, int size) {
    if (size < 2) {
        std::cout << "Размер массива должен быть не менее двух" << "\n";
        return T();
    }

    int max = 0, second_max = -1;
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] > arr[max]) {
            second_max = max;
            max = i;
        }
    }

    return (second_max != -1) ? arr[second_max] : T();
}

template <typename T>
void func() {
    srand(time(0));
    int size = 0;
    std::cout << "Введите размер массива: " << "\n";
    std::cin >> size;
    std::vector <T> array(size);
    for (int i = 0; i < size; ++i) {
        if constexpr (std::is_floating_point<T>::value) {
            array[i] = static_cast<T>(rand()) / RAND_MAX;
        }
        else {
            array[i] = static_cast<T>(rand());
        }
    }
    for (int i = 0; i < size; ++i) std::cout << array[i] << "\t";
    std::cout << "\n";

    T second_max = Second_Max(&array[0], size);
    std::cout << "Второй максимум данного массива: " << second_max << "\n";
}