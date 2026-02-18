class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negcount=0;
        int zerocnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negcount++;
            }
            if(nums[i]==0){
                zerocnt++;
            }
        }
        if(negcount%2==0 && zerocnt==0){
            return 1;
        }
        if(negcount%2==1 && zerocnt==0){
            return -1;
        }
        return 0;
    }
};