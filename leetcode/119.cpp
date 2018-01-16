class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int k = rowIndex + 1;
        vector<int> res(k, 0);
        res[0] = 1;
        for (int i = 1; i < k; i++) {
            for (int j = i; j > 0; j--) res[j] += res[j-1];
        }
        return res;
    }
};
