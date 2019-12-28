//
// Created by 郑驰骋 on 2019/12/27.
//
#include <iostream>
// template metaprogramming是编写template-based C++程序并执行与编译器的过程
// advance用来将某个迭代器移动某个给定距离
template<typename IterT, typename DistT>
void advanceBad(IterT &iter, DistT d) {
    // if iter is a random access iterator
    // 但是有个问题，会把本可以在编译期间就完成的事情延迟到运行期间
    if (typeid(typename std::iterator_traits<IterT>::iterator_category) == typeid(std::random_access_iterator_tag)) {
        iter += d;
    } else {
        if (d >= 0) {
            while (d--) {
                ++iter;
            }
        } else {
            while (d++) {
                --iter;
            }
        }
    }
}