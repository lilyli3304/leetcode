//Offer45. 把数组排成最小的数
//作者: yuelilily
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums)
            strs.push_back(to_string(num));
            quickSort(strs, 0, strs.size() - 1);
        string ans;
        for (auto str : strs)
            ans.append(str);
        return ans;
    }
    void quickSort(vector<string> &strs, int left, int right)
    {
        if (left >= right)
            return;
        int i = left, j = right;
        //pivot, left, right
        int pivot = left;
        while (i < j)
        {
            //from right to left, find the first one smaller than pivot
            while (strs[j] + strs[pivot] >= strs[pivot] + strs[j] && i < j) j--;
            //from left to right, find the first one larger than pivot
            while (strs[i] + strs[pivot] <= strs[pivot] + strs[i] && i < j) i++;
            //pivot, j, i
            swap(strs[i], strs[j]);
        }
        //pivot, smaller x n / 2, larger x n / 2
        swap(strs[i], strs[pivot]);
        //smaller x 1, smaller x n / 2, pivot, larger x n / 2
        //smaller x n / 2 quickSort
        quickSort(strs, left, i - 1);
        //larger x n / 2 quickSort
        quickSort(strs, i + 1, right);
    }
};

