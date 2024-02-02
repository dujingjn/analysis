#include <iostream>
#include <vector>
#include <algorithm>

// 计算一个整数的汉明重量（二进制表示中1的个数）
int hammingWeight(unsigned int n) {
    int weight = 0;
    while (n) {
        weight += n & 1;
        n >>= 1;
    }
    return weight;
}

// 根据汉明重量对整数数组进行排序
void bitSort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        int weightA = hammingWeight(a);
        int weightB = hammingWeight(b);
        return weightA < weightB; // 如果权重相同，则保持原有顺序
    });
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // 使用位排序函数对数组进行排序
    bitSort(arr);

    // 打印排序后的数组
    std::cout << "Sorted array by Hamming weight: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
