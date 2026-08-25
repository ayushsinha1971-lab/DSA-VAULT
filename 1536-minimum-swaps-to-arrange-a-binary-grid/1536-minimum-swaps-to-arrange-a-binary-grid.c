int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n=gridSize;
    int ze[n];
    int k=0;
    
    for(int i=0;i<n;i++){//count of zero 
        int count =0;
        int j=n-1;
        while(j>=0&&grid[i][j]==0){
            count++;
            j--;
        }
        ze[k++]=count ;
   }
   int step=0;
    for(int i=0;i<n;i++){
        int need =n-i-1;
        int j=i;
        while(j<n&&ze[j]<need){
            j++;
        }
    if(j==n){
        return -1;
    }
    else{
        step+=j-i;
        while(j>i){
            int temp=ze[j];
            ze[j]=ze[j-1];
            ze[j-1]=temp;
            j--;
        }
    }
    }
    return step;
}