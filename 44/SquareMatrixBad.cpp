//
// Created by 郑驰骋 on 2019/12/25.
//
#include <iostream>
template <typename T, std::size_t n> // template 支持n * n矩阵，元素是类型为T的objects
class SquareMatrixBad {
public:
    void invert();
};

template<typename T, std::size_t n>
void SquareMatrixBad<T, n>::invert() {
    std::cout << "SuqareBadMatrix.invert()" << std::endl;
}
