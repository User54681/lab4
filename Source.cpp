//#include "Source.h"
//#include <ctime>
//
//template <typename T>
//matrix<T>::matrix() {
//    m = 3;
//    n = 3;
//    data = new int* [m];
//    for (int i = 0; i < m; ++i) data[i] = new int[n];
//}
//
//template <typename T>
//matrix<T>::matrix(unsigned int m, unsigned int n) {
//    this->m = m;
//    this->n = n;
//    data = new int* [m];
//    for (int i = 0; i < m; ++i) data[i] = new int[n];
//}
//
//template <typename T>
//matrix<T>::~matrix() {
//    for (int i = 0; i < m; ++i) {
//        delete[] data[i];
//    }
//    delete[] data;
//}
//
//template <typename T>
//void matrix<T>::random() {
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            data[i][j] = rand() % 10;
//        }
//    }
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const matrix<T>& mat) {
//    for (unsigned int i = 0; i < mat.m; ++i) {
//        for (unsigned int j = 0; j < mat.n; ++j) {
//            os << mat.data[i][j] << " ";
//        }
//        os << "\n";
//    }
//    return os;
//}
//
//template <typename T>
//matrix<T> matrix<T>::operator +(const matrix<T>& other) {
//    if (m == other.m and n == other.n) {
//        matrix result(m, n);
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                result.data[i][j] = data[i][j] + other.data[i][j];
//            }
//        }
//        return result;
//    }
//    else std::cout << "Нельзя посчитать сумму матриц" << "\n";
//}
//
//template <typename T>
//matrix<T>& matrix<T>::operator +=(const matrix<T>& other) {
//    if (m == other.m and n == other.n) {
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                data[i][j] += other.data[i][j];
//            }
//        }
//        std::cout << *this << "\n";
//        return *this;
//    }
//    else std::cout << "Нельзя прибавить одну матрицу к другой" << "\n";
//}
//
//template <typename T>
//matrix<T> matrix<T>::operator -(const matrix<T>& other) {
//    if (m == other.m and n == other.n) {
//        matrix result(m, n);
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                result.data[i][j] = data[i][j] - other.data[i][j];
//            }
//        }
//        return result;
//    }
//    else std::cout << "Нельзя посчитать разность матриц" << "\n";
//}
//
//template <typename T>
//matrix<T>& matrix<T>::operator -=(const matrix<T>& other) {
//    if (m == other.m and n == other.n) {
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                data[i][j] -= other.data[i][j];
//            }
//        }
//        std::cout << *this << "\n";
//        return *this;
//    }
//    else std::cout << "Нельзя вычесть из одной матрицы другую" << "\n";
//}
//
//template <typename T>
//matrix<T> matrix<T>::operator *(const matrix<T>& other) {
//    if (m == other.n) {
//        matrix result(m, other.n);
//        for (unsigned int i = 0; i < m; ++i) {
//            for (unsigned int j = 0; j < other.n; ++j) {
//                result.data[i][j] = 0;
//                for (unsigned int k = 0; k < n; ++k) {
//                    result.data[i][j] += data[i][k] * other.data[k][j];
//                }
//            }
//        }
//        return result;
//    }
//    else std::cout << "Невозможно посчитать произведение матриц" << "\n";
//}
//
//template <typename T>
//bool matrix<T>::operator ==(const matrix<T>& other) const {
//    if (m != other.m || n != other.n) return false;
//
//    for (unsigned int i = 0; i < m; ++i) {
//        for (unsigned int j = 0; j < n; ++j) {
//            if (data[i][j] != other.data[i][j]) return false;
//        }
//    }
//
//    return true;
//}
//
//template <typename T>
//bool matrix<T>::operator !=(const matrix<T>& other) const {
//    return !(*this == other);
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//template <typename T>
//void Vector<T>::random() {
//    for (size_t i = 0; i < data.size(); ++i) {
//        data[i] = static_cast<T>(rand() % 10);
//    }
//}
//
//template <typename T>
//T Vector<T>::dotProduct(const Vector<T>& other) {
//    if (data.size() != other.data.size()) {
//        std::cout << "Cannot calculate dot product of vectors with different sizes" << "\n";
//        return static_cast<T>(0);
//    }
//
//    T result = static_cast<T>(0);
//    for (size_t i = 0; i < data.size(); ++i) {
//        result += data[i] * other.data[i];
//    }
//
//    return result;
//}
//
//template <typename T>
//Vector<T> Vector<T>::crossProduct(const Vector<T>& other) {
//    if (data.size() != 3 || other.data.size() != 3) {
//        std::cout << "Cross product is only defined for 3-dimensional vectors" << "\n";
//        return Vector<T>();
//    }
//
//    Vector<T> result;
//    result.data = {
//        data[1] * other.data[2] - data[2] * other.data[1],
//        data[2] * other.data[0] - data[0] * other.data[2],
//        data[0] * other.data[1] - data[1] * other.data[0]
//    };
//
//    return result;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
//    for (const T& elem : vec.data) {
//        os << elem << " ";
//    }
//    return os;
//}