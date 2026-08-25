class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector <int > l(n);
        vector <int > r(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(skill[i]!=station[j]){
                j++;
            }
            l[i]=j;
            j++;
        }
        int ans=0;
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(skill[i]!=station[j]){
                j--;
            }
            r[i]=j;
            j--;
        }
        for(int i=1;i<n;i++){
            ans=max(ans,r[i]-l[i-1]);
        }
        return ans;
    }
};