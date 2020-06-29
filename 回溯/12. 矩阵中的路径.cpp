/********************************************************************************
 * 问题：
 * 给出一个字符矩阵和字符串，矩阵起点可以为任意位置，判断矩阵中是否存在一条路径，
 * 使得经过的字符组成的字符串与所给的一致（已访问过的点不能再访问）。
 * 
 * 解决思路：
 * 回溯法，首先找出矩阵中字符串的首字母所在位置当做起点，然后判断能否向上下左右
 * 移动，移动后将该位置的字符记为‘0’，若此路不通，则改回该位置的字符，并返回上一位置，
 * 直到所有的起点都遍历一遍为止。
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool found(vector<vector<char>>& board, string& word, int n,int x,int y) {
        char c = board[y][x];
        board[y][x] = '0';
        if (n == word.size()-1)
            return true;
        bool res = false;
        for (int i = 0; i < 4; i++) {
            switch (i) {
            case 0:
                if (x > 0 && board[y][x - 1] == word[n + 1]) {
                    res = found(board, word, n + 1, x - 1, y);
                    if (res)
                        return true;
                }
                break;
            case 1:
                if (x <board[y].size()-1 && board[y][x + 1] == word[n + 1]) {
                    res = found(board, word, n + 1, x + 1, y);
                    if (res)
                        return true;
                }
                break;
            case 2:
                if (y >0 && board[y-1][x] == word[n + 1]) {
                    res = found(board, word, n + 1, x, y-1);
                    if (res)
                        return true;
                }
                break;
            case 3:
                if (y < board.size() - 1 && board[y+1][x] == word[n + 1]) {
                    res = found(board, word, n + 1, x, y+1);
                    if (res)
                        return true;
                }
                break;
        }
    }
    board[y][x] = c;
    return false;
}

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    res = found(board, word, 0, j, i);
                }
                if (res)
                    return true;
            }
        }
        return false;
    }
};