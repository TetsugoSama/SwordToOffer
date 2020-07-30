/**
 * 问题：
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 
 * 解决思路：
 * （1）使用数组储存字符下标：
 * 创建一个数组，元素全部初始化为-1；创建两个指针start和end，两个指针之间的字符串即为字串。
 * end向后移动，并查看所指字符上次出现的地址，若地址大于start，说明重复字符在子串中，start移动到地址后一位，
 * 地址更新为end所指地址。每次end移动都查看此时的字串长度是否为最大。
 * （2）string容器法：
 * 遍历字符串，并将元素保存在string中，若下一个元素在string中有重复，则string裁剪掉重复元素之前的元素。
 * 每次遍历一个元素都查看string的长度是否为最大。
*/

class Solution_Arr {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos, -1, sizeof(pos));
        int start = 0, end = 0;
        int maxlen = 0;
        while (end < s.size()) {
            if (pos[s[end]]>=start) {
                start = pos[s[end]] + 1;
            }
            pos[s[end]] = end;
            int distance = end - start + 1;
            ++end;
            maxlen = maxlen > distance ? maxlen : distance;
        }
        return maxlen;
    }
};


class Solution_String {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int maxlen = 0;
        for(int i=0;i<s.size();++i) {
            int pos = str.find(s[i]);
            if(pos==-1) {
                str+=s[i];
            }else{
                str = str.substr(pos+1,str.size()-pos-1);
                str += s[i];
            }
            maxlen = maxlen>str.size()?maxlen:str.size();
        }
        return maxlen;
    }
};