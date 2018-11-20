#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// Time Limit Exceeded
    void rotate1(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0)
            return;
        if (k % len == 0)
            return;
        while (k --) {
            int temp = nums[len - 1];
            for (int i = len - 1; i > 0; i --)
                nums[i] = nums[i - 1];
            nums[0] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0)
            return;
		k = k % len;
        if (k == 0)
            return;
        while (k --) {
            int temp = nums[len - 1];
            for (int i = len - 1; i > 0; i --)
                nums[i] = nums[i - 1];
            nums[0] = temp;
        }
    }
};
int main() {
	Solution sol;
	vector<int> nums{2, 3, 5, 7, 8};
	sol.rotate(nums, 2);
	for (auto n:nums)
		cout << n << " ";
	cout << endl;
	return 0;
}
