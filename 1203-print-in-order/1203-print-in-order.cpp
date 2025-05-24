#include <latch>

class Foo {
public:
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        l1.count_down();
    }

    void second(function<void()> printSecond) {
        l1.wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        l2.count_down();
    }

    void third(function<void()> printThird) {
        l2.wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    latch l1{1};
    latch l2{1};
};