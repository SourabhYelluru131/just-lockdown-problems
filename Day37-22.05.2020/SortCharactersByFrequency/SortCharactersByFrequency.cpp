//  https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(char x:s) hash[x]++;
        for (auto it = hash.begin(); it != hash.end(); ) {
            if (!it->second) hash.erase(it++);
            else ++it;
        };
        vector<pair<char,int>> hashvec;
        for (auto it = hash.begin(); it != hash.end();it++ ) {
            int a = it->second;
            pair<char,int> newp;
            newp.first = it->first;
            newp.second = it->second;
            int i;
            for(i=0;i<hashvec.size();i++){
                if(hashvec[i].second>=a){
                    hashvec.insert(hashvec.begin() + i, newp);
                    break;
                }
            }
            if(i==hashvec.size()) hashvec.push_back(newp);
        }
        string ans="";
        for(int i=hashvec.size()-1;i>=0;i--) for(int j=0;j<hashvec[i].second;j++) ans+= hashvec[i].first;
        return ans;
    }
};
