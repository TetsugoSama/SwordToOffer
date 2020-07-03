/**
 * 问题：
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，
 * 但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。
 * 
 * 解决思路：
 * a.如果字符串开头有空格，全部跳过。
 * b.后面若有小数点，则至少小数点前有一个带符号的数，或小数点后有一个无符号的数。
 * c.后面若有e，则e前必须是一个数（有无符合、小数点都可以），e后面必须是一个整数（有无符号皆可）。
 * d.指数后面只能是空或者空格。
*/

#include <string>

using namespace std;

class Solution {
private:
    inline bool isUint(string& s,int& i) {
        int head = i;
        while(i<s.size()&&s[i]>='0'&&s[i]<='9') ++i;
        return i>head;
    }
    
    inline bool isInt(string& s,int& i) {
        if(s[i]=='+'||s[i]=='-') {
            ++i;
        }
        return isUint(s,i);
    }

    inline void stepSpace(string& s,int& i) {
        while(i<s.size()&&s[i]==' ') ++i;
    }

public:
    bool isNumber(string s) {
        if(s=="")
            return false;
        int i=0;
        stepSpace(s,i);
        bool isnum = isInt(s,i);
        if(i<s.size()&&s[i]=='.') {
            ++i;
            isnum |= isUint(s,i);
        }
        if(i<s.size()&&(s[i]=='e'||s[i]=='E')) {
            ++i;
            isnum &= isInt(s,i);
        }
        if(!isnum) return false;
        stepSpace(s,i);
        if(i==s.size()) return true;
        else    return false;
    }
};