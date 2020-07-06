/*
 * 问题：
 * 输入一个链表，输出该链表中倒数第k个节点。
 * 
 * 解决思路：
 * （1）stack：将链表遍历，并将每个节点压入栈中，
 *      当链表遍历完时从栈顶往下第k个即为结果。
 * （2）双指针法：创建两个指针，一个处于头结点，
 *      一个在头结点后第k个，两个指针同时向后移动。
 *      当第二个指针到达终点时，第一个指针即为结果。
 */

#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head->next;
        }
        for(int i=0;i<k;i++) {
            head = s.top();
            s.pop();
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *tail = head;
        for(int i=0;i<k;i++) tail = tail->next;
        while(tail) {
            tail = tail->next;
            head = head->next;
        }
        return head;
    }
};