class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string temp;
        stringstream ss(path);
        while(getline(ss, temp, '/')) {
            if(temp == "" || temp == ".") continue;   
            if(temp == "..") {
                if(!stack.empty())
                    stack.pop_back();
            } 
            else {
                stack.push_back(temp);
            }
        }
        string result = "/";
        for(int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if(i != stack.size() - 1)
                result += "/";
        }
        return result;
    }
};