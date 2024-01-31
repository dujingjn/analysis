#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 快速排序的主要函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择基准点为最后一个元素
    int i = (low - 1); // 索引i指向比基准点小的元素

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // 将基准点放到正确的位置上
    return (i + 1);
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取基准点的位置

        quickSort(arr, low, pi - 1); // 对基准点左边的子数组进行递归排序
        quickSort(arr, pi + 1, high); // 对基准点右边的子数组进行递归排序
    }
}

// 主函数，测试快速排序
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
