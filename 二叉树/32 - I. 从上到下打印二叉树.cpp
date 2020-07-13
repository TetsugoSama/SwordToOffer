/**
 * 问题：
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 * 
 * 解决思路：遍历二叉树，若根节点不为空，则将值存入数组，将根节点的左右子节点存入queue,
 * 然后再从队列中取出front,直到队列为空。
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

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                v.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }            
        }
        return v;
    }
};