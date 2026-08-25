char nextGreatestLetter(char* letters, int lettersSize, char target) {
       int n=lettersSize;
       for(int i=0;i<n;i++){
        if(letters[i]>target){
            return letters[i];
        }
       }
       return letters[0];
}