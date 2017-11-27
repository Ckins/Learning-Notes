class Solution {
public:
    string nextClosestTime(string time) {
        int delta = 1440;
        unordered_set<char> s;
        for (auto c:time) {
            if (c != ':') s.insert(c);
        }
        string res = time;
        dfs(time, time, delta, 0, s, res);
        return res;
    }
    
    void dfs(string time, string &target, int &delta, int pos, unordered_set<char> &dict, string &res) {
        for (int i = pos; i < time.size(); i++) {
            if (i == 2) continue;
            for (auto &c : dict) {
                time[i] = c;
                if (isValid(time)) {
                    int tmp_delta = calc(target, time);
                    if (tmp_delta < delta) {
                        res = time;
                        delta = tmp_delta;
                    }
                    dfs(time, target, delta, pos+1, dict, res);    
                }
            }
        }
    }
    
    int calc(string now, string next) {
        int delta = strToMi(next) - strToMi(now);
        return delta > 0 ? delta : delta + 1440;
    }
    
    bool isValid(string time) {
        string hr = time.substr(0, 2);
        string mi = time.substr(3, 2);
        int i_hr = atoi(hr.c_str());
        int i_mi = atoi(mi.c_str());
        return i_hr >= 0 && i_hr <= 23 && i_mi >= 0 && i_mi <= 59;
    }
    int strToMi(string time) {
        string hr = time.substr(0, 2);
        string mi = time.substr(3, 2);
        int i_hr = atoi(hr.c_str());
        int i_mi = atoi(mi.c_str());
        return i_hr * 60 + i_mi;
    }
};
