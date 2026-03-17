class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); 
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;       
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }   
        heights.pop_back(); 
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            } 
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};