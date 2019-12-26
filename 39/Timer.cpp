//
// Created by 郑驰骋 on 2019/12/26.
//
class Timer {
public:
    explicit Timer(int tickFrequency);
    virtual void onTick() const;
};

Timer::Timer(int tickFrequency) {

}

void Timer::onTick() const {

}

class Widget1: private Timer {
private:
    // 如果把onTick()放进public接口内会误导客户端以为他们可以调用
    virtual void onTick() const;
};

void Widget1::onTick() const {
    Timer::onTick();
}

// 也可以使用复合的思路，尽量在实际开发中用复合代替private继承
class Widget2 {
private:
    class WidgetTimer: public Timer {
    public:
        virtual void onTick() const;
    };
    WidgetTimer timer;
};

void Widget2::WidgetTimer::onTick() const {
    Timer::onTick();
}
