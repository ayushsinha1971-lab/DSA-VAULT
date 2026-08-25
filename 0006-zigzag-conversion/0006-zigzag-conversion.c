char* convert(char* s, int numRows) {
     int n=strlen(s);
     int k=0;
     int inc=(numRows-1)*2;
     char * res = (char *)malloc((n+1)*sizeof(char));
     if(numRows==1){
        return s;
     }
     for(int r=0;r<numRows;r++){

        for ( int i=r;i<n;i+=inc){
            res[k++]=s[i];

            if(r>0&&r<numRows-1){//diagonal
                if((i+inc-2*r)<n){
                  res[k++]=s[i+inc-2*r];

                }
            }
        }
     }
    //  char result[n+1];
    //  strcpy(result,res);
    //  res[n+1]='\0';
    //   free(res);
    res[k]='\0';
     return res;
    

}