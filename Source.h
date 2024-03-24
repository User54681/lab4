#pragma once
#ifndef source
#include <iostream>

template <typename T>
class matrix {
private:	
	T** data;
	unsigned int m, n; //m - rows, n - columns
public:
	matrix();
	matrix(unsigned int m, unsigned int n);
	~matrix();
	void random();
	friend std::ostream& operator <<(std::ostream& os, const matrix<T>& mat);
	matrix<T> operator+(const matrix<T>& other);
	matrix<T>& operator+=(const matrix<T>& other);
	matrix<T> operator-(const matrix<T>& other);
	matrix<T>& operator-=(const matrix<T>& other);
	matrix<T> operator*(const matrix<T>& other);
	bool operator ==(const matrix<T>& other) const;
	bool operator !=(const matrix<T>& other) const;
};

#endif // !source

