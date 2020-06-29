/*
 * 问题：
 * 实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
 * 
 * 解决思路：
 * (1)移位法：
 * a.检测n的第一位是否为1，循环左移
 * b.使用变量x = 1检测n的每一位，x循环左移
 * 注意：不要采用检测n的最后一位并右移的方法，若n为负数，则右移后第一位为1。
 * 
 * (2)位运算法：
 * 对于任意二进制数n!=0，若最后一位为1，那么n-1只有最后一位变化；
 * 若最后一位为0，那么从最后一位开始取反，直到最末尾的1变成0结束。
 * 采用n = n&(n-1)的方式，每次运算会消除一个1，消除的次数便是1的个数。
*/

class Solution1 {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n!=0)
        {
            n = n&(n-1);
            ++res;
        }
        return res;
    }
};

class Solution2 {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n!=0)
        {
            if((n&0x80000000)!=0) ++res;
            n<<=1;
        }
        return res;
    }
};