class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int cnt=0, smallest=INT_MIN, longest = 1;
      int n = nums.size();
      sort(nums.begin(),nums.end());
      if(nums.empty()) return 0;
      for(int i=0;i<n;i++){
        if(nums[i]-1 == smallest){
            cnt+=1;
            smallest=nums[i];
        }
        else if(nums[i]!=smallest){
            cnt=1;
            smallest=nums[i];
        }
        longest = max(longest, cnt);
      }  
      return longest;
    }
};
