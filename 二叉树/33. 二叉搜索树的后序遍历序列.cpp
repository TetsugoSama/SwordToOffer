/***
 * 问题：
 * 输入一个整数数组，判断该数组是不是某 “ 二叉搜索树 ” 的后序遍历结果。
 * 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * 
 * 解决思路：
 * 数组的最后一个元素为根节点；子树的根节点必然是子数组的最后一个树。
 * 数组按照 “左子树”、“右子树”、“根节点”排列。根节点向左遍历，直到遇到
 * 小于自己的元素停止。遍历的元素是右子树，剩余的是左子树。若左子树有
 * 元素大于根节点，则返回false。
*/

#include <vector>
using  namespace std;

class Solution {
private:
    bool subTree(vector<int>& postorder, int start, int end, int root, bool left) {
        if (start >= end)
            return true;
        if (left) {
            for (int i = start; i <= end; i++) {
                if (postorder[i] > root) {
                    return false;
                }
            }
        }
        int right = end - 1;
        while (right>=0&&postorder[right] > postorder[end]) {
            --right;
        }
        return subTree(postorder, start, right, postorder[end], true) && subTree(postorder, right + 1, end - 1, postorder[end], false);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0 || postorder.size() == 1)
            return true;
        int end = postorder.size() - 1;
        int right = end - 1;
        while (right >= 0 && postorder[right] > postorder[end]) {
            --right;
        }
        return subTree(postorder, 0, right, postorder[end], true) && subTree(postorder, right + 1, end - 1, postorder[end], false);
    }
};