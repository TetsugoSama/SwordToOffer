/**
 * 问题：
 * 输入两个链表，找出它们的第一个公共节点，若无，输出空指针。
 * 
 * 解决思路：
 * 假设链表1由L1+C两个链表组成；链表2由L2+C两个链表组成。
 * 我们让指针a遍历L1、C和L2,指针b同时遍历L2、C和L1，则最终在公共节点相遇；若C为空，则在空指针处相遇。
*/
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a!=b) {
            if(!a) a = headB;
            else a = a->next;
            if(!b) b = headA;
            else b = b->next;
        }
        return a;
    }
};