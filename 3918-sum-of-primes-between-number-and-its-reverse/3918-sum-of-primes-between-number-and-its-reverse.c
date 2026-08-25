int isPrime(int n){
    if(n==0||n==1)return 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int reverse(int n){
    int sum=0;
    int l;
    while(n!=0){
        l=n%10;
        n/=10;
        sum=sum*10+l;
    }
    return sum;
}
int sumOfPrimesInRange(int n) {
    int rev=reverse(n);
    int min,max;
    min=n;
    max=rev;
    if(n>rev){
        max=n;
        min=rev;
    }
    int sum=0;
    for(int i=min;i<=max;i++){
        if(isPrime(i)){
            sum+=i;
        }
    }
    return sum;
}