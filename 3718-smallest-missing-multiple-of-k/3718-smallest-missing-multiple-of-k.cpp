class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> mp(nums.begin(),nums.end());
        int i=1;
        int t=k;
        while(mp.find(k)!=mp.end()){
            i++;
            k=t*i;
        }
        return k;
    }
};