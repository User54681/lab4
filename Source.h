#pragma once
#ifndef source
#include <iostream>
#include <ctime>

template <typename T>
class matrix {
private:	
	T** data;
	unsigned int m, n; //m - rows, n - columns
public:
	matrix() {
        m = 3;
        n = 3;
        data = new T * [m];
        for (int i = 0; i < m; ++i) data[i] = new T[n];
    };
	matrix(unsigned int m, unsigned int n) {
        this->m = m;
        this->n = n;
        data = new T * [m];
        for (int i = 0; i < m; ++i) data[i] = new T[n];
    };
	~matrix() {
        for (int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    };
	void random() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = rand() % 10;
            }
        }
    };
	friend std::ostream& operator <<(std::ostream& os, const matrix<T>& mat) {
        for (unsigned int i = 0; i < mat.m; ++i) {
            for (unsigned int j = 0; j < mat.n; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    };
	matrix<T> operator+(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            matrix result(m, n);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }
        else std::cout << "������ ��������� ����� ������" << "\n";
    };
	matrix<T>& operator+=(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    data[i][j] += other.data[i][j];
                }
            }
            std::cout << *this << "\n";
            return *this;
        }
        else std::cout << "������ ��������� ���� ������� � ������" << "\n";
    };
	matrix<T> operator-(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            matrix result(m, n);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            return result;
        }
        else std::cout << "������ ��������� �������� ������" << "\n";
    };
	matrix<T>& operator-=(const matrix<T>& other) {
        if (m == other.m and n == other.n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    data[i][j] -= other.data[i][j];
                }
            }
            std::cout << *this << "\n";
            return *this;
        }
        else std::cout << "������ ������� �� ����� ������� ������" << "\n";
    };
	matrix<T> operator*(const matrix<T>& other) {
        if (m == other.n) {
            matrix result(m, other.n);
            for (unsigned int i = 0; i < m; ++i) {
                for (unsigned int j = 0; j < other.n; ++j) {
                    result.data[i][j] = 0;
                    for (unsigned int k = 0; k < n; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
        else std::cout << "���������� ��������� ������������ ������" << "\n";
    };
	bool operator ==(const matrix<T>& other) const {
        if (m != other.m || n != other.n) return false;

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) return false;
            }
        }

        return true;
    };
	bool operator !=(const matrix<T>& other) const {
        return !(*this == other);
    };
};

template <typename T>
class Vec {
private:
    std::vector <T> data;
public:
    vector() {
        
    }
    vector(const std::vector<T>& vec) : data(vec) {}
    void random() {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = static_cast<T>(rand() % 10);
        }
    };
    T Dot_Product(const vector<T>& other) {
        if (data.size() != other.data.size()) {
            std::cout << "���������� ��������� ��������� ������������ ��������" << "\n";
            return static_cast<T>(0);
        }

        T result = static_cast<T>(0);
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] * other.data[i];
        }

        return result;
    };
    vector<T> Cross_Product(const vector<T>& other) {
        if (data.size() != 3 || other.data.size() != 3) {
            std::cout << "��������� ����������� �������� ������ �����, ����� ������� �������� ������ ������" << "\n";
            return Vector<T>();
        }

        Vector<T> result;
        result.data = {
            data[1] * other.data[2] - data[2] * other.data[1],
            data[2] * other.data[0] - data[0] * other.data[2],
            data[0] * other.data[1] - data[1] * other.data[0]
        };

        return result;
    };
    friend std::ostream& operator<<(std::ostream& os, const vector<T>& vec) {
        for (const T& elem : vec.data) {
            os << elem << " ";
        }
        return os;
    };
};

#endif // !source