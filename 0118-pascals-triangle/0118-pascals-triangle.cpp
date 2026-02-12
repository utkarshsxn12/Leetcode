class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.reserve(numRows); 
        
        for(int i = 0; i < numRows; i++) {
            vector<int> row;
            row.reserve(i + 1);  
            
            long long val = 1;
            row.push_back(1);
            
            for(int j = 1; j <= i; j++) {
                val = val * (i - j + 1) / j;
                row.push_back(val);
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};
