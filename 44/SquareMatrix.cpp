//
// Created by 郑驰骋 on 2019/12/25.
//
#include <iostream>
#include <boost/scoped_array.hpp>
// version 1:
template <typename T, std::size_t n> // template 支持n * n矩阵，元素是类型为T的objects
class SquareMatrixBad {
public:
    void invert() {
        std::cout << "SquareMatrixBad invert" << std::endl;
    }
};

// version 2:
template <typename T>
class SquareMatrixBaseBad {
protected:
    void invert(std::size_t matrixSize) {
        // 以给定的尺寸求逆矩阵
        std::cout << "SquareMatrixBaseBad invert" << std::endl;
    }
};

template <typename T, std::size_t n> // template 支持n * n矩阵，元素是类型为T的objects
class SquareMatrix1Bad: private SquareMatrixBaseBad<T> {
private:
    using SquareMatrixBaseBad<T>::invert; // 避免遮掩base版的invert (33)
public:
    void invert() {
        this->invert(n); // (43)
    }
};

// version 3:
template <typename T>
class SquareMatrixBase {
protected:
    SquareMatrixBase(std::size_t n, T* pMem): size(n), pData(pMem) { }
    void setDataPtr(T* ptr) { pData = ptr; }

private:
    std::size_t size;
    T* pData; // 储存一个指针，指向矩阵数值所在的内存
};

template <typename T, std::size_t n>
class SquareMatrix1: private SquareMatrixBase<T> {
public:
    SquareMatrix1(): SquareMatrixBase<T>(n, data) { }

private:
    T data[n * n];
};

// version 4:
template <typename T, std::size_t n>
class SquareMatrix2: private SquareMatrixBase<T> {
public:
    SquareMatrix2(): SquareMatrixBase<T>(n, 0), pData(new T[n * n]) {
        this->setDataPtr(pData.get());
    }

private:
    boost::scoped_array<T> pData;
};

