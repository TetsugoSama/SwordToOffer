/***
 * 问题：构建一个容器，可以储存数据，并求出排序后的中位数。如果数据个数为奇数，
 * 那么中位数就是所有数值排序之后位于中间的数值。如果数据个数为偶数，
 * 那么中位数就是所有数值排序之后中间两个数的平均值。
 * 
 * 解决思路：
 * 使用两个优先队列，一个为maxQ，使用最大堆；另一个为minQ，使用最小堆。
 * maxQ储存较小的半段数据，minQ储存较大的半段数据，那么中位数一定是在
 * maxQ和minQ的顶端。
 * 每次把数据存入maxQ,然后把maxQ的最大值放入minQ，保证了maxQ储存的值小于
 * minQ；若minQ的长度大于maxQ,则把minQ的最小值放回maxQ。
*/
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxQ;
    priority_queue<int,vector<int>,greater<int>> minQ;
    int lenth = 0;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        ++lenth;
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();

        if (minQ.size() > maxQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        if (lenth == 0) {
            return -1;
        }
        else if (lenth % 2 == 0) {
            double a1 = maxQ.top();
            double a2 = minQ.top();;
            return (a1 + a2) / 2;
        }
        else
            return maxQ.top();
    }
};