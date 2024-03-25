#include "../header.h"


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));

        int c = 0;
        int t = n * n;
        int k = 1;
        while (k <= t) {
            for (int i = c; k <= t && i < n - c; i++) {
                res[c][i] = k++;
            }
            for (int i = c + 1; k <= t && i < n - c; i++) {
                res[i][n-c-1] = k++; 
            }
            for (int i = n-c-2; k <= t && i >= c; i--) {
                res[n-c-1][i] = k++;
            }
            for (int i = n-c-2; k <= t && i >= c+1; i--) {
                res[i][c] = k++;
            }
            c++;
        }

        return res;
    }
};