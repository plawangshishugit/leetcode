class Solution {
public:
    bool rotateString(string s, string goal) {
        //brute force
        int m = s.length();
        int n = goal.length ();

        //check if both length is equal or not?if not return false
        if( m != n) return false;
        for(int cnt = 0; cnt <m; cnt++){
            if(s == goal) return true;
            rotate(s.begin(), s.begin()+1, s.end());
        }
        return false;

    }
};
//rotate ka syntax
// rotate(start index of the string segment, which postition will become starting position of the range, last index of the string segment which we have to rotate)
//to ismein hoga s.begin()+1 
//rotate(s.begin(), s.begin()+1, s.end());