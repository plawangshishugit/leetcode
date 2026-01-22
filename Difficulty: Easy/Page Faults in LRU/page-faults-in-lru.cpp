// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        if(C==0) return N;
        list<int>l;
        unordered_map<int, list<int>::iterator>mp;
        int pf = 0;
        for(int i =0; i<N; i++)
        {
            // if page is not found
            if(mp.find(pages[i]) == mp.end()){
                pf += 1;
                // check if the cache is full or not
                if(l.size() == C){
                    int pgrmv = l.front();
                    //remove it from map first
                    mp.erase(pgrmv);
                    //remove it from list too
                    l.pop_front();
                }
            }
            // if page is found
            else{
                //only have to remove the list first element and insert the current page we are having
                l.erase(mp[pages[i]]);
            }
            
            //do this always
            // Insert current page as MRU 
            l.push_back(pages[i]); 
            mp[pages[i]] = --l.end();
        }
        return pf;
    }
};