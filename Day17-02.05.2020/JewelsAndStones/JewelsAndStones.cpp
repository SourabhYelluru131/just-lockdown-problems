//  https://leetcode.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        unordered_map<char, int> hash;
        for(char x : J){
            hash[x]++;
        }
        for(char y : S){
            if(hash[y]) count++;
        }
        return count;
    }
};
