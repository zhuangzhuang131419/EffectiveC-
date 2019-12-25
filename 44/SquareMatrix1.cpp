//
// Created by 郑驰骋 on 2019/12/25.
//
#include <iostream>
template <typename T> // template 支持元素是类型为T的objects
class SquareMatrixBase {
protected:
    void invert(std::size_t matrixSize); //以给定的尺寸求逆
};

template <typename T, std::size_t n> // template 支持n * n矩阵，元素是类型为T的objects
class SquareMatrix1: private SquareMatrixBase<T> {
private:
    using SquareMatrixBase<T>::invert; // 避免遮掩base版的invert
public:
    void invert() {
        this->invert(n);
    }
};
