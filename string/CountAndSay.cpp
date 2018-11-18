class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        if (n == 1)
            return ret;
        while (-- n) {
            ret = CountString(ret);
        }
        return ret;
    }
    string CountString(string& s) {
        string ret;
        int i = 0;
        while (i < s.length()) {
            char temp;
            int count = 1;
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                while (i + 1 < s.length() && s[i] == s[i + 1]) {
                    ++ i;
                    ++ count;
                }
                temp = count + '0';
                ret = ret + temp + s[i];
                i ++;
            } else {
                temp = '1';
                ret = ret + temp + s[i];
                ++ i;
            }
        }
        return ret;
    }
};
