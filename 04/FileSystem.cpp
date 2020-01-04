//
// Created by 郑驰骋 on 2020/1/4.
//
#include <iostream>
class FileSystem {
public:
    FileSystem() = default;
    std::size_t numDisks() const {
        return theDisk;
    }

    static FileSystem& tfs() {
        static FileSystem fs;
        return fs;
    }

private:
    std::size_t theDisk = 0;
};




class Directory {
public:
    Directory(std::size_t num): disks(num) {
        // C++ 对定义于不同编译单元内的non-local static对象的初始化相对次序并无明确定义
    }

    std::size_t numDisks() const {
        return disks;
    }

    static Directory& tempDir() {
        static Directory td(10);
        return td;
    }

private:
    std::size_t disks;
};


