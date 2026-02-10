class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        for(int i=0;i<pos.size();i++){
            for(int j=0;j<neg.size();j++){
                ans.push_back(pos[i]);
                i++;
                ans.push_back(neg[j]);
            }
        }
        return ans;
    }
};