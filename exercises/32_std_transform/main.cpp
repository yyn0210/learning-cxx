#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    
    // 创建结果向量
    std::vector<std::string> ans;
    ans.reserve(val.size());  // 预分配空间以提高效率
    
    // 使用 std::transform 将每个整数乘以2并转换为字符串
    std::transform(val.begin(), val.end(), 
                  std::back_inserter(ans),  // 使用back_inserter来插入元素
                  [](int x) {
                      return std::to_string(x * 2);  // 乘以2并转换为字符串
                  });

    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");
    return 0;
}
