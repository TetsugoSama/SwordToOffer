/**
 * 问题：
 * 我们把只包含质因子2、3 和 5 的数称作丑数（包含1）。求按从小到大的顺序的第 n 个丑数。
 * 
 * 解决思路：
 * 对于大于5的任意丑数，必然是一个丑数乘上(2，3，5)，通过三个指针，分别指向下一个元素的父元素。
*/
#include <algorithm>

using namespace std;

class Solution {
    public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;   //分别指向下一个元素的父元素
        int *dp = new int[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;   //分别乘上2，3，5
            dp[i] = min(min(n2, n3), n5);   //选出最小
            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;   //防止元素重复
        }
        return dp[n - 1];
    }
};
