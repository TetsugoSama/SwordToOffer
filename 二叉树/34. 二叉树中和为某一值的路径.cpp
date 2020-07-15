/***
 * 问题：
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 * 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 * 
 * 解决方案：
 * 回溯法，每个节点将值push入数组，然后把sum减去值，判断节点是否太监；若是，
 * 检查sum是否为0，为0的话将数组push入二维数组，然后把数组尾pop，返回；若有后代，访问子节点；
 * 回溯时把数组尾pop
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
private:
    vector<vector<int>> res;
    vector<int> v;
private:
    void visitPath(TreeNode* root, int sum) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        v.push_back(root->val);
        sum -= root->val;
        if (!left&&!right) {
            if (sum == 0) {
                res.push_back(v);
            }
            v.pop_back();
            return;
        }
        if (left) {
            visitPath(left, sum);
        }
        if (right) {
            visitPath(root->right, sum);
        }
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return {};
        visitPath(root, sum);
        return res;
    }
};