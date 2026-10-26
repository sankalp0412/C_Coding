#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return optimalBS(nums1,nums2);
    }
    double bruteForce(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        vector<int> temp;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
            temp.push_back(nums1[i++]);
        while (j < n)
            temp.push_back(nums2[j++]);
        // 1 2 3 4 5 6
        if (temp.size() % 2 == 0)
        {
            // even
            int len = temp.size();
            int x = temp[len / 2];
            int y = temp[(len / 2) - 1];

            return ((x + y) / 2.0);
        }
        return temp[temp.size() / 2];
    }
    double better(vector<int> &nums1, vector<int> &nums2)
    {
        // at the end we just need the middle index in case of odd
        //  and middle two index in case of even
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        int sz = m + n;
        int idx1 = (sz / 2) - 1, idx2 = sz / 2, elem1 = -1, elem2 = -1;

        int k = 0;

        while (i < j)
        {
            if (nums1[i] < nums2[j])
            {
                if (k == idx1)
                    elem1 = nums1[i];

                if (k == idx2)
                    elem2 = nums1[i];
                i++;
            }
            else
            {
                if (k == idx1)
                    elem1 = nums2[j];

                if (k == idx2)
                    elem2 = nums2[j];
                j++;
            }
            k++;
        }

        while (i < m)
        {
            if (k == idx1)
                elem1 = nums1[i];

            if (k == idx2)
                elem2 = nums1[i];
            i++;
        }
        while (j < n)
        {
            if (k == idx1)
                elem1 = nums2[j];

            if (k == idx2)
                elem2 = nums2[j];
            j++;
        }

        if(sz % 2 == 0) {
            return (elem1+elem2)/2.0;
        }
        return elem2;
    }


    double optimalBS(vector<int> &nums1, vector<int> &nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int m = nums1.size();
        int n = nums2.size();
        int l = 0, r = m;

        while(l <= r) {
            int px = l + (r-l)/2; //number of elemenst in the left half from nums1
            int py = (m + n + 1)/2 - px;

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];

            if(x1 <= x4 && x2 <= x3) {
               if((m + n) % 2 == 1) return max(x1,x2);
               return (max(x1,x2) + min(x3,x4))/2.0;
            }
            if(x1 > x4) 
                r = px - 1;
            else 
                l = px + 1;
        }
        return -1;
    }
};


int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};
    Solution sol;
    cout << sol.findMedianSortedArrays(arr1, arr2);
    return 0;
}