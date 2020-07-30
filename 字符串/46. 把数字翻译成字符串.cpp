/**
 * 问题：
 * 给定一个数字，我们按照如下规则把它翻译为字符串：
 * 0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 * 
 * 解决思路：
 * 把数字转换成字符串，然后每次递归尝试右移一位、右移两位。
 * 要注意一下几个特殊情况：
 * 1、指针指向最后一个元素，这种情况不能右移两位；
 * 2、指针指向的元素为‘0’，这种情况不能右移两位；
 * 3、右移两位组成的数字大于25，这种情况不能右移两位；
*/

#include <string>

using namespace std;

class Solution {
private:
    int res;
private:
    void recursion(string& s,int index) {
        if(index>=s.size()) {
            ++res;
            return;
        }
        int n = s[index]-'0';
        recursion(s,index+1);
        if((index<s.size()-1)&&(s[index]!='0')) {
            n = stoi(s.substr(index,2));
            if(n<26) {
                recursion(s,index+2);
            }
        }
    }
public:
    int translateNum(int num) {
        string s = to_string(num);
        recursion(s,0);
        return res;
    }
};