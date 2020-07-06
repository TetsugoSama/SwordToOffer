/**
 * 问题：
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * 
 * 解决思路：
 * （1）遍历+对比（临时头结点）：
 * 创建一个临时头结点res,并使得指针node指向该临时头结点。对比l1和l2，若l1>l2,
 * 则把l2插入融合链表中；反之，将l1插入融合链表。当其中一个链表到头时，直接将
 * 另一个链表剩余部分插入融合链表。
 * 
 * （2）递归法：
 * 两节点中较小的节点，递归调用函数，获得将该节点的下一节点，返回该节点。若某
 * 链表遍历结束，则返回另一链表。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode* node = &res;
        while(l1&&l2) {
            if(l1->val>l2->val) {
                node->next = l2;
                node = l2;
                l2 = l2->next;
            }
            else {
                node->next = l1;
                node = l1;
                l1 = l1->next;
            }
        }
        if(l1) {
            node->next = l1;
        }
        else {
            node->next = l2;
        }
        return res.next;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        if(l1->val>l2->val) {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
        else {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
    }
};