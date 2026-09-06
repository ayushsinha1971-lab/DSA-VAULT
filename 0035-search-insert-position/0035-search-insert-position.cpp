class Solution {
public:
    int search(vector <int> & nums,int target, int l,int u){
        if(l>u){
            return l;
        }
        int mid=(l+u)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return search(nums,target,l,mid-1);
        }
        else{
            return search(nums,target,mid+1,u);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        
        return search(nums,target,0,n-1);
    }
};