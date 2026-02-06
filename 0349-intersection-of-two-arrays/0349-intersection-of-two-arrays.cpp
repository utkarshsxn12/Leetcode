class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
     int m = nums2.size();
     vector<int>ans;
     sort(nums1.begin(), nums1.end());
     sort(nums2.begin(),nums2.end());
     int i=0,j=0;
     while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            int val = nums1[i];
            ans.push_back(val);
        
             
                while (i < n && nums1[i] == val) i++; 
                while (j < m && nums2[j] == val) j++;
        }
     }
     return ans;
    }
};
      