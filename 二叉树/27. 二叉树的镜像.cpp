/**
 * 问题：
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 * 
 * 解决思路：
 * 针对每个节点，递归的交换左右子节点。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    void turn(TreeNode* root) {
        if(!root)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        turn(root->left);
        turn(root->right);
    }

    TreeNode* mirrorTree(TreeNode* root) {
        turn(root);
        return root;
    }
};