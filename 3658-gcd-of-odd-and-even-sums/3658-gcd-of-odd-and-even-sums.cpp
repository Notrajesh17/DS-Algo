class Solution {
public:
    int gcd(int a, int b) 
    {
        while (b != 0) 
        {
            int temp = a%b;
            a= b;
            b= temp;
        }

        return a;

    }

    int gcdOfOddEvenSums(int n) 
    {
        int sumOdd= n* n;
        int sumEven= n * (n + 1);
        return gcd(sumOdd, sumEven);
        
    }
};