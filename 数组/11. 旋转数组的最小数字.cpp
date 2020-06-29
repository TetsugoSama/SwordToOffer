/*******************************************************************************************************************
 * 问题：
 * 一个按照升序排列的数组，把所有元素向右移动同样的距离，如果超过数组尾部，则到达数组头部。找出数组中的最小的元素。
 * 
 * 解决思路：
 * 循环二分：设置left,right指针分别指向numbers数组左右两端，mid = (left + right)/2;可分为以下三种情况：
 * 
 * (1)当 numbers[mid] > numbers[right]时：mid一定在右半段数组中，即旋转点一定在[mid + 1,j]闭区间内，因此执行left = mid+1；
 * (2)当 numbers[mid] < numbers[right]时：mid一定在左半段数组中，即旋转点一定在[left, mid]闭区间内，因此执行right = mid；
 * (3)当 numbers[mid] == numbers[right]时：无法判断mid在哪个排序数组中，即无法判断旋转点在[left, mid]还是 [mid+1,right]区间中。
 *    但可以肯定旋转点在[left,right-1]中，执行right--；
 * 返回值：当left==right时跳出二分循环，并返回 numbers[left] 即可。
 */

#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0,right = numbers.size()-1,mid = (left+right)/2;
        if(numbers[right]>numbers[left])
            return numbers[0];
        while(left!=right) {
            if(numbers[right]>numbers[mid]) {
                right = mid-1;
            } else if(numbers[right]<numbers[mid]) {
                left = mid+1;
            } else {
                --right;
            }
            mid = (left+right)/2;
        }
        return numbers[left];
    }
};