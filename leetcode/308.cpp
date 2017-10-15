class NumMatrix {

private:
    vector<vector<int>> _matrix;
public:    
    NumMatrix(vector<vector<int>> matrix) {
        _matrix = matrix;
    }
    
    void update(int row, int col, int val) {
        _matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                sum += _matrix[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
