class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > res_map;
        vector<vector<string> > res;
        int size = strs.size();
        for (int i = 0; i < size; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            res_map[tmp].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = res_map.begin(); it != res_map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
