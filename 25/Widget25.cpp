//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>
#include <vector>


//namespace std {
//    // version 1:
//    template <typename T>
//    void swap(T& a, T& b) {
//        T temp(a);
//        a = b;
//        b = temp;
//    }
//}

class WidgetImpl {
public:
private:
    int a, b, c;
    std::vector<double> v; // 可能复制的时间很长
};

class Widget {
public:
    Widget(const Widget& rhs) {}
    Widget& operator=(const Widget& rhs) {
        // 复制Widget时，令它复制其WidgetImpl对象
        *pImpl = *(rhs.pImpl);
        return *this;
    }

private:
    WidgetImpl* pImpl;
};

namespace std {
    // version 2: (Bad)
    // 一旦要置换两个Widget对象值，我们只需要置换其pImpl指针
    template <>
    void swap<Widget>(Widget& a, Widget& b) {
        // swap(a.pImpl, b.pImpl); 无法通过编译 无法获取pImpl
    }
}

// version 3
class Widget1 {
public:
    void swap(Widget1& other) {
        using std::swap;
        std::cout << "widget1.swap(Widget1& a)" << std::endl;
        swap(pImpl, other.pImpl);
    }
private:
    WidgetImpl* pImpl;
};

namespace std {
    template<>
    void swap<Widget1>(Widget1 &a, Widget1 &b) noexcept(is_nothrow_move_constructible<Widget1>::value && is_nothrow_move_assignable<Widget1>::value) {
        std::cout << "swap(Widget1& a, Widget1& b)" << std::endl;
        a.swap(b);
    }
}

// 如果Widget和WidgetImpl内有参数
template <typename T>
class Widget_T {
public:
    void swap(Widget_T& other) {
        using std::swap;
        std::cout << "Widget_T.swap(Widget_T& a)" << std::endl;
    }
};

// version 4: (Bad)
namespace std {
    // template <typename T>
    // void swap<Widget_T<T>>(Widget_T<T>& a, Widget_T<T>& b) { a.swap(b);}  编译错误
}

// version 5: (Bad)
namespace std {
    // 这样虽然正确，但是客户不可以添加新的templates到std里头
    template <typename T>
    void swap(Widget_T<T>& a,Widget_T<T>& b) {
        std::cout << "std::swap(Widget<T>& a, Widget<T>& b)" << std::endl;
        a.swap(b);
    }
}

// version 6:
namespace WidgetStuff {
    template <typename T>
    class Widget_T1 {
    public:
        void swap(Widget_T1<T>& other) {
            std::cout << "Widget_T1.swap(Widget_T1<T>& a)" << std::endl;
        }
    };

    // 这里不属于std 命名空间
    template <typename T>
    void swap(Widget_T1<T>& a, Widget_T1<T>& b) {
        std::cout << "swap(Widget<T>& a, Widget<T>& b)" << std::endl;
        a.swap(b);
    }

}


// 总结
// 1 提供一个pubic swap成员函数，高效的置换两个类型的对象值 （考虑到要交换private）
// 2 在你的class或者template所在的命名空间内提供一个non-member swap 再让他调用上述swap成员函数
// 3 如果你正在编写class 为你的class特化std::swap 并令他调用你的swap成员函数