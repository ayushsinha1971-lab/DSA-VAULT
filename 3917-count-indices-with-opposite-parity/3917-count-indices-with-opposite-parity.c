/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int iseven(int n){
    if(n%2==0)return 1;
    return 0;
}
int* countOppositeParity(int* nums, int numsSize, int* returnSize) {
    int * a=(int *)malloc(sizeof(int )*numsSize);
    int k=0;
   * returnSize=numsSize;
    for(int i=0;i<numsSize-1;i++){
       int count =0;
        if(iseven(nums[i])){
            for(int j=i+1;j<numsSize;j++){
                if(!iseven(nums[j])){
                    count ++;
                }
            }
        }
        else{
            for(int j=i+1;j<numsSize;j++){
                if(iseven(nums[j])){
                    count ++;
                }
            }
        }
        a[k++]=count;
    }
    a[k]=0;
    return a;
}