class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 3) return 0;
        std::sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        if(res == target) return target;
        for(int i = 0; i < len - 2; ++i) {
            int front = i + 1, back = len - 1;
            while(front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if(sum == target) return target;
                if(abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if(sum < target) front++;
                else if(sum > target) back--;
            }
        }
        return res;
    }
};