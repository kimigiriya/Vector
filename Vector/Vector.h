#pragma once

#include <iostream>
#include <locale.h>
#include <cstring>
#include <string>
#include <stdexcept>
#include <sstream>

template <typename T>
class Vector {
private:
    T* datatype;
    int size;

public:
    // Конструктор
    Vector(int n) : size(n) {
        if (n <= 0) {
            throw std::runtime_error("Размер вектора должен быть положительным.");
        }
        datatype = new T[n];
        if (datatype == nullptr) {
            throw std::runtime_error("Не удалось выделить память.");
        }
    }

    // Конструктор копирования
    Vector(const Vector& other) : size(other.size) {
        datatype = new T[size];
        if (datatype == nullptr) {
            throw std::runtime_error("Не удалось выделить память.");
        }
        std::memcpy(datatype, other.datatype, size * sizeof(T));
    }

    // Деструктор
    ~Vector() {
        delete[] datatype;
    }

    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] datatype;
            size = other.size;
            datatype = new T[size];
            std::memcpy(datatype, other.datatype, size * sizeof(T));
        }
        return *this;
    }

    // Оператор ввода
    friend std::istream& operator>>(std::istream& inside, Vector<T>& v) {
        for (int i = 0; i < v.size; ++i) {
            inside >> v.datatype[i];
        }
        return inside;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& outside, const Vector<T>& v) {
        for (int i = 0; i < v.size; ++i) {
            outside << v.datatype[i] << (i == v.size - 1 ? "" : " ");
        }
        return outside;
    }


    // Оператор сложения
    Vector operator+(const Vector& other) const {
        if (this->size != other.size) {
            throw std::runtime_error("Размеры векторов должны совпадать для сложения.");
        }
        Vector<T> result(size);
        for (int i = 0; i < size; ++i) {
            result.datatype[i] = this->datatype[i] + other.datatype[i];
        }
        return result;
    }

    // Оператор вычитания
    Vector operator-(const Vector& other) const {
        if (this->size != other.size) {
            throw std::runtime_error("Размеры векторов должны совпадать для вычитания.");
        }
        Vector<T> result(size);
        for (int i = 0; i < size; ++i) {
            result.datatype[i] = this->datatype[i] - other.datatype[i];
        }
        return result;
    }

    // Оператор умножения
    T operator*(const Vector& other) const {
        if (this->size != other.size) {
            throw std::runtime_error("Размеры векторов должны совпадать для умножения.");
        }
        T result = 0;
        for (int i = 0; i < size; ++i) {
            result += this->datatype[i] * other.datatype[i];
        }
        return result;
    }

    // Определение размера
    int getSize() const { return size; }

    // Определение данных (с const)
    const T* getData() const { return datatype; }

    // Определение данных (без const)
    T* getData() { return datatype; }
};

// Специализация для string: перешрузка оператора +
template <>
Vector<std::string> Vector<std::string>::operator+(const Vector<std::string>& other) const {
    if (size != other.size) {
        throw std::runtime_error("Векторы должны иметь одинаковый размер для объединения строк.");
    }
    Vector<std::string> result(size);
    for (int i = 0; i < size; ++i) {
        result.datatype[i] = datatype[i] + " " + other.datatype[i];
    }
    return result;
}

// Специализация для string: перешрузка оператора -
template <>
Vector<std::string> Vector<std::string>::operator-(const Vector<std::string>& other) const {
    throw std::runtime_error("Для переменных типа string не предусмотрен оператор вычитания.");
}

// Специализация для string: перешрузка оператора *
template <>
std::string Vector<std::string>::operator*(const Vector& other) const {
    throw std::runtime_error("Для переменных типа string не предусмотрен оператор умножения.");
}
