//112. Path Sum 路径总和
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
bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr)
			return false;

		queue<TreeNode*> q;
		q.push(root);
		TreeNode* node;
		while (!q.empty())
		{
            node = q.front();
            q.pop();
            if (!node->left && !node->right)
            {
                if (node->val == targetSum)
                    return true;
                continue;
            }

            if (node->left)
            {
                node->left->val += node->val;
                q.push(node->left);
            }
            if (node->right)
            {
                node->right->val += node->val;
                q.push(node->right);
            }
		}
		return false;
	}
};

