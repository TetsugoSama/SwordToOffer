/**
 * 问题：
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中。
 * 
 * 解决思路：
 * 两个栈，一个栈s存放数据，另一个栈mins存放最小值。
 * 当mins为空时，push的数据放入mins。
 * 当mins不为空时，若push的数据<=mins.top(),则放入mins。
 * pop时，若mins.top()==s.top()，则mins.pop();
*/
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }

    void pop() {
        if(s.top()==mins.top())
            mins.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return mins.top();
    }
};