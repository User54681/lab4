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
    /*func<int>();
    std::cout << "\n";
    func<char>();
    std::cout << "\n";
    func<double>();
    std::cout << "\n";
    func<float>();
    std::cout << "\n";*/

    matrix<float> mat1(2, 3);
    mat1.random();

    matrix<float> mat2(2, 3);
    mat2.random();

    std::cout << "Матрица 1:" << "\n" << mat1;
    std::cout << "Матрица 2:" << "\n" << mat2;

    std::cout << "Сумма матриц:" << "\n";
    matrix<float> sum = mat1 + mat2;
    std::cout << sum << "\n";

    std::cout << "Матрица 1 после прибавления к ней матрицы 2:" << "\n";
    mat1 += mat2;

    std::cout << "Разница матриц:" << "\n";
    matrix<float> diff = mat1 - mat2;
    std::cout << diff << "\n";

    std::cout << "Матрица 1 после вычитания из нее матрицы 2:" << "\n";
    mat1 -= mat2;

    std::cout << "Произведение матриц:" << "\n";
    matrix<float> prod = mat1 * mat2;
    std::cout << prod << "\n";

    if (mat1 == mat2) {
        std::cout << "Матрица 1 тождественна матрице 2." << "\n";
    }
    else {
        std::cout << "Матрица 1 не тождественна матрице 2." << "\n";
    }

    if (mat1 != mat2) {
        std::cout << "Матрица 1 не равняется матрице 2." << "\n";
    }
    else {
        std::cout << "Матрица 1 равняется матрице 2." << "\n";
    }
}
//
//template <typename T>
//T Second_Max(const T* arr, int size) {
//    if (size < 2) {
//        std::cout << "Размер массива должен быть не менее двух" << "\n";
//        return T();
//    }
//
//    int max = 0, second_max = 0;
//    std::vector <T> vec(arr, arr + size);
//
//    for (int i = 0; i < size; ++i) {
//        if (vec[i] > vec[max]) {
//            max = i;
//        }
//    }
//
//    vec.erase(vec.begin() + max);
//
//    for (int i = 0; i < vec.size(); ++i) {
//        if (vec[i] > vec[second_max]) {
//            second_max = i;
//        }
//    }
//
//    return (second_max != -1) ? vec[second_max] : T();
//}
//
//template <typename T>
//void func() {
//    srand(time(0));
//    int size = 0;
//    std::cout << "Введите размер массива: " << "\n";
//    std::cin >> size;
//    std::vector <T> array(size);
//    for (int i = 0; i < size; ++i) array[i] = static_cast<T>(rand()%100);
//    for (int i = 0; i < size; ++i) std::cout << array[i] << "\t";
//    std::cout << "\n";
//
//    T second_max = Second_Max(&array[0], size);
//    std::cout << "Второй максимум данного массива: " << second_max << "\n";
//}