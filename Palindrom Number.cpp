class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
         if(x < 0) return false;
        while(x > 0)
        {
            int a = x%10;
            s+=a + '0';
            x/=10;
        }

       

        for(int i=0,j=s.size()-1; i<j; i++, j--)
        {
            if(s[i] != s[j])
            {
                return false ;
            }
        }
        return true;
    }
};
