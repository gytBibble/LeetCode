class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            // the nums[i] is too large
            if(4 * nums[i] > target) return res;
            else if( 4 * nums[i] == target) {
                if(i + 3 && nums[i] == nums[i + 3]) res.push_back(vector<int>(4, nums[i]));
                break;
            }
            // find the threeSum
            vector<vector<int>> threeRes = threeSum(nums, i + 1, target - nums[i]);
            for(int j = 0; j < threeRes.size(); ++j) {
                res.push_back(vector<int>{nums[i], threeRes[j][0], threeRes[j][1], threeRes[j][2]});
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int begin, int target) {
        int len = nums.size() - begin;
        vector<vector<int>> res;
        if(len < 3) return res;
        for(int i = begin; i < nums.size() - 2; ++i) {
            if(i > begin && nums[i] == nums[i - 1]) continue;
            if(3 * nums[i] > target) return res;
            else if(3 * nums[i] == target) {
                if(i + 2 && nums[i] == nums[i + 2]) res.push_back(vector(3, nums[i]));
                break;
            }
            // find the twoSum
            int front = i + 1, back = nums.size() - 1;
            while(front < back) {
                int sum = nums[front] + nums[back];
                if(sum < target - nums[i]) front++;
                else if(sum > target -nums[i]) back--;
                else {
                    res.push_back(vector<int>{nums[i], nums[front], nums[back]});
                    while(front + 1 < nums.size() && nums[front + 1] == nums[front]) front++;
                    while(back - 1 > i && nums[back - 1] == nums[back]) back--;
                    front++;
                    back--;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};