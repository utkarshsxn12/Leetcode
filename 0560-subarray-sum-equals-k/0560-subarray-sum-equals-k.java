class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap <> ();
        mp.put(0,1);
        int ans = 0;
        int sum = 0;
        for(int j=0; j<n; j++){
            sum+=nums[j];
            if(mp.containsKey(sum-k)){
                ans+=mp.get(sum-k);
            }
            if(mp.containsKey(sum)){
                mp.put(sum, mp.get(sum)+1);
            }else{
                mp.put(sum, 1);
            }
        }
        return ans;
    }
}