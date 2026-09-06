class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        int k=0;
        for(auto it:s){
            nums[k++]=it;
        }
         k=s.size();
        return k;
    }
};