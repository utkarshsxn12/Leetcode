class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int org, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Boundary check
        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        // Stop if color is different
        if (image[r][c] != org)
            return;

        // Color current cell
        image[r][c] = newColor;

        // Explore 4 directions
        dfs(r - 1, c, image, org, newColor);
        dfs(r + 1, c, image, org, newColor);
        dfs(r, c - 1, image, org, newColor);
        dfs(r, c + 1, image, org, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];

        if (org == color)
            return image;

        dfs(sr, sc, image, org, color);
        return image;
    }
};