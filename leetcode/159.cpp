class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ctr[256] = {0}, j = -1;
        int res = 0, dis = 0;
        for (int i = 0; i < s.size(); i++) {
            dis += ctr[s[i]]++ == 0;
            while (dis > 2) {
                if (--ctr[s[++j]] == 0) dis--;
            }
            res = max(res, i - j);
        }
        return res;
    }
};
