//   https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int last = 0;
        for(int i=0;i<nums1.size();i++){
            for(int j=last;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+j);
                    last=j;
                    break;
                }
                if(nums2[j]>nums1[i]){         //Since array is sorted, no use of iterating over more elements
                    last=j;
                    break;
                }
            }
        }
        return ans;
    }
};
