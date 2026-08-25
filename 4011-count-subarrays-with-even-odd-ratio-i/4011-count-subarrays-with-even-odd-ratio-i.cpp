class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count =0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int e=0;
            int o=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    e++;
                }
                else{
                    o++;
                }
                if(o>0){
                    if(e*b<=a*o){
                        count ++;
                        
                    }
                }
            }
        }
        return count ;
    }
};