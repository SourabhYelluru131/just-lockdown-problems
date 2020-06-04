//https://leetcode.com/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(!s.size()) return;
        int n = s.size();
        int size=n;
        if(!n%2) n =n/2;
        else n = (n-1)/2;
        for(int i=0;i<=n;i++){
            char temp = s[size-1-i];
            s[size-1-i] = s[i];
            s[i] = temp;
        }
    }
};
