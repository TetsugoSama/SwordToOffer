/**
 * 问题：
 * 数字以0123456789101112131415…的格式序列化到一个字符序列中。
 * 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
 * 请写一个函数，求任意第n位对应的数字。
 * 
 * 解决思路：
 * 1、将 101112⋯ 中的每一位称为 数位 ，记为 n；
 * 2、将 10, 11, 12，⋯ 称为 数字 ，记为 num ；
 * 3、数字 10 是一个两位数，称此数字的 位数 为 2 ，记为 digit ；
 * 4、每 digit 位数的起始数字（即：1, 10, 100, ⋯），记为 start 。
 * 5、每个digit包含的总的数字(两位是从10~99，共90*2=180个)，记为count。
 * 
 * 故有：
 * 位数递推：digit++;
 * 起始数字递推：start *= 10;
 * count的计算：count = 9*start*digit;
 * 
*/
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long count = 9;
        long long start = 1;
        int digit = 1;
        while (count < n) {
            n -= count;
            start *= 10;
            ++digit;
            count = 9 * start * digit;
        }
        int num = start + (n - 1) / digit;  //num是n指向的数字所在的数
        string s = to_string(num);
        return s[(n - 1) % digit]-'0';
    }
};