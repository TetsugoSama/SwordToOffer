/***
 * 问题：
 * 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
 * 
 * 解决思路：
 * （1）双队列法：
 * 两个队列a和b，将根节点push进a，然后再从a中pop，若取出的不为nullptr，则将值存入
 * 临时数组level，并将该节点左右孩子push进b。当a为空时，检查level是否为空，若不是，则
 * 存入二维数组中；再将之前的步骤重复，a和b反过来操作，直到两个队列都为空为止。
 * 
 * （2）递归法：
 * 递归访问每个节点的左右孩子，并传递层数信息，每个节点将自己的值按层存入二维数组，直到
 * 遇到nullptr为止。
*/

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution_Queue {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> a, b;
        a.push(root);
        while (!a.empty() || !b.empty()) {
            vector<int> level;
            if (a.empty()) {
                while (!b.empty()) {
                    if (b.front()) {
                        level.push_back(b.front()->val);
                        a.push(b.front()->left);
                        a.push(b.front()->right);
                    }
                    b.pop();
                }
            }
            else {
                while (!a.empty()) {
                    if (a.front()) {
                        level.push_back(a.front()->val);
                        b.push(a.front()->left);
                        b.push(a.front()->right);
                    }
                    a.pop();
                }
            }
            if (!level.empty()) {
                v.push_back(level);
            }
        }
        return v;
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
        return v;
    }
};

