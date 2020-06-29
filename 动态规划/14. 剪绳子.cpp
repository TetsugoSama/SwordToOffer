/*
 * 问题：
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 
 * 解决思路：
 * （1）动态规划：
 * 当n<4时，只能剪成1，n-1的方式，故最大只有n-1;
 * 创建数组dp[],存放各长度剪出的最大解。
 * 当n>4时，我们认为可以剪成0，n的方式，此时值为n,则dp[n]等于其本身的长度和不同剪法剪出的长度（k,n-k）得到的
 * 最大解dp[k]*dp[n-k]中的最大值（dp[n] = max(dp[n],dp[k]*dp[n-k], 0<k<=n/2)。
 * 
 * （2）贪心法：详见“贪心法”目录下的“剪绳子”解答。
*/

#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n<4)
            return n-1;
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++) {
            dp[i] = i;
            for(int k=1;k<=i/2;k++) {
                dp[i] = max(dp[i],dp[k]*dp[i-k]);
            }
        }
        return dp[n];
    }
};