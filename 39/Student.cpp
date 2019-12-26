//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>

class Person {

};

class Student: private Person {
    // 用private继承的意义是implemented in term of
    // Student的构造采用了Person内已经具备的某种特性
};


