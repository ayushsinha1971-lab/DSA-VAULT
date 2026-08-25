int indx(char a,char *arr){
    
    int i=0;
    while(arr[i]!='\0'&&arr[i]!=a){
        i++;
    }
    return i;
}
int romanToInt(char* s) {
    char symbol[]="IVXLCDM";
    int value[7]={1,5,10,50,100,500,1000};
    int i=0;
    int j=i+1;
    int res=0;
    while(s[i]!='\0')
    {
        if(s[j]!='\0'){
        if(indx(s[i],symbol)<indx(s[j],symbol)){
            res+=value[indx(s[j],symbol)]-value[indx(s[i],symbol)];
            i+=2;
            j+=2;
        }
        else
        {
            res+=value[indx(s[i],symbol)];
            i++;
            j++;
        }
    }
    else 
    {
        res+=value[indx(s[i],symbol)];
        i++;
    }

}
return res;
}