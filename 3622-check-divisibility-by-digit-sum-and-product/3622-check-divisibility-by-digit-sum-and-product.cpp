class Solution {
public:

    bool checkDivisibility(int n) {
        int temp=n;
        int multi=1,sum=0;
        while(temp!=0){
            int last=temp%10;
            multi*=last;
            sum+=last;
            temp/=10;
        }
        int num=multi+sum;
        if(n%num==0)return true ;
        return false;
    }
};