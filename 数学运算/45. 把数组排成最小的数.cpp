/**
 * 问题：
 * 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 
 * 解决思路：
 * 将数组内的元素转换成字符串，并储存到另外一个数组中。对字符串数组排序，排序规则如下：
 * bool compare(string s1,string s2) {
 *     string s12 = s1+s2;
 *     string s21 = s2+s1;
 *     return s12<s21;
 * }
 * 将排序后的数组元素拼接成一个大字符串，即为结果。
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), [=](string s1, string s2) {return (s1 + s2) < (s2 + s1); });
        string res;
        for (auto s : v) {
            res += s;
        }
        return res;
    }
};