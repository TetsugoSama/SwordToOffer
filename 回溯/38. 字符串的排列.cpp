/**
 * 问题：
 * 输入一个字符串，打印出该字符串中字符的所有排列。不能有重复元素。
 * 
 * 解决思路：
 * (1)将字符串中字母储存起来，用回溯法排列组合，每组合完一个就在set中
 * 查看是否重复，若不重复，则存入set和vector。
 * 
 * (2)使用STL的next_permutation全排列函数
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution_BackTrack{
private:
    vector<int> index;
    vector<char> cv;
    vector<string> v;
    unordered_set<string> res;
private:
    void fun(string s) {
        if(s.size()==index.size()) {
            if(res.count(s)==0) {
                res.insert(s);
                v.push_back(s);
            }
        }
        for(int i=0;i<index.size();i++) {
            int in = index[i];
            if(in<0) continue;
            index[i] = -1;
            fun(s+cv[in]);
            index[i] = in;
        }
    }
public:
    vector<string> permutation(string s) {
        if(s=="") {
            return {};
        }
        else if(s.size()==1) {
            return {s};
        }
        int i=0;
        for(auto c:s) {
            cv.push_back(c);
            index.push_back(i++);
        }
        fun("");
        return v;
    }
};

class Solution_STLFunction {
public:
    vector<string> permutation(string s) {
        vector<string>  ans;
        sort(s.begin(),s.end());
        ans.push_back(s);
        while(next_permutation(s.begin(),s.end())){
            ans.push_back(s);
        }
        return ans;
    }
};