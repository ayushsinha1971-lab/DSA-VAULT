class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int max=0;
        int M=*max_element(lights.begin(),lights.end());
        for(int i=0;i<arrivalTime.size();i++){
            int t =arrivalTime[i]%period;
            if(t>=M){
                int temp=period-t;
                if(max<temp){
                    max=temp;
                }
            }
        }
        return max;
    }
};