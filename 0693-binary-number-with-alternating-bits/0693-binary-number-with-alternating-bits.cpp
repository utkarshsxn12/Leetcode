class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        while(n > 0) {
            
            if((n % 2) == ((n / 2) % 2)) 
                return false;
            
            n = n / 2;   
        }
        
        return true;
    }
};
