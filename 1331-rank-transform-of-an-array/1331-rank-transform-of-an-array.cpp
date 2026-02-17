class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 0) return arr;
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int j = 0;
        for(int i = 1; i < n; i++){
            if(temp[i] != temp[j]){
                j++;
                temp[j] = temp[i];
            }
        }
        for(int i = 0; i < n; i++){
            int low = 0, high = j;
            
            while(low <= high){
                int mid = (low + high) / 2;
                
                if(temp[mid] == arr[i]){
                    arr[i] = mid + 1;
                    break;
                }
                else if(temp[mid] < arr[i]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        } 
        return arr;
    }
};
