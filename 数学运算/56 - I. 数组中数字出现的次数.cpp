/**
 * 问题：
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * 
 * 解决思路：
 * 两个相同的数异或为0，且异或具有结合律。设目标值为a,b，则所有元素异或的值为 s =  a^b；
 * 设s的二进制数的第n位为1，则必然a和b中只有一个第n位为1。
 * 以第n位是否为1，将元素分成两组，分别求异或值，则分别为a，b
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sumCheck = 0;
        for(int i=0;i<nums.size();++i) {
            /*将所有元素异或，异或具有结合律，相同元素异或为0*/
            sumCheck ^= nums[i];
        }
        int k = 1;
        /*检查sumCheck为1的最低位n，目标值必然一个n位为1，另一个不为1*/
        while((sumCheck & k)==0) k <<= 1;
        int a = 0,b = 0;
        for(int i=0;i<nums.size();++i) {
            /*以n位是否为1,将元素分成两组异或*/
            if((nums[i]&k)==0) {
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }
        return {a,b};
    }
};