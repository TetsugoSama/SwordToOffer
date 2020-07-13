/**
 * 问题：
 * 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 * 
 * 解决思路：
 * （1）双stack法：
 * 设置两个stack：a和b，将根节点push入a，然后遍历a中节点，再将pop出的非空节点的
 * 子节点按照先left后right push入b，并将值储存在临时数组level中；当a空时，
 * 遍历b中节点，并将pop出的非空节点的子节点按照先right后left push入b,并将值储存在
 * 临时数组level中。循环直到两个stack都为空为止。
 * 
 * （2）递归法：
 * 递归访问每个节点的左右孩子，并传递层数信息，每个节点将自己的值按层存入二维数组，直到
 * 遇到nullptr为止。最后将序号为奇数的数组反转。
*/

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution_Stack {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        stack<TreeNode*> a, b;
        a.push(root);
        vector<vector<int>> res;
        while (!a.empty() || !b.empty()) {
            vector<int> level;
            if (!a.empty()) {
                while(!a.empty()) {
                    if (a.top()) {
                        level.push_back(a.top()->val);
                        b.push(a.top()->left);
                        b.push(a.top()->right);
                    }
                    a.pop();
                }
            }
            else {
                while (!b.empty()) {
                    if (b.top()) {
                        level.push_back(b.top()->val);
                        a.push(b.top()->right);
                        a.push(b.top()->left);
                    }
                    b.pop();
                }
            }
            if (!level.empty())
                res.push_back(level);
        }
        return res;
    }
};

class Solution_Recursion {
private:
    void recursion(TreeNode* root, vector<vector<int>>& v, int level) {
        if (!root)
            return;
        if (level >= v.size())
            v.push_back({});
        v[level].push_back(root->val);
        recursion(root->left, v, level + 1);
        recursion(root->right, v, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        recursion(root, v, 0);
        for (int i = 0; i < v.size(); i++) {
            if (i % 2 != 0)
                reverse(v[i].begin(), v[i].end());
        }
        return v;
    }
};