class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";
        for(int i = 0 ; i < s.length() ;i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        s = str;
        int i = 0;
        int j = s.length()-1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};