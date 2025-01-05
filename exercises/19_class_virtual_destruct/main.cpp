#include "../exercise.h"

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>
// READ: 虚析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

struct A {
    // 静态成员变量需要在类外定义和初始化
    static int num_a;

    A() {
        ++num_a;
    }
    // 基类析构函数需要声明为虚函数，否则通过基类指针删除派生类对象会导致未定义行为
    virtual ~A() {
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};
// 在类外定义静态成员
int A::num_a = 0;

struct B final : public A {
    static int num_b;

    B() {
        ++num_b;
    }
    ~B() override {
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};
// 在类外定义静态成员
int B::num_b = 0;

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    ASSERT(A::num_a == 2, "Fill in the correct value for A::num_a");  // A和B各创建一个，共2个A
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");  // 创建了1个B
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;
    ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");  // 创建了1个A(B)
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");  // 创建了1个B
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    // 使用 dynamic_cast 进行安全的向下转换
    B &bb = dynamic_cast<B&>(*ab);
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    // TODO: ---- 以下代码不要修改，通过改正类定义解决编译问题 ----
    delete ab;// 通过指针可以删除指向的对象，即使是多态对象
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
