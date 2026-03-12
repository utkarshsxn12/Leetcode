class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& temp,vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], temp, ans); 
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};