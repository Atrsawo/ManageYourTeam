#pragma once

template <class T>

class Array {
protected:
	T* storage;
	int storageCount;
public:
    Array(int size);
    ~Array();
    T& operator [](int index);
    class InsufficientMemory { };
    class IndexOutOfRange { };
};