class Solution_1 { // Brute Force
public:
    int maxArea(vector<int>& height) {
        int mWater = 0;
        for(int i = 0; i < height.size(); ++i) {
            for(int j = i + 1; j < height.size(); ++j) {
                mWater = max(mWater, (j - i) * min(height[i], height[j]));
            }
        }
        return mWater;
    }
};

class Solution_2 {
public:
    int maxArea(vector<int>& height) {
        int mWater = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            if(height[i] < height[j]) {
                mWater = max(mWater, (j - i) * height[i]);
                i++;
            }
            else {
                mWater = max(mWater, (j - i) * height[j]);
                j--;
            }
        }
        return mWater;
    }
};