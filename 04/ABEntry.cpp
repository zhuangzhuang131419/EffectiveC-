//
// Created by 郑驰骋 on 2020/1/4.
//
#include <iostream>
class ABEntry {
public:
//    // 赋值，首先调用default构造函数设置初始值，再赋予新值
//    ABEntry(const std::string& name, const std::string& address) {
//        theName = name;
//        theAddress = address;
//    }

    // 初始化，推荐使用初始化来写构造函数，效率更高
    ABEntry(const std::string& name,
            const std::string& address)
            :theName(name),theAddress(address) {

    }

private:
    std::string theName;
    std::string theAddress;

};
