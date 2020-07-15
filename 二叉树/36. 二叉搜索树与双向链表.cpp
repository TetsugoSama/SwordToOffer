/**
 * 问题：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
 * 
 * 解决思路：
 * 将二叉树按照中序遍历，储存在数组中，再生成循环双向链表。
 * 中序遍历采用栈，则将自身push入栈中，访问左子节点。
 * 当节点为空时，从栈中弹出上一节点，将节点的值存入数组，然后标记
 * 该节点以及栈中节点都已经访问左子树；若有右子节点，访问右子节点，
 * 并清理标记。直到栈为空且节点为空为止。
*/

#include <stack>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        vector<Node*> v;
        stack<Node*> s;
        bool left_visited = false;
        while (!s.empty()||root) {
            if (!left_visited&&root) {
                s.push(root);
                root = root->left;
                continue;
            }
            root = s.top();
            v.push_back(root);
            s.pop();
            left_visited = true;
            root = root->right;
            if (root) {
                left_visited = false;
            }
        }
        if (v.size() == 1) {
            v[0]->left = v[0];
            v[0]->right = v[0];
        }
        else {
            int pre = 0, next = 1;
            while (next < v.size()) {
                v[pre]->right = v[next];
                v[next]->left = v[pre];
                ++pre;
                ++next;
            }
            v.front()->left = v.back();
            v.back()->right = v.front();
        }
        return v.front();
    }
};
