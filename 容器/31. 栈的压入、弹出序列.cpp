/***
 * 问题:
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 
 * 解决思路：
 * 建立一个stack(s),push指针pu和pop指针po，然后当s不为空且栈首不等于pop[po]时，将push[pu++]推入s。
 * 若s.top()==pop[po]，则执行s.pop(),po++;当pu到头时，若s.top()!=pop[po],则顺序有问题，返回false.
 * 若po到头，则返回true.
*/
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0|| popped.size()==0)
            return true;
        stack<int> s;
        int pu = 0, po = 0;
        while(pu<pushed.size()) {
            while (pu < pushed.size()&&(s.empty() || s.top() != popped[po])) {
                s.push(pushed[pu]);
                ++pu;
            }
            while (po < popped.size() && !s.empty() && s.top() == popped[po]) {
                s.pop();
                ++po;
            }
        }
        if (po < popped.size())
            return false;
        else
            return true;
    }
};