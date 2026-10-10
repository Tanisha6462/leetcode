class Solution {
public:
    string prefix(string s1 , string s2){
        int i = 0;
        int j = 0;
        string str = "";
        while(i < s1.length() && j < s2.length()){
            if(s1[i] == s2[j]){
                str += s1[i];
                i++;
                j++;
            }
            else{
                break;
            }
        }
        return str;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        while(strs.size() != 1){
            int j = i + 1;
            string temp = prefix(strs[i],strs[j]);
            strs.erase(strs.begin(),strs.begin()+2);
            strs.insert(strs.begin(),temp);
        }
        return strs[0];

    }
};