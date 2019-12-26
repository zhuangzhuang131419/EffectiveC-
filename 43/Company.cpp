//
// Created by 郑驰骋 on 2019/12/26.
//
#include <iostream>
class CompanyA {
public:
    void sendCleartext(const std::string& msg) {
        std::cout << "CompanyA send clear text" << std::endl;
    }
    void sendEncrypted(const std::string& msg) {
        std::cout << "CompanyA send encrypted text" << std::endl;
    }
};

class CompanyB {
public:
    void sendCleartext(const std::string& msg) {
        std::cout << "CompanyB send clear text" << std::endl;
    }
    void sendEncrypted(const std::string& msg) {
        std::cout << "CompanyB send encrypted text" << std::endl;
    }
};

class MsgInfo {

};

template <typename Company>
class MsgSender {
public:
    void sendClear(const MsgInfo& info) {
        std::string msg;
        /*
         * ...根据info产生msg
         */
        Company c;
        c.sendCleartext(msg);
    }

    void sendSecret(const MsgInfo& info) {
        std::string msg;
        /*
         * ...根据info产生msg
         */
        Company c;
        c.sendEncrypted(msg);
    }
};



class CompanyZ {
public:
    void sendEncrypted(const MsgInfo& msg) {

    }
};

// 仅在template实参是CompanyZ的时候使用
template <>
class MsgSender<CompanyZ> {
public:
    void sendSecret(const MsgInfo& info) {

    }
};

template <typename Company>
class LoggingMsgSenderBad: public MsgSender<Company> {
public:
    void sendClearMsg(const MsgInfo& info) {
        // 将传送前信息写至Log

        // sendClear(info); 编译无法通过
        // 当编译器遭遇class template LoggingMsgSender定义式时，并不知道它继承什么样的class，因为我们不知道Company是什么直到LoggingMsgSender<Company>被具象化
        // 而如果不知道Company是什么，就无法知道class MsgSender<Company>看起来像什么——没办法直到是否有这个sendClear函数
        // eg. 如果Company == CompanyZ，那么sendClear这个函数就不存在

        // 将传送后信息写至Log
    }
};

template <typename Company>
class LoggingMsgSender1: public MsgSender<Company> {
public:
    void sendClearMsg(const MsgInfo& info) {
        // 将传送前信息写至Log

        this->sendClear(info);

        // 将传送后信息写至Log
    }
};

template <typename Company>
class LoggingMsgSender2: public MsgSender<Company> {
public:
    using MsgSender<Company>::sendClear; // 告诉编译器，请他假设sendClear位于base class之内

    void sendClearMsg(const MsgInfo& info) {
        // 将传送前信息写至Log

        sendClear(info);

        // 将传送后信息写至Log
    }
};

template <typename Company>
class LoggingMsgSender3: public MsgSender<Company> {
public:
    using MsgSender<Company>::sendClear; // 告诉编译器，请他假设sendClear位于base class之内

    void sendClearMsg(const MsgInfo& info) {
        // 将传送前信息写至Log

        MsgSender<Company>::sendClear(info);

        // 将传送后信息写至Log
    }
};