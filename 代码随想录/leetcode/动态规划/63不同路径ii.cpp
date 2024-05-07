#include "../header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

        vector<vector<int>> dp(r, vector<int>(c, 1));

        for (int i = 0, flag = 0; i < r; i++) {
            if (flag) {
                dp[i][0] = 0;
                continue;
            }
            if (obstacleGrid[i][0] == 1) {
                flag = 1;
                dp[i][0] = 0;
            }
        }
        for (int j = 0, flag = 0; j < c; j++) {
            if (flag) {
                dp[0][j] = 0;
                continue;
            }
            if (obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
                flag = 1;
            }
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[r-1][c-1];
    }
};