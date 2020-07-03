/*
 * 问题：
 * 求double型变量的整数次幂，禁止使用pow函数，返回double型数值。
 * 
 * 解决方案：
 * 对于任意k^n，有k^n = (k)^a * (k^2)^b * (k^4)^c * (k^8)^d  * …………；
 * 因此，我们只要求出 k^(2^x)，2^x<=n即可。
 * 由上，有 n = a + 2b + 4c + 8d + …………;
 * 即 n = 01a + 010b + 0100c + 01000d + …………；
 * 故我们只要知道系数不为 0 的次幂即可。即n的位数为1的值的次幂。
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        else if(x==1||n==0)
            return 1;
        else if(x==-1)
            return n%2==0?1:-1;
        double res = 1;
        long k = n;
        if(n<0) {
            k = -k;
            x = 1/x;
        }
        while(k>0) {
            if((k&1) == 1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
};