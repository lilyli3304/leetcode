//145. Binary Tree Postorder Traversal 二叉树的后序遍历
//作者: yuelilily
//链接：https://leetcode.cn/problems/binary-tree-postorder-traversal/solution/by-yuelilily-2fb4/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //核心思想
 //左子树直接一条道走到头
 //右子树确认没走过在走，一个岔路一个岔路确认
 //用一个prev确认右子树没走过或者往回退的时候不走回头路
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (!stk.empty() || root != nullptr)
        {
            //以root为起点，走到extreme left node
            //沿途所有左子树上的点全部收于stack里
            while (root != nullptr)
            {
                stk.emplace(root);
                root = root->left;
            }
            //到达extreme left, 以这个点为新root
            root = stk.top();
            stk.pop();
            //开始检查它的右侧有无左子树，或者右侧是否已经遍历过(利用prev实现)
            if (root->right == nullptr || root->right == prev)
            {
                //右没有，或者右已遍历，那就改print这个root了
                res.emplace_back(root->val);
                //这个小子树就算彻底结束了，
                //root退回去重新开始遍历新的小子树
                //退回去时,有个prev指针用来监督，不走回头路
                prev = root;
                root = nullptr;
            }
            else
            {
                //发现右子树有且未遍历
                //开始遍历右子树,加入stack.
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

