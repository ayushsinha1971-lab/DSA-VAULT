class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long maxdiff=0;
        for(int i=0;i<nums1.size();i++){
            maxdiff=max(maxdiff,(long long)abs(nums1[i]-nums2[i]));
        }
        vector <long long> countdiff(maxdiff+1,0);
        for(int i=0;i<nums2.size();i++){
            long long diff=abs(nums1[i]-nums2[i]);
            countdiff[diff]++;
        }
        long long n=k1+k2;
        for(long long i=maxdiff;i>0&&n>0;i--){
            long long minop=min(n,countdiff[i]);
            countdiff[i]-=minop;
            countdiff[i-1]+=minop;
            n-=minop;
        }
        long long sum=0;
        for(int i=1;i<=maxdiff;i++){
            sum+=countdiff[i]*i*i;
        }
        return sum;
    }
};