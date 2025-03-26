#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited) {
        int n = maze.size();
        // Check if (x, y) is within the maze and not yet visited, and the cell is not blocked
        return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
    }

    void solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& visited, string path, vector<string>& ans) {
        int n = maze.size();

        // If the rat reaches the destination (bottom-right corner), store the path
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Move down
        if (isSafe(x + 1, y, maze, visited)) {
            solveMaze(maze, x + 1, y, visited, path + 'D', ans);
        }

        // Move left
        if (isSafe(x, y - 1, maze, visited)) {
            solveMaze(maze, x, y - 1, visited, path + 'L', ans);
        }

        // Move right
        if (isSafe(x, y + 1, maze, visited)) {
            solveMaze(maze, x, y + 1, visited, path + 'R', ans);
        }

        // Move up
        if (isSafe(x - 1, y, maze, visited)) {
            solveMaze(maze, x - 1, y, visited, path + 'U', ans);
        }

        // Backtrack by unmarking the current cell
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& maze, int n) {
        vector<string> ans;
        if (maze[0][0] == 0) {
            return ans;
        }
        int srcx= 0;
        int srcy=0;

        vector<vector<int>> visited= maze;
        //initialise with 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j]=0;
            }
            
        }
        

        string path = "";
        solveMaze(maze, srcx, srcy, visited, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    vector<string> result = sol.findPath(maze, n);

    // Print the results
   cout << "Paths:\n";
for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
}


    return 0;
}
