class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int m = tasks.size();
        int n = shifts.size();
        vector <int> ans(n);
        vector <long long > pref(m+1,0);
        for(int i=0;i<m;i++){
            pref[i+1]=pref[i]+tasks[i];
        }
        long long total=pref[m];
        long long pos=0;
        for(int i=0;i<n;i++){
            pos+=shifts[i];
            if(pos>=total){
                pos =0;
                ans[i]=0;

            }
            else{
                int idx=upper_bound(pref.begin(),pref.end(),pos)-pref.begin();
                ans[i]=m-idx+1;
            }
        }
        return ans;
    }
};