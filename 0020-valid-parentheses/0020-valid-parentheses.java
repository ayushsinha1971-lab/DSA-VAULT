class Solution {
    public boolean isValid(String s) {
        char []stack=new char [100000];
        int top=-1;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('||s.charAt(i)=='['||s.charAt(i)=='{'){
                stack[++top]=s.charAt(i);
            }
            else{
                if(top==-1){
                    return false;
                }
                if(
                    (stack[top]=='{'&&s.charAt(i)=='}')||
                    (stack[top]=='('&&s.charAt(i)==')')||
                    (stack[top]=='['&&s.charAt(i)==']')
                ){
                    top--;
                }
                else{
                    return false ;
                }
            }
        }
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
}