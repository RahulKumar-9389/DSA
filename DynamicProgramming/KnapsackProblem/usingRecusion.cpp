#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int ind, int W, vector<int> &wt, vector<int> &val)
{

    if (ind == 0)
    {
        if (wt[ind] <= W)
        {
            return val[ind];
        }
        else
        {
            return 0;
        }
    }

    // not take
    int notTake = 0 + solve(ind - 1, W, wt, val);

    // take
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + solve(ind - 1, W - wt[ind], wt, val);
    }

    return max(take, notTake);
}

int main()
{

    int n = 3;
    int W = 6;
    vector<int> weights = {3, 2, 5};
    vector<int> values = {30, 40, 60};

    cout << solve(n - 1, W, weights, values);

    return 0;
}