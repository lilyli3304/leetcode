//104. 二叉树的最大深度 Maximum Depth of Binary Tree
//作者: yuelilily
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
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            depth++;
            for (int i = 1; i <= currentLevelSize; ++i)
            {
                TreeNode* node = q.front(); 
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
