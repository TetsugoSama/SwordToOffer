/***
 * 问题：
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 * 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 * 
 * 解决思路：
 * 动态规划：对于某一格grid[y][x],比较它上一格和左一格的大小，选取较大的，加到自己身上。
 * 开始前先初始化第一行和第一列。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int y=0,x=0;
        for(int i=1;i<grid[0].size();++i) {
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1;i<grid.size();++i) {
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1;i<grid.size();++i) {
            for(int j=1;j<grid[0].size();++j) {
                grid[i][j] += max(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};