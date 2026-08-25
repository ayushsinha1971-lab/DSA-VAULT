bool isPalindrome(int x) {
   long long int l;
    long long int sum=0;
    int temp=x;
    if(x>=0){
         while(x!=0){
         l=x%10;
      
          sum=sum*10+l;
       
        x/=10;
    }
    if(sum==temp){
        return true;
    }
    else{
        return false;
    }
    }
    else{
        return false;
    }
   
}