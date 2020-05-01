//  https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int find_firstBad(int l, int r){  // Kind of Binary Search
        int mid = l/2 + r/2;
        if(l%2 && r%2) mid++;
        if(l==r && !isBadVersion(mid)) return mid+1;
        if(isBadVersion(mid)){
            if(mid==l) return l;
            if(l==r){
                return mid;
            }
            return find_firstBad(l, mid-1);
        }
        else return find_firstBad(mid+1, r);
    }
public:
    int firstBadVersion(int n) {
        return find_firstBad(1,n);
    }
};
