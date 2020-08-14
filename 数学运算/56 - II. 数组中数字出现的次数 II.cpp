/**
 * 问题：
 * 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
 * 
 * 解决思路：
 * 统计数组中所有元素每一位的1出现的次数，对3取余后便是目标值在该位的值。
*/

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitSum[32] = {0};
        for(int i=0;i<nums.size();++i) {
            long long k=1;
            for(int j=0;j<32;++j) {
                if((nums[i]&k)!=0) {
                    ++bitSum[j];
                }
                k <<= 1;
            }
        }
        int res = 0;
        for(int i=31;i>=0;--i) {
            int x = bitSum[i] %3;
            res <<= 1;
            res |= x;
        }
        return res;
    }
};