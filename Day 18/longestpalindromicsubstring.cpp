//https://www.codingninjas.com/studio/problems/day-12-longest-palindromic-substring_8230702?challengeSlug=striver-sde-challenge&leftPanelTab=1

string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.length();
    int start=0;
    int maxLen=1;

    for(int i=0;i<n;i++)
    {
    //odd length
    int l=i;
    int r=i;
    while(str[l]==str[r] && l>=0 && r<n)
    {
        if(r-l+1>maxLen)
        {
            maxLen=r-l+1;
            start=l;
        }
        l--;
        r++;
    }
    //even
     l=i;
     r=i+1;
    while(str[l]==str[r] && l>=0 && r<n)
    {
      if (r - l + 1 > maxLen) {
        maxLen = r - l + 1;
        start = l;
      }
      l--;
      r++;
    }
    }
    return str.substr(start,maxLen);
    

    



}