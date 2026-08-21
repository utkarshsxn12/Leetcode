class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int mini = salary[0];
        int n = salary.size();
        int maxi = salary[n-1];
        
        double sum  = 0;
        for(int i=0;i<n; i++){
            if(salary[i] != mini && salary[i] != maxi){
                sum+=salary[i];
            }
        }
        return sum / (n-2);
    }
};