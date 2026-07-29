class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;

        int temp=x;
        long long number=0;

        while(temp>0)
        {
            int digit = temp%10;
            number = number*10 + digit;
            temp = temp/10;
        }

        return number==x;
        
    }
};