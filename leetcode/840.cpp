class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int cnt = 0;
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (isMagic(grid, i, j)) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
    # left upper corner
    bool isMagic(vector<vector<int>> &grid, int row, int col) {
        int s = 0;
        for (int i = 0; i < 3; i++) {
            s += grid[row][col + i];
            if (grid[row][col + i] > 9 || grid[row][col + i] < 1) {
                return false;
            }
        }
        cout << s << endl;
        # check other rows
        for (int j = 1; j < 3; j++) {
            int tmp_s = 0;
            for (int i = 0; i < 3; i++) {
                tmp_s += grid[row+j][col+i];
                if (grid[row+j][col+i] > 9 || grid[row+j][col+i] < 1) {
                    return false;
                }
            }
            if (tmp_s != s) {
                return false;
            }
        }
        
        # check cols
        for (int j = 0; j < 3; j++) {
            int tmp_s = 0;
            for (int i = 0; i < 3; i++) {
                tmp_s += grid[row+i][col+j];
            }
            if (tmp_s != s) {
                return false;
            }
        }
        
        # diag right
        int tmp_s = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if (tmp_s != s) {
            return false;
        }
        
        # diag left
        tmp_s = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if (tmp_s != s) {
            return false;
        }
        return true;
    }
};
