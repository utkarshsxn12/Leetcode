class Solution {
public:
    bool isHappy(int n) {
        
        while(n != 1) {
            int sum = 0;
            
            while(n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            
            n = sum;
            
            if(n == 4) return false;   
        }
        
        return true;
    }
};
