#include "../header.h"

class Solution {
public:

    bool is(vector<vector<char>>& board, int r, int c) {
        for (int i = 0; i < 9; i++) {
            if (i == r) continue;
            if (board[i][c] == board[r][c]) return false;
        }

        for (int j = 0; j < 9; j++) {
            if (j == c) continue;
            if (board[r][j] == board[r][c]) return false;
        }

        int rb = r / 3 * 3;
        int re = rb + 3;
        int cb = c / 3 * 3;
        int ce = cb + 3;
        for (int i = rb; i < re; i++) {
            for (int j = cb; j < ce; j++) {
                if (i == r && j == c) continue;
                if (board[i][j] == board[r][c]) return false;
            }
        }

        return true;
    }

    bool func(vector<vector<char>>& board, int r, int c) {
        if (r >= 9 || c >= 9) {
            return true;
        }

        for (int i = c; i < board[0].size(); i++) {
            if (board[r][i] != '.') continue;

            for (int t = 1; t <= 9; t++) {
                board[r][i] = '0' + t;
                if (!is(board, r, i)) {
                    board[r][i] = '.';
                    continue;
                } else {
                    if (func(board, r, i + 1) == false) {
                        board[r][i] = '.';
                    } else {
                        break;
                    }
                }
            }
            if (board[r][i] == '.')
                return false;
        }
        r++;
        if (func(board, r, 0) == true) {
            return true;
        } else {
            r--;
            return false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int r = 0;
        func(board, r, 0);
    }
};