//  https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        if(target>nums[nums.size()-1]) return nums.size();
        int l=0,h=nums.size()-1;
        int mid = nums.size()/2;
        while(l<h){
            if(nums[mid]<target) l=mid+1;
            else{
                if(nums[mid]!=target) h = mid-1;
                else return mid;
            }
            mid = (l+h)/2;
            if(nums[l]>target) return l;
            if(nums[h]<target) return h+1;
        }
        return h;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,target);
    }
};
