int vowelConsonantScore(char* s) {
    int n=0;
    int i=0;
    while(s[i]!='\0'){
        n++;
        i++;
    }
    int res;
    int c=0;
    int v=0;
    for( i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){
    if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
            v++;
            }
    else {
        c++;
    }
        }
    }
    if(c>0){
        res=v/c;
    }
    else{
        res=0;
    }
    return res;
}
