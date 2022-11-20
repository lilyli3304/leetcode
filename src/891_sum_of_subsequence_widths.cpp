//891. Sum of Subsequence Widths 子序列宽度之和
//作者：lily哟
//链接：https://leetcode.cn/problems/sum-of-subsequence-widths/solutions/1979145/by-yuelilily-74gt/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    long long int fastexp(int exp)
    {
        long long int ans = 1, mul = 2;
        while (exp)
        {
            if (exp & 1)
                ans = (ans * mul) % mod;
            mul = (mul % mod) * (mul % mod);
            mul = mul % mod;
            exp >>= 1;
        }
        return ans;
    }

    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int num1, int num2) {
            return num1 < num2;
        });
        long long int ans = 0;
        int j = n - 1, i = 0;
        for (int k = 0; k < n / 2; ++k)
        {
            long long int pji = (fastexp(j) % mod - fastexp(i) % mod) % mod;
            long long int add = pji * (long long int)nums[j] % mod;
            add -= pji * (long long int)nums[i] % mod;
            ans += add % mod;
            j--;
            i++;
        }
        while (ans < 0)
            ans = ans + mod;
        return ans % mod;
    }
private:
    static constexpr long long int mod = 1e9 + 7;
};
