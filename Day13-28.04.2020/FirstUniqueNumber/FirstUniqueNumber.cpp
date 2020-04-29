//    https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/
class FirstUnique {
    unordered_map<int, list<int>::iterator> _map;
    list<int> _keys;
public:
    FirstUnique(vector<int>& nums) {
        for(int n : nums){
            add(n);
        }
    }
    
    int showFirstUnique() {
        if(_keys.size()){
            return _keys.front();
        }
        return -1;
    }
    
    void add(int value) {
        if(_map.find(value)!=_map.end()){
            list<int>::iterator it = _map[value];
            if(it!=_keys.end()){
                _keys.erase(it);
                _map[value]=_keys.end();
            }
        }
        else{
            _keys.push_back(value);
            list<int>::iterator it = _keys.end();
            it--;
            _map[value]=it;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
