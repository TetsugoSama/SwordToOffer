/**
 * 问题：输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 * 
 * 解决思路：
 * 设n == 23104，1出现在万位的可能性为1xxxx(10000~19999),共10000种；
 * 1出现在千位的可能性为01xxx，11xxx，21xxx，共3000种；
 * 1出现在百位的可能性为001xx~221xx，以及23100~23104，共22105种；
 * 1出现在十位的可能性为0001x~2301x，共2300种；
 * 1出现在各位的可能性为00001~23101，共2311种；
 * 
 * 总结如下：
 *  对于第k位(从右向左数)，大于k位的数设为m，小于k位的数为n，有：
 *  若k位大于1，则可能性为(m+1)* 10^(k-1)个；
 *  若k位等于1，则可能性为m * 10^(k-1) + n + 1 个;
 *  若k位小于1，则可能性为m * 10^(k-1) 个;
*/


#include <string>

using namespace std;

class Solution {
private:
    int getHigh(string& num,int index) {
        if(index==0) return 0;
        string s = num.substr(0,index);
        return stoi(s);
    }
    int getLow(string& num,int index) {
        if(index==num.size()-1) return 0;
        ++index;
        string s = num.substr(index,num.size()-index);
        return stoi(s);
    }
public:
    int countDigitOne(int n) {
        string num = to_string(n);
        int res = 0;
        int index = 0;
        while(index<num.size()) {
            if(num[index]>'1') {
                res += (getHigh(num,index)+1)*pow(10,num.size()-index-1);
            }else if(num[index]=='1') {
                res += getHigh(num,index)*pow(10,num.size()-index-1) + getLow(num,index)+1;
            }else{
                res += getHigh(num,index)*pow(10,num.size()-index-1);
            }
            ++index;
        }
        return res;
    }
};