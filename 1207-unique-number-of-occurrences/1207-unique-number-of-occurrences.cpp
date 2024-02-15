class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         // Map to store the frequency of each element
        unordered_map<int, int> frequencyMap;
      
        // Increment the frequency count for each element in arr
        for (int element : arr) {
            ++frequencyMap[element];
        }
      
        // Set to store unique occurrence counts
        unordered_set<int> occurrencesSet;
      
        // Iterate through the frequency map
        for (auto& keyValue : frequencyMap) {
            int occurrence = keyValue.second; // Get the occurrence/frequency count of the element
          
            // Check if the occurrence count is already in the occurrences set
            if (occurrencesSet.count(occurrence)) {
                // If already present, it's not unique and returns false
                return false;
            }
            // If not present, add the occurrence count to the set
            occurrencesSet.insert(occurrence);
        }
      
        // All occurrence counts were unique, return true
        return true;
        
    }
};