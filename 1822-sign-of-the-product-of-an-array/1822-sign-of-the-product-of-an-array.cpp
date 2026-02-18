class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negcount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negcount++;
            }
            if(nums[i]==0){

                return 0;
            }
        }
        if(negcount%2==0 ){
            return 1;
        }
        if(negcount%2==1){
            return -1;
        }
        return 0;
    }
};