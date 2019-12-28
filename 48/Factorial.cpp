//
// Created by 郑驰骋 on 2019/12/27.
//
template <unsigned n>
struct Factorial {
    enum {
        value = n * Factorial<n-1>::value
    };
};

template <>
struct Factorial<0> {
    enum {
        value = 1
    };
};


