class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] != (i % 2 ? '1' : '0')) count1++;
            if(s[i] != (i % 2 ? '0' : '1')) count2++;
        }

        return min(count1, count2);
    }
};