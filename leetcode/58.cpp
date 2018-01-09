class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while(end >= 0 && s[end] == ' ') end--;
        int start = end;
        while(start >=0 && s[start] != ' ') start--;
        if (end == -1) return 0;
        return end - start;
    }
};
