class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;    
        function<void(int)> dfs = [&](int i){
            if(i == digits.size()){
                res.push_back(path);
                return;
            }
            string letters = mp[digits[i]-'0'];
            for(char c : letters){
                path.push_back(c);
                dfs(i+1);
                path.pop_back();
            }
        }; 
        dfs(0);
        return res;
    }
};