class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n > m) {
            swap(a, b);
            swap(n, m);
        }
        int low = 0, high = n;
        int totalLeft = (n + m + 1) >> 1;
        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = totalLeft - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) & 1)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) * 0.5;
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0; 
    }
};