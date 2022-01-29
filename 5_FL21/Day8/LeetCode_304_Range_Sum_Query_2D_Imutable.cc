class NumMatrix {
private:
    int prefix[201][201] = {0};
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for (int i = 1; i <= n; ++ i){
            int cur = 0;
            for (int j = 1; j <= m; ++ j){
                cur += matrix[i-1][j-1];
                prefix[i][j] = prefix[i-1][j] + cur;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return    prefix[row2+1][col2+1]
                - prefix[row2 + 1][col1]
                - prefix[row1][col2 + 1]
                + prefix[row1][col1];
    }
};