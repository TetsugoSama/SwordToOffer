/**
 * 问题：
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 
 * 解决思路：
 * (1)摩尔投票法：
 * 每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），
 * 最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。
 * 
 * (2)中位法：
 * 将数组排序，则中间那个元素必定长度超过一半。
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution_BoyerMoore {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int vote = nums[0];
        int num = 1;
        for(int i=1;i<nums.size();++i) {
            if(num==0) {
                num = 1;
                vote = nums[i];
            }
            else {
                if(vote==nums[i]) {
                    ++num;
                }else {
                    --num;
                }
            }
        }
        return vote;
    }
};

class Solution_SortAndMiddle {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};