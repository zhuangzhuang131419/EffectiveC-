//
// Created by 郑驰骋 on 2019/12/25.
//
#include <iostream>
class Base {
private:
    int x;
public:
    virtual void mf1() = 0;
    virtual void mf1(int) { std::cout << "Base mf1(int)" << std::endl; }
    virtual void mf2() { std::cout << "Base mf2()" << std::endl; }
    void mf3() { std::cout << "Base mf3()" << std::endl; }
    void mf3(double) { std::cout << "Base mf3(double)" << std::endl; }
};

class Derived1: public Base {
public:
    // 这两句声明可以避免mf1(int) mf3(double)被遮掩
    using Base::mf1;
    using Base::mf3;


    virtual void mf1() { std::cout << "Derived mf1()" << std::endl; }
    void mf3() { std::cout << "Derived mf3()" << std::endl; }
    void mf4() {
        std::cout << "Derived mf4()" << std::endl;
        mf2();
    }
};

class Derived2: private Base { // private继承 唯一想继承的mf1是那个无参的版本
public:
    virtual void mf1() { Base::mf1(0); } // forwarding function 转交函数
};