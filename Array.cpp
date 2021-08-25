#include "Array.h"

    template <class T>
    Array<T>::Array(int size)
    {
        storage = new T[size];
        storageCount = size;
    }

    template <class T>
    Array<T>::~Array()
    {
        delete[] storage;
    }

    template<class T>
    T& Array<T>::operator [](int index)
    {
        if (index < 0) {
            throw IndexOutOfRange();
        }
        if (index < storageCount) {
            return storage[index];
        }

        int newStorageCount = (index + 1) + storageCount / 2;
        T* newStorage = new T[newStorageCount];
        memmove(newStorage, storage, sizeof(T) * storageCount);
        delete[] storage;
        storage = newStorage;
        storageCount = newStorageCount;
        return storage[index];
    }
