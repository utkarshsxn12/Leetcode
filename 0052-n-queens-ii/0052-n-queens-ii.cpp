class Solution {
public:
    int count = 0;
    void solve(int row, int n, vector<int>& col, vector<int>& diag, vector<int>& antiDiag) {
        if (row == n) {
            count++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || diag[row - c + n - 1] || antiDiag[row + c])
                continue;
            col[c] = 1;
            diag[row - c + n - 1] = 1;
            antiDiag[row + c] = 1;
            solve(row + 1, n, col, diag, antiDiag);
            col[c] = 0;
            diag[row - c + n - 1] = 0;
            antiDiag[row + c] = 0;
        }
    }
    int totalNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> antiDiag(2 * n - 1, 0);
        solve(0, n, col, diag, antiDiag);
        return count;
    }
};