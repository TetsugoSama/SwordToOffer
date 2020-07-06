/**
 * 问题：
 * 输入两棵二叉树A和B，判断B是不是A的子结构（空树不是任意一个树的子结构）。
 * 
 * 解决思路：
 * 设计两个函数，第一个函数可以找出A树中所有的值和B的值相同的节点，并储存在数组中；
 * 第二个函数可以检查从A树的根开始到某一层是否和B树相同。
 * 主函数调用第一个函数，然后在针对数组中每一个元素调用第二个函数，若返回true，则表示
 * 包含；若都不返回true,则表示不包含。
 * 因为空树不算子节点，函数开头要检查B树。
*/
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    void found(TreeNode* A,int& t,vector<TreeNode*>& v) {
        if(!A)
            return;
        if(A->val==t) {
            v.push_back(A);
        }
        found(A->left,t,v);
        found(A->right,t,v);
    }
    
    bool same(TreeNode* A,TreeNode* B)
    {
        if(!B)
            return true;
        else if(!A||A->val!=B->val)
            return false;
        return same(A->left,B->left) && same(A->right,B->right);
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B)
            return false;
        vector<TreeNode*> v;
        found(A,B->val,v);
        for(auto a:v) {
            if(same(a,B))
                return true;
        }
        return false;
    }
};