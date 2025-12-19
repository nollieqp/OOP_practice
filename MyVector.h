#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    T* array;
    int size;
    int capacity;

public:
    Vector() {
        capacity = 10;
        size = 0;
        array = new T[capacity];
    }


    ~Vector() {
        delete[] array;
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }


    void push_back(T element) {
        if (size == capacity) {

            capacity *= 2;
            T* newArray = new T[capacity];


            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
        }
        array[size] = element;
        size++;
    }


    void pop_back() {
        if (size > 0) {
            size--;
        }
    }


    T at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }


    T& operator[](int index) {
        return array[index];
    }
};