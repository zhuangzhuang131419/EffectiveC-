#include <iostream>
#include "33/Derived33.cpp"
#include "39/Student.cpp"
#include "39/Empty.cpp"
#include "43/Company.cpp"
#include "44/SquareMatrix.cpp"

void Task33();
void Task39();
void eat(const Person& p);
void study(const Student& s);
void Task43();
void Task44();

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Task33();
    // Task39();
    // Task43();
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
void Task39() {
    Person p;
    Student s;
    eat(p);
    // eat(s);  编译错误
    // 如果classes之间的继承关系是private, 编译器不会自动将Student转换成Person
    // 由Person继承来的所有成员，在student中都会变成private属性

    std::cout << sizeof(int) << std::endl;
    std::cout << "holds an int 1: " << sizeof(HoldsAnInt1) << std::endl;
    std::cout << "holds an int 2: " << sizeof(HoldsAnInt2) << std::endl;
    // output:
    // holds an int 1: 8
    // holds an int 2: 4
    // 通常C++会默默暗查一个char到空对象中，再加上alignment的需求
}
void eat(const Person& p) {
    std::cout << "eat" << std::endl;
}
void study(const Student& s) {
    std::cout << "study" << std::endl;
}

void Task43() {
    LoggingMsgSender1<CompanyZ> zMsgSender1;
    // LoggingMsgSender2<CompanyZ> zMsgSender2; 编译错误
    // LoggingMsgSender3<CompanyZ> zMsgSender3; 编译错误
    MsgInfo msgData;
    // zMsgSender1.sendClearMsg(msgData); 无法通过编译
}

void Task44() {
    SquareMatrixBad<double, 5> sm1;
    sm1.invert();

    SquareMatrixBad<double, 10> sm2;
    sm2.invert();
    // 会具现化出两份invert 但除了常量5 10，两个函数的其他部分完全相同。这便是template引起的代码膨胀



    return;
}
