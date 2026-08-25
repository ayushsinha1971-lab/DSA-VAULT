int dominantIndices(int* nums, int numsSize) {
    int count =0;
    int n=numsSize;
    int j;
    int i;
    for( i=0;i<n-1;i++){
        int sum=0;
        int num=0;
        for( j=i+1;j<n;j++ ){
            sum+=nums[j];
        }
        num=j-i-1;
        int avg=sum/num;
        if(nums[i]>avg){
            count++;
        }
    }
    return count;
}