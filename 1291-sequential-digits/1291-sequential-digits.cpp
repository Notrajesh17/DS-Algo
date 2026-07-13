class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>ans;

        for(int start = 1; start <= 9; start++) 
        {
            int num = start;
            int nextDigit = start + 1;

            while (nextDigit <= 9) 
            {
                num= num * 10 + nextDigit;

                if (num >= low && num <= high) 
                {
                    ans.push_back(num);
                }
                nextDigit++;

            }
        }

        sort(ans.begin(), ans.end());


        return ans;   


    }
};