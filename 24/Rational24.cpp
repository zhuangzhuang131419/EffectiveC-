//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>
class RationalBad {
public:
    RationalBad(int numerator = 0, int denominator = 1) {}
    int numerator() const {
        return 0;
    }
    int denominator() const {
        return 0;
    }

    RationalBad operator* (const RationalBad& rhs) const {
        RationalBad r;
        return r;
    }
};

class Rational1 {
public:
    Rational1(int numerator = 0, int denominator = 1) {}
    int numerator() const {
        return 0;
    }
    int denominator() const {
        return 0;
    }

    friend Rational1 operator * (const Rational1& lhs, const Rational1& rhs) {
        return {lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator()};
    }
};


