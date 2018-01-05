class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        vector<int> res;
        for (unsigned int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            map<int, int>::const_iterator it = dict.find(rest);
            if (it == dict.end()) {
                dict[nums[i]] = i;
            } else {
                res.push_back(it->second);
                res.push_back(i);
            }
        }
        return res;
    }
};
