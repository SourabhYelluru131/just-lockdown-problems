//  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26]={0};
        for(char x:magazine){
            count[x-'a']++;
        }
        for(char y:ransomNote){
            count[y-'a']--;
            if(count[y-'a']<0)  return false;
        }
        return true;
    }
};
