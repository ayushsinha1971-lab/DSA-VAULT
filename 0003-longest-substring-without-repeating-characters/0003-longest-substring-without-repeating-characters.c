#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int arr[256] = {0};
    int n = strlen(s);
    int f = 0, se;
    int len=0;
    for (se = 0; se < n; se++) {

        if(arr[s[se]]>0){//SAME CHARACTER 
            while(arr[s[se]]>0){
                arr[s[f]]=0;
                f++;
            }       
        }
          arr[s[se]]=1;
          if(len<se-f+1){

              len=se-f+1;

          }
 

    }
    return len;
}