class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector <int> maxi;
        int n=nums.size();
        vector <int> mini(n);
        maxi.push_back(nums[0]);
        mini[n-1]=nums[n-1];
        // int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>maxi[i-1]){
                maxi.push_back(nums[i]);
            }
            else{
                maxi.push_back(maxi[i-1]);
            }
        }
        for(int j=n-2;j>=0;j--){
            if(nums[j]<mini[j+1])
            mini[j]=nums[j];
            else
            mini[j]=mini[j+1];
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k){
                return i;
            }
        }
        return -1;
    }
};