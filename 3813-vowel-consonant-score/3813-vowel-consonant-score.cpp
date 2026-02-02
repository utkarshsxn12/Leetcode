class Solution {
public:
    int vowelConsonantScore(string s) {
      int vowel = 0;
      int consonent = 0;
      for(char ch: s){
        if(ch>='a' && ch<='z'){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowel++;
            }
            else{
                consonent++;
            }
        }
      }
      if(consonent==0)return 0;
      return vowel/consonent;
    }
};