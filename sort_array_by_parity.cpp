/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.


*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {

        vector<int> even;
        vector<int> odd;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
        }

        even.insert(even.end(), odd.begin(), odd.end());

        return even;
    }
};