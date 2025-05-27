#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution 
{
    // Use long long to safely accumulate large hour values
    long long calculateHrs(vector<int>& piles, int banana)
    {
        long long hrs = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // Ensure proper division and casting
            hrs += (piles[i] + banana - 1LL) / banana; // avoids ceil
        }
        return hrs;
    }    

public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long hrs = calculateHrs(piles, mid);

            if (hrs <= h)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};
