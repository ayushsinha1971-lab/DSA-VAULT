char* longestCommonPrefix(char** strs, int strsSize) {
    int n=strsSize;
    int i;
    i=0;
    int k=0;
    char * res =(char * )malloc(sizeof(char)*200);
    int j;
    while(strs[0][i]!='\0')
    {
        if(n>1)
        {
            for(j=1;j<n;j++)
            {
                if(strs[0][i]!=strs[j][i])
                {
                    break;
                }
            }
            if(j==n)
            {
                res[k++]=strs[0][i];
            }
            else
            {
                res[k]='\0';
                return res;
            } 
        }
        else if(n==1)
        {
            // strcpy(res,strs[0]);
            res=strs[0];
            return res;
        }
        i++;
    }
    res[k]='\0';
    return res;
}
