using namespace std;
class Solution {
public:
    int abs(int x){
        if(x<0)return -1*x;
        return x;
    }
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int min=-1;
        int mindis=-1;
        for(int i=0;i<drones.size();i++){
            int dis=0;
             // min=0;
            for(int j=0;j<2;j++){
                dis+=abs(target[j]-drones[i][j]);
                
            }
           if(drones[i][2]>=dis){
               if(min==-1){
                   min=i;
                   mindis=dis;
               }
             else  if(dis<mindis)
             {
                 min=i;
                 mindis=dis;
             }
           }
        }
        
        if(min==-1)return -1;
        return min;
    }
};