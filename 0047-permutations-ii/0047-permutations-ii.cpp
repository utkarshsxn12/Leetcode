class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& temp, vector<int>& vis){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            backtrack(nums,temp,vis);
            temp.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp, vis(nums.size(),0);
        backtrack(nums,temp,vis);
        return res;
    }
};