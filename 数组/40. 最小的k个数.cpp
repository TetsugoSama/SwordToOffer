/**
 * 问题：
 * 输入整数数组 arr ，找出其中最小的 k 个数。
 * 
 * 解决思路：
 * (1)容器法：对于priority_queue和multiset（考虑重复元素）两种容器，可以实现自动排序。
 * 先将前k个元素存入容器，然后将最大值与后面的元素对比，若元素小于最大值，则弹出最大值，
 * 插入元素。
 * 
 * (2)排序法：排序，把前k个输出。
*/


#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution_PriorityQueue {
public:
    vector<int> getLeastNumbers(vector<int> arr, int k) {
        if (k == 0)
            return {};
        priority_queue<int> q;
        vector<int> res(k, 0);
        for (int i = 0; i < k; ++i) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            res[i] = q.top();
            q.pop();
        }
        return res;
    }
};

class Solution_Sort {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(k);
        for(int i=0;i<k;++i) {
            res[i] = arr[i];
        }
        return res;
    }
};