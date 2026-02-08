class Solution {
public:
    bool rotateString(string s, string goal) {
        // //brute force
        int m = s.length();
        int n = goal.length ();

        //check if both length is equal or not?if not return false
        if( m != n) return false;
        // for(int cnt = 0; cnt <m; cnt++){
        //     if(s == goal) return true;
        //     rotate(s.begin(), s.begin()+1, s.end());
        // }
        // return false;

        //optimized solution
        // observe that string s ko maximum s.length() baar rotate ke dene ke baad wahi milta hai to hm s mein se s ko hi concatinate kr de dekhte hain ki concatinated string mein s ke sare rotation mil jate hain to is problem mein hm concatinated string mein goal ko find() kr sakte hain if yes return true otherwise return false;
        if((s+s).find(goal) != string :: npos){
            return true;
        }
        return false;
    }
};
//rotate ka syntax
// rotate(start index of the string segment, which postition will become starting position of the range, last index of the string segment which we have to rotate)
//to ismein hoga s.begin()+1 
//rotate(s.begin(), s.begin()+1, s.end());