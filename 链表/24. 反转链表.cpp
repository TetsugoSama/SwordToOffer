/**
 *问题：
 *定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 * 
 * 解决思路:
 * (1)构建尾结点：
 * 创建一个空节点tail作为新链表尾，遍历链表，并用两个指针
 * 指向节点pNode和下一个节点pNext：
 * pNext = pNode->next;
 * pNode->next = tail;
 * tail = pNode;
 * pNode = pNext;
 * 直到pNext到达尾部。
 * 
 * (2)数组储存：
 * 遍历链表，将所有节点储存在ListNode*型数组里，从尾到头更改
 * next指针。(注意：链表为空时直接返回nullptr，链表不为空时vec[0]->next = nullptr)
 */
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        ListNode* node = head;
        while(head) {
            node = head;
            head = head->next;
            node->next = tail;
            tail = node;
        }
        return tail;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        vector<ListNode*> vec;
        while(head) {
            vec.push_back(head);
            head = head->next;
        }
        for(int i=vec.size()-1;i>0;--i)
        {
            vec[i]->next = vec[i-1];
        }
        vec.front()->next = nullptr;
        return vec.back();
    }
};