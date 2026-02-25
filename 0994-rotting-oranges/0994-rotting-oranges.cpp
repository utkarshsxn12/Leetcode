class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int minutes = 0;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int size = q.size();
            bool rottenThisMinute = false;
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                for(auto dir : directions){
                    int x = front.first + dir.first;
                    int y = front.second + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }
            if(rottenThisMinute) minutes++;
        }
        return (fresh == 0) ? minutes : -1;
    }
};