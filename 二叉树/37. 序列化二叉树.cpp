/**
 * 问题：
 * 请实现两个函数，分别用来序列化和反序列化二叉树。
 * 注：序列化：将二叉树层序遍历，并且将节点的值以字符串的形式存储，用逗号隔开；空节点表示为null
 * 反序列化：将字符串中的值按照层序构建二叉树。
 * 
 * 解决思路：
 * 序列化：将节点存放在queue中实现层序遍历，每次遍历都将节点存入deque，再将deque尾部所有的nullptr弹出，然后
 * 从头向尾访问节点，并将值存储为字符串。
 * 
 * 反序列化：先构建头节点，将头节点放入queue中，然后进入循环，从queue头取出节点node，从字符串中找出node的子节点
 * （字符串设置一个指针，每次取出一个节点就向后移动），构建好子节点后再将子节点放入queue，直到queue为空。
 */
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
class Codec {
public:

    inline string get_next(string& s, int& pre) {
        int next = 0;
        if (pre == s.size())
            return "";
        while ((pre + next) < s.size() && s[pre + next] != ',') next++;
        string res = s.substr(pre, next);
        pre += next + 1;
        return res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> qs;
        deque<TreeNode*> dq;
        qs.push(root);
        string res = "[";
        while (!qs.empty()) {
            TreeNode* node = qs.front();
            dq.push_back(node);
            qs.pop();
            if (node) {
                qs.push(node->left);
                qs.push(node->right);
            }
        }
        while (!dq.empty() && dq.back() == nullptr) dq.pop_back();
        while (!dq.empty()) {
            TreeNode* node = dq.front();
            dq.pop_front();
            if (node) {
                res += to_string(node->val);
            }
            else
                res += "null";
            if (!dq.empty())
                res += ',';
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s = data.substr(1,data.size()-2);
        if (s == "")
            return nullptr;
        string node;
        int index = 0;
        node = get_next(s,index);
        if (node == "null")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(node));
        TreeNode* res = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (!root)
                continue;
            if (index< s.size()) {
                node = get_next(s, index);
                if (node == "null") {
                    q.push(nullptr);
                }
                else {
                    root->left = new TreeNode(stoi(node));
                    q.push(root->left);
                }
            }
            if (index< s.size() ) {
                node = get_next(s, index);
                if (node == "null") {
                    q.push(nullptr);
                }
                else {
                    root->right = new TreeNode(stoi(node));
                    q.push(root->right);
                }
            }
        }
        return res;
    }
};