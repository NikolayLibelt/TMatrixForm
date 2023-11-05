#pragma once
#include <vector>


template <typename T>
class vector
{
private:
	int start;
	T* memory;
	int size;
public:
	vector(int size = 0, int start = 0)
	{
		this->size = size;
		this->start = start;
		memory = new T[size - start];
		for (int i = 0; i < size - start; i++)
		{
			memory[i] = T(0);
		}
	}

	~vector()
	{
		delete[] memory;
	}

	vector(const vector& other)
	{
		start = other.start;
		size = other.size;
		memory = new T[size - start];
		for (int i = 0; i < size - start; i++)
		{
			memory[i] = other.memory[i];
		}
	}

	vector& operator =(const vector& other)
	{
		if (size != other.size)
		{
			if (size != 0) delete[] memory;

			size = other.size;
			memory = new T[size];
		}

		start = other.start;

		for (int i = 0; i < size - start; i++)
		{
			memory[i] = other.memory[i];
		}

		return *this;
	}

	vector operator +(const vector& other) const
	{
		vector result(*this);

		T* newMemory = new T[size];

		if (size == other.size && start == other.start)
		{
			for (int i = 0; i < size - start; i++) newMemory[i] = memory[i] + other.memory[i];
			result.memory = newMemory;
		}
		return result;
	}

	vector operator -(const vector& other) const
	{
		vector result(*this);

		T* newMemory = new T[size];

		if (size == other.size && start == other.start)
		{
			for (int i = 0; i < size - start; i++) newMemory[i] = memory[i] - other.memory[i];
			result.memory = newMemory;
		}
		return result;
	}

	T operator *(const vector& other) const
	{
		T result(0);
		if (size == other.size && start == other.start)
		{
			for (int i = 0; i < size - start; i++) result += memory[i] * other.memory[i];
		}

		return result;
	}

	vector operator *(int k) const
	{
		vector result(*this);

		T* newMemory = new T[size];

		for (int i = 0; i < size - start; i++) newMemory[i] = memory[i] * k;

		result.memory = newMemory;

		return result;
	}

	T& operator [](int k)
	{
		T res(0);
		if ((k >= start) && (k < size))
		{
			return memory[k - start];
		}
		return res;
	}
};