#include <iostream>
#include "44/SquareMatrixBad.cpp"
#include "33/Derived33.cpp"

void Task33();
void Task44();

int main() {
    std::cout << "Hello, World!" << std::endl;

    Task33();
    // Task44();
    return 0;



}

void Task33() {
    Derived1* d = new Derived1;
    d->mf1();
    d->mf1(0);
    // 被Derived内的mf1()函数给遮掩了
    d->mf2();
    d->mf3();
    d->mf3(0);
    // 被Derived内的mf1()函数给遮掩了
    d->mf4();

// output:
//    Derived mf1()
//    Base mf2()
//    Base mf3()
//    Derived mf4()
//    Base mf2()

    Derived2* d2 = new Derived2;
    d2->mf1();
    // d2->mf1(0)
    // 被Derived内的mf1()函数给遮掩了
}


void Task44() {
    SquareMatrixBad<double, 5> sm1;
    sm1.invert();

    SquareMatrixBad<double, 10> sm2;
    sm2.invert();
    // 会具现化出两份invert 但除了常量5 10，两个函数的其他部分完全相同。这便是template引起的代码膨胀



    return;
}
