class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int r=0; r<rows; r++){
            for(int c =0; c<cols; c++){
                if(grid[r][c]==2) q.push({r,c});
                else if(grid[r][c]==1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        int minutes = 0;
        while(!q.empty() && fresh > 0){
            int size = q.size();
            minutes++;
            while(size--){
                pair<int, int> frontcell = q.front();
                q.pop();

                int r = frontcell.first;
                int c = frontcell.second;
                //top
                if(r>0 && grid[r-1][c] == 1){
                    grid[r-1][c] = 2;
                    fresh--;
                    q.push({r-1, c});
                }
                   if(r<rows-1 && grid[r+1][c] == 1){
                    grid[r+1][c] = 2;
                    fresh--;
                    q.push({r+1, c});
                }
                   if(c>0 && grid[r][c-1] == 1){
                    grid[r][c-1] = 2;
                    fresh--;
                    q.push({r, c-1});
                }
                   if(c<cols-1 && grid[r][c+1] == 1){
                    grid[r][c+1] = 2;
                    fresh--;
                    q.push({r, c+1});
                }
            }
        }
        return (fresh == 0) ? minutes : -1;
    }
};