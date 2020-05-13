//https://leetcode.com/problems/remove-k-digits/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.length()) return "0";
        int i=0;
        while(k>0){
            if(i) i--;
            while(i<num.length()-1 && num[i]<=num[i+1]){
                i++;
            }
            num.erase(num.begin()+i);
            k--;
        }
        auto signi = num.find_first_not_of("0");
        num.erase(0,signi);
        if(!num.length()) return "0";
        return num;
    }
};
