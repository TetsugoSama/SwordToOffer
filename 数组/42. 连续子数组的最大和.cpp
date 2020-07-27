/**
 * 问题：输入一个整型数组，数组里有正数也有负数。
 * 数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 
 * 解决思路：
 * 从第一个元素开始，累加后面的元素；如果加上第k个元素后和小于0，则放弃之前的结果，从k+1个元素开始累加。
 * 这期间和的最大值为结果。
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int left = 0,right = 1;
        int sum = nums[left];
        int res = sum;
        while(left<nums.size()&&right<nums.size()) {
            if(sum<0) {
                left = right++;
                sum = nums[left];
            }else{
                sum += nums[right];
                ++right;
            }
            res = max(res,sum);
        }
        return res;
    }
};