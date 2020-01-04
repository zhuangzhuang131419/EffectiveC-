//
// Created by 郑驰骋 on 2020/1/3.
//
#include <iostream>
class TextBlock {

public:
    TextBlock(std::string s) {
        text = s;
    }


    const char& operator[](std::size_t position) const {
        return text[position];
    }

    // 要返回char的reference
    char& operator[](std::size_t position) {
        // 其中一个调用另一个，减小维护成本
        return const_cast<char&>(
                static_cast<const TextBlock&>(*this)[position]
                );
    }

private:
    std::string text;
};
