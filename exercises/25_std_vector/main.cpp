﻿#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");
        // vector的sizeof是固定的，包含指针和size/capacity信息，与元素个数无关
        ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            // 在索引1的位置插入1.5
            vec.insert(vec.begin() + 1, 1.5);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            // 删除索引2的元素
            vec.erase(vec.begin() + 3);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value.");
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
        }
    }
    {
        // 创建48个元素，初始值都是'z'
        std::vector<char> vec(48, 'z');
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == 24, "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier.");
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            ASSERT(vec[15] == 'z', "Fill in the correct value.");
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }
    return 0;
}
