//  https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices,finder(26),current(26),res;
        if(p.length()>s.length()) return indices;
        for(char x:p) finder[x-'a']++;
        for(int i=0;i<s.length();i++){
            if(i<p.length()) current[s.at(i)-'a']++;
            else if(i>=p.length() && s.at(i)!=s.at(i-p.length())) {
                    current[s.at(i)-'a']++;
                    current[s.at(i-p.length())-'a']--;
                }
            if(current==finder) res.push_back(i-p.length()+1);
        }
        return res;
    }
};
