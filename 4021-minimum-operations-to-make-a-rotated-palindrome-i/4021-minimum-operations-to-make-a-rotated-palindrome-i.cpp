class Solution {
public:  
    int minOperations(string s) {
        int n=s.length();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cost=i;
            for(int j=0;j<n/2;j++){
                int a =s[(i+j)%n];
                int b=s[(i+n-1-j)%n];
                int diff =abs(a-b);
                int Cdiff=min(diff,26-diff);
                cost+=Cdiff;
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};