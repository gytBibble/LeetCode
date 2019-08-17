class Solution_1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int len = n + m;
        if(len % 2 == 1)
            return (double) getK(nums1, 0, n - 1, nums2, 0, m - 1, (len + 1) / 2);
        else
            return ((double) (getK(nums1, 0, n - 1, nums2, 0, m - 1, (len + 1) / 2) + getK(nums1, 0, n - 1, nums2, 0, m - 1, (len / 2) + 1))) * 0.5;
    }
                    
    // get the Kth num
    double getK(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1, len2 = end2 -start2 + 1;
        if(len1 == 0)
            return nums2[start2 + k - 1];
        else if(len2 == 0)
            return nums1[start1 + k - 1];
        else if(k == 1)
            return min(nums1[start1], nums2[start2]);
        else {
            // consider the len of array less than k/2
            int i = start1 + min(len1, k / 2) - 1;
            int j = start2 + min(len2, k / 2) - 1;
            if(nums1[i] > nums2[j])
                return getK(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
            else
                return getK(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};

class Solution_2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if(n == 0) { // empty
            return 0;
        }
        
        // i + j == m - i + n - j + 1
        // nums2[j - 1] <= nums1[i] && nums1[i - 1] <= nums2[j]
        
        int i_min = 0, i_max = m, half_len = (m + n + 1) / 2;
        while(i_min <= i_max) {
            // binary search
            int i = (i_min + i_max) / 2;
            int j = half_len - i;
            if(i < m && nums2[j - 1] > nums1[i]) {
                // i is too small
                i_min = i + 1;
            }
            else if(i > 0 && nums1[i - 1] > nums2[j]) {
                // i is too big
                i_max = i - 1;
            }
            else {
                // perfect
                double max_left, min_right;
                if(i == 0) {
                    max_left = nums2[j - 1];
                }
                else if(j == 0) {
                    max_left = nums1[i - 1];
                }
                else {
                    max_left = max(nums1[i - 1], nums2[j - 1]);
                }
                if((m + n) % 2 == 1) {
                    return max_left;
                }
                if(i == m) {
                    min_right = nums2[j];
                }
                else if(j == n) {
                    min_right = nums1[i];
                }
                else {
                    min_right = min(nums1[i], nums2[j]);
                }
                return (double)(max_left + min_right) * 0.5;
            }
        }
        return 0;
    }
};