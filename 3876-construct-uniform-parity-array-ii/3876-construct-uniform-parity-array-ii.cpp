class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minOdd = INT_MAX;
        bool Even = false, Odd = false;

        for (auto x : nums1) {
            if (x % 2 == 0) {
                Even = true;
            } else {
                Odd = true;
                minOdd = min(minOdd, x);
            }
        }
        if (!Even || !Odd) 
            return true;

        for (auto x : nums1) {
            if (x % 2 == 0 && x <= minOdd) {
                return false;
            }
        }
        return true;
    }
};