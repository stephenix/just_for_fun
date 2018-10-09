#include <iostream>
#include <vector>
using namespace std;
// 思想:分治
// 时间复杂度、空间复杂度
int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= pivot)
            -- right;
        nums[left] = nums[right];
        while (left < right && nums[left] < pivot)
            ++ left;
        nums[right] = nums[left];
    }
    nums[left] = pivot;  
    return left; 
} 
    
void QuickSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        int pos = partition(nums, left, right); 
        QuickSort(nums, left, pos - 1);
        QuickSort(nums, pos + 1, right);
    }
}

int main(void) {
    int num[] = {80,2,55,34,31,27,8,9,15,51}; 
    vector<int> nums(num, num + 10);
    QuickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i ++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
