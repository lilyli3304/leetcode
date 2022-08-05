//66. Plus One
//作者：lilyyueli
//链接：https://leetcode-cn.com/problems/plus-one/solution/spoiler-zi-ji-de-chu-shi-da-an-qiu-ping-3vhk4/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        bool shift = true;

        while (i >= 0)
        {
            if (digits.at(i) < 9)
            {
                digits.at(i) += 1;
                shift = false;
                break;
            }
            else
            {
                digits.at(i) = 0;
                i--;
            }
        }

        if (shift)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
