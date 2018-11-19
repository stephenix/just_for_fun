#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0;
        int max_len = 1;
        // left, right point palindromic begin and end respectively
        for (int i = 0; i < s.size() && (s.size() - i) * 2 >= max_len;) {
            int left = i, right = i;
            while (right + 1 < s.size() && s[right] == s[right + 1]) {
                ++ right;
            }
            i = right + 1;
            while (left > 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                -- left;
                ++ right;
            }
            if (max_len < right - left + 1) {
                max_len = right - left + 1;
                begin = left;
            }
        }
        return s.substr(begin, max_len);
    }
};

int main() {
	Solution sol;
	string s = "cbbd"; 
	string ret = sol.longestPalindrome(s);
	cout << ret << endl;
	return 0;
}
