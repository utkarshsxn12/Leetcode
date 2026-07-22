class Solution {
public:
    //create a visited array 
    //loop through every city n times, 
    //if city is not visited, start dfs from it
    //dfs marks all directly and indirectly connected cities as visited
    //increase the cnt, after each dfs call
    //return cnt
    void dfsHelper(int node, vector<vector<int>>& isConnected,
                   vector<bool>& visited) {

        visited[node] = true;

        // Check every city
        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {

            // If connected and not visited
            if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                dfsHelper(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool> visited(n, false);

        int provinceCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsHelper(i, isConnected, visited);
                provinceCount++;
            }
        }

        return provinceCount;
    }
};