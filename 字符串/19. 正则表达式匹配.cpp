/**
 * 题目：
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（含0次）。
 * 
 * 解决思路：检查p指针的下一个元素是不是'*'，若是，则同时进行如下操作：
 *（1）s后移一位，p后移两位,这种情况匹配如下情况：
        s:abcd
 *      p:a*bcd
 * (2) s后移一位，p不动，这种情况匹配如下情况: 
 *      s:aaaabcd
 *      p:a*bcd
 * (3) s不动，p后移两位，这种情况匹配如下情况：
 *      s:abcd
 *      p:a*abcd
 * 
 * 若p+1不是'*'，则观察*p是否等于*s,或者是'.'，若是，s，p同时后移一位；若不是，返回false。
 * 
 * 结束条件：若s和p都到达终点，则返回true；若p先到达终点，则返回false；若s先到达终点，则观察p+1是否为'*'（将p消除），
 * 若是，p后移两位；若否，返回false。
*/
#include <string>

using namespace std;

class Solution {
public:
    bool fun(const char* s,const char* p) {
        if (*s == '\0' && *p == '\0')
            return true;
        if (*s != '\0' && *p == '\0')
            return false;
        if (*(p + 1) == '*') {
            if (*p == *s || (*p == '.' && *s != '\0')) {
                return fun(s + 1, p + 2) || fun(s + 1, p) || fun(s, p + 2);
            }
            else {
                return fun(s, p + 2);
            }
        }
        else if (*s == *p || (*p == '.' && *s != '\0'))
            return fun(s + 1, p + 1);
        else
            return false;
    }

    bool isMatch(string s, string p) {
        return fun(s.c_str(), p.c_str());
    }
};