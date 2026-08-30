class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0, maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);
        // Delete both from the left
        int option1 = right + 1;
        // Delete both from the right
        int option2 = n - left;
        // Delete one from each side
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};