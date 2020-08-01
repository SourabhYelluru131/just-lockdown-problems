//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int x:nums) hash[x]++;
        vector<pair<int, int>> elems(hash.begin(), hash.end());
        sort(elems.begin(), elems.end(),[this] (pair<int,int> a, pair<int,int> b) {
    return comp(a, b); });;
        int i=0;
        vector<int> sol;
        for(auto it:elems){
            i++;
            if(i<=k) sol.push_back(it.first);
            else break;
        }
        return sol;
    }
};
