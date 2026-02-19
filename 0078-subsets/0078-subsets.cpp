class Solution {
public:
    void getSubsets(vector<int>&nums, vector<int>&ans, int i,vector<vector<int>>&allSubsets){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        //include
        ans.push_back(nums[i]);
        getSubsets(nums, ans, i+1, allSubsets);
        ans.pop_back();
        //exclude
        getSubsets(nums, ans, i+1, allSubsets);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int>ans;
        getSubsets(nums, ans, 0, allSubsets);
        return allSubsets;

    }
};