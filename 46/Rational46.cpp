//
// Created by 郑驰骋 on 2019/12/27.
//
#include <iostream>

template<typename T>
class Rational2 {
public:
    Rational2(const T &numerator = 0, const T &denominator = 1) {}

    T numerator() const {}

    T denominator() const {}
};

template<typename T>
Rational2<T> operator*(const Rational2<T> &lhs, const Rational2<T> &rhs) {
    return {lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator()};
}

template<typename T>
class Rational3 {
public:
    Rational3(const T &numerator = 0, const T &denominator = 1) {
        Numerator = numerator;
        Denominator = denominator;
    }

    T numerator() const {
        return Numerator;
    }

    T denominator() const {
        return Denominator;
    }

    friend Rational3<T> operator*(const Rational3<T> &lhs, const Rational3<T> &rhs) {
        return Rational3(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
    }

private:
    T Numerator;
    T Denominator;
};

template<typename T>
Rational3<T> operator*(const Rational3<T> &lhs, const Rational3<T> &rhs) {}
