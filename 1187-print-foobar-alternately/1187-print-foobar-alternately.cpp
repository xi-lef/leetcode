class FooBar {
private:
    const int n;
    binary_semaphore sem1{0};
    binary_semaphore sem2{1};

public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem2.acquire();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem1.release();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem1.acquire();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem2.release();
        }
    }
};