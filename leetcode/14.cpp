class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        if (strs.size() == 1) return strs[0];
        for (auto &s : strs) {
            if (s.size() == 0) return string("");
        }
        string base = strs[0];
        for (unsigned int i = 1; i < strs.size(); i++) {
            base = longestPrefixInTwoStr(base, strs[i]);
        }
        return base;
    }
    string longestPrefixInTwoStr(string a, string b) {
        if (a.size() == 0 || b.size() == 0) return string("");
        unsigned int i = 0;
        for (; i < a.size(); i++) {
            if (a[i] != b[i]) {
                break;
            }
        }
        return a.substr(0, i);
    }
};
