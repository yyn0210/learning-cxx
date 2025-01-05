#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    // 创建100个元素的bool向量，全部初始化为true
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    
    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == 24, "Fill in the correct value.");  // 通常是24字节
    
    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");  // 已设置为false
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");  // 增加了一个元素
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");  // 新增的元素为false
    }
    {
        auto ref = vec[30];  // 注意：这不是真正的引用，而是一个代理对象
        ASSERT(ref, "Fill in `ref` or `!ref`");  // 原值为true
        ref = false;  // 修改代理对象
        ASSERT(!ref, "Fill in `ref` or `!ref`");  // 代理对象已改为false
        // THINK: WHAT and WHY?
        ASSERT(vec[30], "Fill in `vec[30]` or `!vec[30]`.");  // 原向量的值没有改变！
    }
    return 0;
}
