class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for(int i = 0; i < nums1.size(); i++) {
            int ans = -1;
            bool found = false;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    found = true;
                }
                else if(found && nums2[j] > nums1[i]) {
                    ans = nums2[j];
                    break;
                }
            }

            res.push_back(ans);
        }
        return res;
    }
};
