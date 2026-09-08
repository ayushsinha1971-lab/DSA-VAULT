class Solution {
public:
    int countCommas(int n) {
        int d=0;
        int temp=n;
        while(temp){
            temp/=10;
            d++;
        }
        if(d<=3)return 0;
        return n-1000+1;
    }
};