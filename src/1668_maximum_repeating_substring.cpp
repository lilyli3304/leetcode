//1668. 最大重复子字符串 Maximum Repeating Substring
//作者: yuelilily
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = word.size(), n = sequence.size();
        if (n < m)
            return 0;

        vector<int> next(m, 0);
        vector<int> f(n, 0);
        for (int i = 1, j = 0; i < m; ++i)
        {
            while (j > 0 && word[i] != word[j])
                j = next[j - 1];
            if (word[i] == word[j])
                j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i)
        {
            while (j > 0 && sequence[i] != word[j])
                j = next[j - 1];
            if (sequence[i] == word[j])
            {
                j++;
            }
            if (j == m)
            {
                f[i] = (i < m ? 0 : f[i - m]) + 1;
                j = next[j - 1];
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};

