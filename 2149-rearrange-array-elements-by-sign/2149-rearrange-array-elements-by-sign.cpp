class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> p;
        vector <int>n;
        for(auto it:nums){
            if(it<0)
            n.push_back(it);
            else
            p.push_back(it);
        }
        int k=0;
        int l=0;
        int sgn=0;
        for(int i=0;i<nums.size();i++){
            if(sgn==0){
            nums[i]=p[k++];
            sgn=1;
            }
            else{
            nums[i]=n[l++];
            sgn=0;
            }
        }
        return nums;
    }
};