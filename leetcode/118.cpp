class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) return res;
        vector<int> first(1, 1);
        res.push_back(first);
        for (unsigned int i = 1; i < numRows; i++) {
            first = res[i-1];
            vector<int> second;
            second.push_back(1);
            for (unsigned j = 0; j + 1 < first.size(); j++) {
                second.push_back(first[j]+first[j+1]);
            }
            second.push_back(1);
            res.push_back(second);
        }
        return res;
    }
};
