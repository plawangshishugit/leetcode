class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> freqMap;
        vector<int> duplicates;

        for (int num : nums)
        {
            freqMap[num]++;
            if (freqMap[num] == 2)
            {
                duplicates.push_back(num);
            }
        }

        if (duplicates.empty())
        {
            // If no duplicates found, return an empty vector
            return {};
        }
        else
        {
            // If duplicates found, return the vector containing duplicates
            return duplicates;
        }
    }
};