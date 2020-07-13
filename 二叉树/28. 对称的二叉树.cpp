/*
 * 问题：
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 * 
 * 解决思路：
 * （1）左前序遍历+右前序遍历：
 * 将树同时进行左右的前序遍历，同时检查遍历到的节点的值是否相等。
 * 
 * （2）逐层检查法：
 * 将节点的值按层放入一个二维数组中，空指针就放入一个特殊值，检查每一层的数组是否对称。 
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution1 {
public:
    bool fun(TreeNode* l, TreeNode* r) {
        if(!l&&!r) {
            return true;
        }
        else if(!l||!r) {
            return false;
        }
        else if(l->val!=r->val) {
            return false;
        }
        return fun(l->left,r->right) && fun(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return fun(root->left,root->right);
    }
};

class Solution2 {
public:
    void fun(TreeNode* root, vector<vector<int>>& vec, int level) {            
        if (level>=vec.size()) {
            vector<int> blank;
            vec.push_back(blank);
        }
        if (!root) {
            vec[level].push_back(-1);
            return;
        }
        vec[level].push_back(root->val);
        fun(root->left, vec, level + 1);
        fun(root->right, vec, level + 1);
    }
    bool isSymmetric(TreeNode* root) {
        vector<vector<int>> vec;
        fun(root, vec, 0);
        for (int i = 0; i < vec.size(); ++i) {
            int left = 0, right = vec[i].size() - 1;
            while (right > left) {
                if (vec[i][left] != vec[i][right])
                    return false;
                ++left;
                --right;
            }
        }
        return true;
    }
};