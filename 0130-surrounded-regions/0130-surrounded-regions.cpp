class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int x, int y, int m, int n) {
        
        visited[x][y] = true;
        
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(auto dir : directions) {
            int xnew = x + dir.first;
            int ynew = y + dir.second;
            
            if(xnew >= 0 && xnew < m &&
               ynew >= 0 && ynew < n &&
               !visited[xnew][ynew] &&
               board[xnew][ynew] == 'O') {
                
                dfs(board, visited, xnew, ynew, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(board, visited, i, 0, m, n);
            
            if(board[i][n-1] == 'O' && !visited[i][n-1])
                dfs(board, visited, i, n-1, m, n);
        }
        
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(board, visited, 0, j, m, n);
            
            if(board[m-1][j] == 'O' && !visited[m-1][j])
                dfs(board, visited, m-1, j, m, n);
        }
        

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};