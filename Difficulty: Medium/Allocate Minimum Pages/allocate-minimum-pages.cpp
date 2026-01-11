class Solution {
  public:
  int countStudent(vector<int>&arr, int page){
      int student = 1;
      long long pageStudent = 0;
      for (int i = 0; i<arr.size(); i++){
          if(pageStudent + arr[i] <= page){
              pageStudent += arr[i];
          }else{
              student += 1;
              pageStudent = arr[i];
          }
      }
      return student;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int len = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(),0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int student = countStudent(arr, mid);
            if(student > k){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return low;
    }
};