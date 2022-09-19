//6183. 字符串的前缀分数和 Sum of Prefix Scores of Strings
//作者: yuelilily
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
    struct TrieNode
    {
        TrieNode* children[26] {};
        vector<int> ids;
        int score = 0;
    };

    vector<int> ans;
    
    void dfs(TrieNode* node, int sum)
    {
        sum += node->score;
        for (int i : node->ids)
            ans[i] += sum;
        for (auto child : node->children)
            if (child != nullptr)
                dfs(child, sum);
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            TrieNode* curr = root;
            for (char c : words[i])
            {
                c = c - 'a';
                if (curr->children[c] == nullptr)
                    curr->children[c] = new TrieNode();
                curr = curr->children[c];
                ++curr->score;
            }
            curr->ids.push_back(i);
        }
        ans.resize(n);
        dfs(root, 0);       
        return ans;
    }
};
