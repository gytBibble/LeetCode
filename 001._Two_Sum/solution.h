// 1

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
        if(nums.size() <= 1)
            return vector<int>{};
        for(int i = 0; i < nums.size() - 1; ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        return vector<int>{};
    }
};

// 2
class Solution {
public:
    vector<int> twoSum_2(vector<int>& nums, int target) {
        unordered_map<int, int> map_;
        // insert key-val to map
        for(int i = 0; i < nums.size(); ++i) {
            map_.insert({nums[i], i});
        }
        // find
        for(int i = 0; i < nums.size(); ++i) {
            auto j = map_.find(target - nums[i]);
            if(j != map_.end() && j->second != i)
                return vector<int>{i, j->second};
        }
        return vector<int>{};
    }
};

// 3
class Solution {
public:
    vector<int> twoSum_3(vector<int>& nums, int target) {
        unordered_map<int, int> map_;
        // insert key-val to map and find
        for(int i = 0; i < nums.size(); ++i) {
            map_.insert({nums[i], i});
            auto j = map_.find(target - nums[i]);
            if(j != map_.end() && j->second != i)
                return vector<int>{i, j->second};
        }
        return vector<int>{};
    }
};