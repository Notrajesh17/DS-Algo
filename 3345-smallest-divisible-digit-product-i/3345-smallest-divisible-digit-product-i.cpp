class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        while (true) 
        {
            long long product = 1;
            int x = n;

            if (x == 0) product = 0;

            while (x > 0) 
            {
                product *= (x % 10);
                x /= 10;
                if (product == 0) break;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};