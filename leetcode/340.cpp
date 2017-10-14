class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ctr[256] = {0}, j = -1;
        int res = 0, dis = 0;
        for (int i = 0; i < s.size(); i++) {
            dis += ctr[s[i]]++ == 0;
            while (dis > k) {
                if (--ctr[s[++j]] == 0) dis--;
            }
            res = max(res, i - j);
        }
        return res;
    }
};
