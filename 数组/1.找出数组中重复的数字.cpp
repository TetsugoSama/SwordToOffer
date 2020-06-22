/**************************************************************************
 * 问题：
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是
 * 重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意
 * 一个重复的数字。
 *
 * 解决思路：
 * （1）遍历数组，设索引为i,元素为m。若i!=m,则检查nums[m]是否等于m，若是，则为重复
 * 的数；若否，则将nums[i]与nums[m]交换。
 * （2）哈希表法，创建一个哈希数组hash_table,默认元素为0，将已经访问过的元素作为
 * hash_table的下标，改变哈希数组的元素的值，hash_table[nums[i]] = 1;检查正在访问
 * 的元素是否已经访问过，if(hash_table[nums[i]] == 1)
*/

#include <vector>
using namespace std;

class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=i) {
                int m = nums[i];
                if(m==nums[m])
                    return m;
                else {
                    nums[i] = nums[m];
                    nums[m] = m;
                }
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> n(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(n[nums[i]]==1)
                return nums[i];
            n[nums[i]] = 1;
        }
        return 0;
    }
};