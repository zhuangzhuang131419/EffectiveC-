//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>
class Empty {

};

class HoldsAnInt1 {
private:
    int x;
    Empty e;
};

class HoldsAnInt2: private Empty {
private:
    int x;
};
