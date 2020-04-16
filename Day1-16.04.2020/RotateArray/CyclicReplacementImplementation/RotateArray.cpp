class Solution {
public:
    void rotate(vector<int>& nums, int k) {    // Cyclic Replacement
        int n = nums.size();
        int cnt = 0;          // cnt is the number of elements in the right place
        for(int i=0;cnt<n;i++)   // runs until n elements are in right place
        {
            int temp,first,first_value,beg,second;
            first = i;
            first_value = nums[i];
            do{
                second = (first+k)%n;
                temp = nums[second];
                nums[second] = first_value;
                first_value = temp;
                first = second;
                cnt++;
            }while(first!=i) ;  // first one when first==i
        }
    }
};
