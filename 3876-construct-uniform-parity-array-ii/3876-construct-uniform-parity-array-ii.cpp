class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> odd, even;
        for (auto it : nums1) {
            if (it % 2 == 0) even.push_back(it);
            else odd.push_back(it);
        }

        if (even.size() == n || odd.size() == n)
            return true;

        sort(odd.begin(), odd.end());

        for (auto e : even) {
            int num = e - 1;
            auto it = upper_bound(odd.begin(), odd.end(), num);
            if (it == odd.begin()) {
                return false; 
            }
        }
        return true;
    }
};