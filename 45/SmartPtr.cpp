//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>
class Top {

};

class Middle: public Top {

};

class Bottom: public Middle {

};


template <typename T>
class SmartPtr {
public:
    explicit SmartPtr(T* realPtr) {}
};

template <typename T>
class SmartPtr1 {
public:
    // 对于任何类型T和类型U，这里可以根据SmartPtr<U>生成一个SmartPtr<T>
    // 只有当"存在某个隐式转换可以将一个U*指针转为一个T*指针"时才能通过编译
    template <typename U>
    SmartPtr1(const SmartPtr<U>& other): heldPtr(other.get()) {}
    T* get() const { return heldPtr; }

private:
    T* heldPtr; // 这个SmartPtr持有的内置指针
};

template <class T>
class shared_ptr1 {
public:
    template <class Y> explicit shared_ptr1(Y* p) {}
    // 意味着从某个shared_ptr类型隐式转换至另一个shared_ptr类型是被允许的，但如果是从某个内置指针或从其他智能指针类型进行隐式转换则不被认可
    template <class Y> shared_ptr1(shared_ptr1<Y> const& r) {}
    template <class Y> explicit shared_ptr1(std::weak_ptr<Y> const& r) {}
    template <class Y> explicit shared_ptr1(std::auto_ptr<Y> const& r) {}
    template <class Y> shared_ptr1& operator=(shared_ptr1<Y> const& r) {} // 没有声明const 因为在复制一个auto_ptr时，已经被改动了
    template <class Y> shared_ptr1& operator=(std::auto_ptr<Y> const& r) {}
};