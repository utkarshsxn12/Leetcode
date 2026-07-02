class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(int i=0; i<s.length();i++){
            f1[s[i] - 'a']++;
        }
        for(int j=0;j<t.length();j++){
            f2[t[j]-'a']++;
        }
        if(f1==f2) return true;
        return false;
    }
};