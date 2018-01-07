class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s.length();
        int result = 1;
        //value, index
        map<char, int> letter;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (letter.find(s[i]) == letter.end() || letter[s[i]] < start) {
                result = max(result, i - start + 1);
            }
            else {
                start = letter[s[i]];
            }
            letter[s[i]] = i + 1;
        }
        return result;
    }
};
