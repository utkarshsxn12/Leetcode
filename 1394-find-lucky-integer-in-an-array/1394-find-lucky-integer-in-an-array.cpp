class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int maxi = -1;
        sort(arr.begin(), arr.end());
        while(i<n){
            int curval = arr[i];
            int blocklength = 0;
            while( i < n && arr[i] == curval){
                blocklength++;
                i++;
            }
            if(blocklength == curval){
                maxi = max(maxi, curval);
            }
            

        }
        return maxi;
    }
};