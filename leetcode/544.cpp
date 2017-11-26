class Solution {
public:
    string findContestMatch(int n) {
        vector<string> pre_res;
        for (int i = 1; i <= n; i++) pre_res.push_back(to_string(i));
                                                       
        int tmp_size = pre_res.size();
        while(tmp_size > 1) {
            for (int i = 0; i < tmp_size / 2; i++) {
                pre_res[i] = "(" + pre_res[i] + "," + pre_res[tmp_size - i - 1] + ")";
            }
            tmp_size /= 2;
        }
        return pre_res[0];
    }
};
