class Solution {
public:
    int hammingWeight(int n) {
        string ans ="";

        while(n>0)
        {
            int k = n%2;
           n/=2;
           ans+=k+'0';
        }

        int cnt = 0;
        for(int i=0; i<ans.size(); i++)
        {
          if(ans[i] == '1') cnt++;
        }
      return cnt ;
        
    }
};
