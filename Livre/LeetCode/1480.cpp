class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {

        vector<int> sum;
        int aux = 0;
        for (auto &i : nums)
        {
            aux += i;
            sum.push_back(aux);
        }

        return sum;
    };
};