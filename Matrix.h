#pragma once
#include <vector>
#include "vector.h"

template <typename T>
class matrix
{
private:
	vector <vector<T>> memory;
	int n;
	int m;
public:
	matrix(int n = 0, int m = 0)
	{
		this->n = n;
		this->m = m;
		memory = vector<vector<T>>(n, 0);

		for (int i = 0; i < n; i++)
		{
			memory[i] = vector<T>(m, i);
		}
	}

	~matrix() {};

	matrix(const matrix& other)
	{
		n = other.n;
		m = other.m;
		memory = other.memory;
	}

	matrix& operator =(const matrix& other)
	{
		n = other.n;
		m = other.m;
		memory = other.memory;

		return *this;
	}

	vector<T>& operator [](int k)
	{
		return memory[k];
	}

	matrix operator +(matrix& other)
	{
		matrix<T> result = matrix<T>();

		if (n != other.n || m != other.m) return result;

		result = matrix<T>(n, m);

		for (int i = 0; i < n; i++)
		{
			result[i] = memory[i] + other.memory[i];
		}

		return result;
	}

	matrix operator -(matrix& other)
	{
		matrix<T> result = matrix<T>();

		if (n != other.n || m != other.m) return result;

		result = matrix<T>(n, m);

		for (int i = 0; i < n; i++)
		{
			result[i] = memory[i] - other.memory[i];
		}

		return result;
	}

	matrix operator *(int k) const
	{
		matrix<T> result = matrix<T>(*result);

		for (int i = 0; i < n; i++)
		{
			result[i] = memory[i] * k;
		}

		return result;
	}

	matrix operator*(matrix& other)
	{
		matrix<T> result = matrix<T>();

		if (m != other.n) return result;

		result = matrix<T>(n, other.m);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < other.m; j++)
			{
				T tmp = 0;
				for (int k = 0; k < m; k++)
				{
					tmp += memory[i][k] * other.memory[k][j];
				}
				result[i][j] = tmp;
			}
		}

		return result;
	}

	matrix operator*(int k)
	{
		matrix<T> result = matrix<T>(n, m);

		for (int i = 0; i < n; i++)
		{
			result[i] = memory[i] * k;
		}

		return result;
	}
};