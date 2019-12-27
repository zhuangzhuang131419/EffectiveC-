//
// Created by 郑驰骋 on 2019/12/27.
//
#include <iostream>

// 在std库中
struct input_iterator_tag {
};
struct output_iterator_tag {
};
struct forward_iterator_tag : public input_iterator_tag {
};
struct bidirection_iterator_tag : public forward_iterator_tag {
};
struct random_access_iterator_tag : public bidirection_iterator_tag {
};


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

// traits 允许你在编译期间取得某些类型信息
// 类型的traits信息必须位于类型自身之外

// 针对每一个类型IterT, 在struct iterator_traits<IterT>内声明某个typeof名为iterator_category
template<typename IterT>
struct iterator_traits {
    typedef typename IterT::iterator_category iterator_category;
};

// 针对指针类型做一个偏特化
template <typename IterT>
struct iterator_traits<IterT*> {
    typedef random_access_iterator_tag iterator_category;
};

// deque的迭代器可以随机访问
class deque {
public:
    class iterator {
    public:
        typedef random_access_iterator_tag iterator_category;
    };
};

// list的迭代器可以双向访问
class list {
public:
    class iterator {
    public:
        typedef bidirection_iterator_tag iterator_category;
    };
};


//利用重载
template <typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
    do_advance(iter, d, typename std::iterator_traits<IterT>::iterator_category());
}


template <typename IterT, typename DistT>
void doadvance(IterT& iter, DistT d, std::random_access_iterator_tag) {
    iter += d;
}

template <typename IterT, typename DistT>
void do_advance(IterT& iter, DistT d, std::bidirectional_iterator_tag) {
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

template <typename IterT, typename DistT>
void doadvance(IterT& iter, DistT d, std::input_iterator_tag) {
    if (d < 0) {
        throw std::out_of_range("Negative distance");
    }
    while (d--) {
        ++iter;
    }
}



