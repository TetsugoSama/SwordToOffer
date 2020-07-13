/**
 * 问题：
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * 
 * 解决思路：
 * 将矩阵分割成几个环，分别顺时针遍历每个环，调整好每个环的边界。
 * 对于有的环只需要横向或纵向遍历一次，使用一个变量，初始化为矩阵
 * 元素数量，每遍历一个就减一，减到0时结束遍历。
*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        vector<int> res;
        int all = matrix.size()*matrix[0].size();
        for (int level = 0; level < (matrix.size() + 1) / 2;++level) {
            int x = level, y = level;
            while (x < matrix[y].size() - level) {
                res.push_back(matrix[y][x]);
                ++x;
                --all;
            }
            if(!all) break;
            --x;
            ++y;
            while (y < matrix.size()-level) {
                res.push_back(matrix[y][x]);
                ++y;
                --all;
            }
            if(!all) break;
            --y;
            --x;
            while (x >= level) {
                res.push_back(matrix[y][x]);
                --x;
                --all;
            }
            if(!all) break;
            ++x;
            --y;
            while (y > level) {
                res.push_back(matrix[y][x]);
                --y;
                --all;
            }
            if(!all) break;
        }
        return res;
    }
};