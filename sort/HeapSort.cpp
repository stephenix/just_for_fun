#include <iostream>
#include <vector>
using namespace std;

void AdjustHeap(vector<int>& nums, int i, int len) {
	int child = 2 * i + 1;
	int cur_parent = nums[i];
	while (child < len) {
		while (child + 1 < len && nums[child] < nums[child + 1])
			++ child;
		if (cur_parent < nums[child]) {
			nums[i] = nums[child];
			i = child;
			child = 2 * i + 1;
		} else {
			break;
		}
	}
	nums[i] = cur_parent;
}

void HeapSort(vector<int>& nums, int len) {
	for (int i = len / 2 - 1; i > 0; i --)
		AdjustHeap(nums, i, len);
	for (int j = len - 1; j > 0; j --) {
		swap(nums[0], nums[j]);
		AdjustHeap(nums, 0, j);
	}
}

int main(void) {
    int num[] = {80,2,55,34,31,27,8,9,15,51}; 
    vector<int> nums(num, num + 10);
    HeapSort(nums, nums.size());
    for (int i = 0; i < nums.size(); i ++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
