class Solution {
public:
    int findLucky(vector<int>& arr) {
       int ans =-1;
       int n = arr.size();
       for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]){
                cnt++;
            }
        }
        if(cnt==arr[i]){
            ans=max(ans, arr[i]);
        }
       } 
       return ans;
    }
};