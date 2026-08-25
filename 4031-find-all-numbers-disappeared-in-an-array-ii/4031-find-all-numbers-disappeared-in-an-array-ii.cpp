class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) { 
        vector <vector<int>> ans;
        unordered_set<int> s(nums.begin(),nums.end());
        int n=nums.size();
        vector <int> a;
        for(int i=lower;i<=upper;i++){
            if(s.find(i)==s.end()){
                a.push_back(i);
            }
        }
        int m=a.size();
        
        int c=0;
        int start;
        for(int i=0;i<m;i++){
            if(c==0)
              start=a[i];
            c=1;
            if(i==m-1||a[i]+1!=a[i+1]){
                ans.push_back({start,a[i]});
                
                c=0;
            }
            }
        return ans;
    }
};