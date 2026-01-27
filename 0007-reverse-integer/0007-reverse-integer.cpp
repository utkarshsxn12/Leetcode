class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x!=0){
            int digit=x%10;
            long long temp = (long long)ans * 10 + digit;
             if (temp != (int)temp)
                return 0;
            ans=(int)temp;
            x=x/10;
        }
        return ans;
        }

        
    
};