class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int ans=0;
        vector <int > count(10);
        for(auto it: digits){
            count[it]++;
        }
        vector <int> vis(1000,0);
        for(int i=1;i<10;i++){
            if(count[i]==0)continue;
            count[i]--;
            for(int j=0;j<10;j++){
                if(count[j]==0){
                    continue;
                }
                count[j]--;
                for(int k=0;k<10;k+=2){
                    if(count[k]==0)continue;
                    
                    int x=100*i+10*j+k;
                    if(vis[x]==0){
                        vis[x]=1;
                        ans++;
                    }

                }
                count[j]++;
            }
            count[i]++;
        }
        return ans;
    }
};