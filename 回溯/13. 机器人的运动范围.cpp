/*
 * 问题：
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
 * 它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，
 * 因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 * 
 * 解决思路：
 * 回溯法，先创建一个m*n二维数组作为地图，然后从0,0出发，每到一个点就判断是否可以进入，若可以，则在地图上
 * 把该点抹去，并统计后面能去的点的数量，加上1后返回；若不行，则返回0.
*/


#include <vector>

using namespace std;

class Solution {
public:
    int bitsum(int a, int b) {
        int res = 0;
        while (a > 0) {
            res += a % 10;
            a /= 10;
        }
        while (b > 0) {
            res += b % 10;
            b /= 10;
        }
        return res;
    }

    bool canIn(vector<vector<bool>>& vmap, int& m, int& n, int& k, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return false;
        else if (bitsum(x, y) > k)
            return false;
        else if (vmap[y][x] == 0)
            return false;
        else
            return true;
    }

    int move(vector<vector<bool>>& vmap, int& m, int& n, int& k, int x, int y) {
        int res = 0;
        if (canIn(vmap, m, n, k, x, y)) {
            vmap[y][x] = 0;
            res += 1 + move(vmap, m, n, k, x - 1, y)
                + move(vmap, m, n, k, x + 1, y)
                + move(vmap, m, n, k, x, y - 1)
                + move(vmap, m, n, k, x, y + 1);
        }
        return res;
    }


    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vmap(m, vector<bool>(n, 1));
        return move(vmap, m, n, k, 0, 0);
    }
};