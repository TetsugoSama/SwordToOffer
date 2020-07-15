/***
 * 问题：
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 要求返回这个链表的 深拷贝。 
 * 
 * 思路：用map将原节点和新节点联系起来，然后按照原来的关系构造新链表。
*/

#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nm;
        nm[nullptr] = nullptr;
        Node pre(0);
        pre.next = head;
        Node* p = &pre;
        nm[p] = p;
        Node* n = head;
        while (n) {
            nm[n] = new Node(n->val);
            nm[p]->next = nm[n];
            p = n;
            n = n->next;
        }
        n = head;
        while (n) {
            nm[n]->random = nm[n->random];
            n = n->next;
        }
        return nm[head];
    }
};