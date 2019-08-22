class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; ++i) {
            int target = -nums[i];
            if(target < 0) break;
            int front = i + 1;
            int back = len - 1;
            while(front < back) {
                int sum = nums[front] + nums[back];
                if(sum < target) front++;
                else if(sum > target) back--;
                else {
                    vector<int> triplet{nums[i], nums[front], nums[back]};
                    res.push_back(triplet);
                    // execute once in any case and ensure no duplicate
                    while(front < len && nums[front] == triplet[1]) front++;
                    while(back > 0 && nums[back] == triplet[2]) back--;
                }
            }
            // to ensure no duplicate
            while(i + 1 < len && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};