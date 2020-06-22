/***************************************************************
 * 问题：
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个
 * 二维数组和一个整数，判断数组中是否含有该整数。
 * 
 * 解决思路：
 * (1)以右上角为起点，若元素小于目标，则下移；若大于目标，则左移；
 * 若超出左边界或下边界，则不存在。
 * (2)以左下角为起点，若元素小于目标，则右移；若大于目标，则上移；
 * 若超出右边界或上边界，则不存在。
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int y = 0,x = matrix[0].size()-1;
        while(x>=0&&y<matrix.size())
        {
            if(matrix[y][x]==target)
                return true;
            else if(matrix[y][x]<target)
                ++y;
            else
                --x;
        }
        return false;
    }
};