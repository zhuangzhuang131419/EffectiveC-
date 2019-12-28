#include <iostream>
#include <list>
#include "24/Rational24.cpp"
#include "25/Widget25.cpp"
#include "33/Derived33.cpp"
#include "39/Student.cpp"
#include "39/Empty.cpp"
#include "43/Company.cpp"
#include "44/SquareMatrix.cpp"
#include "45/SmartPtr.cpp"
#include "46/Rational46.cpp"
#include "48/advance48.cpp"
#include "48/Factorial.cpp"

void Task24();
void Task25();
template <typename T>
void doSwap(T& obj1, T& obj2);
void Task33();
void Task39();
void eat(const Person& p);
void study(const Student& s);
void Task43();
void Task44();
void Task45();
void Task46();
void Task48();

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Task24();
    // Task25();
    // Task33();
    // Task39();
    // Task43();
    // Task44();
    // Task45();
    // Task46();
    Task48();

    return 0;



}

void Task24() {
    RationalBad oneEighth(1, 8);
    RationalBad oneHalf(1, 2);
    RationalBad result = oneHalf * oneEighth;
    result = result * oneEighth;
    result = oneHalf * 2;
    // result = 2 * oneHalf; 编译错误

    Rational1 oneEighth1(1, 8);
    Rational1 oneHalf1(1, 2);
    // Rational1 result1 = 2 * oneHalf1;
}
void Task25() {
    Widget1 w1{};
    Widget1 w2{};
    doSwap(w1, w2);

    Widget_T<int> widgetT1;
    Widget_T<int> widgetT2;
    doSwap(widgetT1, widgetT2);

    WidgetStuff::Widget_T1<int> widgetT11;
    WidgetStuff::Widget_T1<int> widgetT12;
    doSwap(widgetT11, widgetT12);



}
template <typename T>
void doSwap(T& obj1, T& obj2) {
    using std::swap;
    swap(obj1, obj2);
    // std::swap(obj1, obj2) 编译通过 但是无法找到写在WidgetBuffer中的了
}
void Task33() {
    auto* d = new Derived1;
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

    auto* d2 = new Derived2;
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
}
void Task45() {
    // SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
    // SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
    // SmartPtr<const Top> pct2 = pt1;
    // 编译错误，不存在此种隐式转换
    shared_ptr1<Top> pt1 = shared_ptr1<Middle>(new Middle);
    shared_ptr1<Middle> pt2 = shared_ptr1<Bottom>(new Bottom);
    shared_ptr1<const Top> pct2 = pt1;
}
void Task46() {
    Rational2<int> oneHalf(1, 2);
    // Rational2<int> result = oneHalf * 2; 编译无法通过，模板化之后与之前的不同
    // template实参推导过程中从不讲隐式类型转换函数纳入考虑

    Rational3<int> onethird(1, 3);
    std::cout << onethird.numerator() << ", " << onethird.denominator() << std::endl;
    Rational3<int> result = onethird * 4;
    Rational3<int> result1 = 3 * onethird;
    std::cout << result.numerator() << ", " << result.denominator() << std::endl;
}
void Task48() {
    std::list<int>::iterator iter;
    // advanceBad(iter, 10); 运行报错，list<int>::iterator是bidirectional迭代器，并不支持+=
    std::cout << Factorial<5>::value << std::endl;
    std::cout << Factorial<10>::value << std::endl;
}
