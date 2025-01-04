#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;
    
    // 构造函数，用于初始化缓存
    Fibonacci() : cached(2) {
        // 初始化前两个斐波那契数
        cache[0] = 0;
        cache[1] = 1;
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        // 如果请求的索引小于等于已缓存的数量，则直接返回缓存中的值
        if (i < cached) {
            return cache[i];
        }

        // 如果索引超过了缓存大小（128），则需要处理这种情况
        if (i >= 128) {
            // 这里可以抛出异常、返回错误码或者使用其他方法处理超出范围的情况
            // 在这个例子中，我们简单地返回0作为错误标志
            return 0;
        }

        // 计算并填充缓存直到第 i 项
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib = {};
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
