#pragma once
#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cassert>

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cols);

	int rows() const;
	int cols() const;
	double det() const;

	Matrix<T>& initialize(T value);
	Matrix<T>& transpose();

	T& operator()(int row, int col);
	const T& operator()(int row, int col) const;

	~Matrix();
private:
	int _rows;
	int _cols;

	T** _matrix;

	T**  alloc(int rows, int cols);
	void destroy();
};

typedef Matrix<int>   Matrixi;
typedef Matrix<float> Matrixf;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
{
	for (auto i = 0; i < m.rows(); ++i)
	{
		for (auto j = 0; j < m.cols(); ++j)
			os << m(i, j) << " ";

		os << std::endl;
	}

	return os;
}

template<typename T>
inline Matrix<T>::Matrix(int rows, int cols)
{
	assert(rows > 0);
	assert(cols > 0);
	_rows = rows;
	_cols = cols;

	_matrix = new T*[rows];
	for (auto i = 0; i < rows; ++i)
		_matrix[i] = new T[cols];
	/*for (auto j = 0; j < cols; ++j)
	_matrix[i][j] = default(T);*/
}

template<typename T>
inline int Matrix<T>::rows() const
{
	return _rows;
}

template<typename T>
inline int Matrix<T>::cols() const
{
	return _cols;
}

template<typename T>
inline double Matrix<T>::det() const
{
	return 0.0;
}

template<typename T>
inline Matrix<T>& Matrix<T>::initialize(T value)
{
	for (auto i = 0; i < _rows; ++i)
		for (auto j = 0; j < _cols; ++j)
			_matrix[i][j] = value;

	return(*this);
}

template<typename T>
inline Matrix<T>& Matrix<T>::transpose()
{
	if (_cols == _rows)
	{
		for (int i = 0; i < _rows; ++i)
			for (int j = i + 1; j < _cols; ++j)
				std::swap(_matrix[i][j], _matrix[j][i]);
	}
	else
	{
		auto matrix_trans = alloc(_cols, _rows);
		for (int i = 0; i < _rows; ++i)
			for (int j = i + 1; j < _cols; ++j)
				matrix_trans[j][i] = _matrix[i][j];
		destroy();

		std::swap(_rows, _cols);
		_matrix = matrix_trans;
	}
	return(*this);
}

template<typename T>
inline T & Matrix<T>::operator()(int row, int col)
{
	assert(row >= 0 && row < _rows);
	assert(col >= 0 && col < _cols);

	return _matrix[row][col];
}

template<typename T>
inline const T&  Matrix<T>::operator()(int row, int col) const
{
	assert(row >= 0 && row < _rows);
	assert(col >= 0 && col < _cols);

	return _matrix[row][col];
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	destroy();
}

template<typename T>
inline T ** Matrix<T>::alloc(int rows, int cols)
{
	T** _matrix_tmp = new T*[rows];
	for (auto i = 0; i < rows; ++i)
		_matrix_tmp[i] = new T[cols];

	return _matrix_tmp;
}

template<typename T>
inline void Matrix<T>::destroy()
{
	for (auto i = 0; i < _rows; ++i)
		delete[] _matrix[i];

	delete _matrix;
}

#endif // !_MATRIX_H_
