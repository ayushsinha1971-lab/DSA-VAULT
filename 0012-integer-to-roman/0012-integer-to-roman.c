#include <math.h>
#include <stdlib.h>
// #define I 
char * intToRoman(int num){
    int temp;
    char *res=(char * )malloc(sizeof(char)*100);
    int k=0;
    while(num/10!=0){
        int po=0;
         temp=num;
        while(temp/10!=0){
            temp/=10;
            po ++;
        }
        if(po==3){
            if(temp<=3){
                int i=0;
                while(i!=temp){
                    res[k++]='M';
                    i++;
                }
            }
        }
        else if (po==2){
            if(temp!=4&&temp!=9){
                if(temp<4){
                int i=0;
                while(i!=temp){
                    res[k++]='C';
                    i++;
                    }
                }  
            
                else if (temp<9){
                    int i=0;
                    int digit =temp;
                    digit=digit-5;
                    res[k++]='D';
                while(i!=digit){
                    res[k++]='C';
                    i++;
                    }
                }
            }
        
            else {
                if(temp==4){
                    res[k++]='C';
                    res[k++]='D';
                }
                else if (temp==9){
                    res[k++]='C';
                    res[k++]='M';
                }
            }
        }
        else if (po==1){
             if(temp!=4&&temp!=9){
                if(temp<4){
                int i=0;
                while(i!=temp){
                    res[k++]='X';
                    i++;
                    }
                }  
            
                else if (temp<9){
                    int i=0;
                    int digit=temp;
                    digit=digit-5;
                    res[k++]='L';
                while(i!=digit){
                    res[k++]='X';
                    i++;
                    }
                }
            }
            else {
                if(temp==4){
                    res[k++]='X';
                    res[k++]='L';
                }
                else if (temp==9){
                    res[k++]='X';
                    res[k++]='C';
                }
            }
        }
       
        int num1=temp*pow(10,po);
        num=num-num1;

    }
    temp=num;
     
             if(temp!=4&&temp!=9){
                if(temp<4){
                int i=0;
                while(i!=temp){
                    res[k++]='I';
                    i++;
                    }
                }  
            
                else if (temp<9){
                    int i=0;
                    int digit=temp;
                    digit=digit-5;
                    res[k++]='V';
                while(i!=digit){
                    res[k++]='I';
                    i++;
                    }
                }
            }
            else {
                if(temp==4){
                    res[k++]='I';
                    res[k++]='V';
                }
                else if (temp==9){
                    res[k++]='I';
                    res[k++]='X';
                }
            }
            res[k]='\0';
        
    return res;

}