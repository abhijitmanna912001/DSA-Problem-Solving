#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        // Total food required to survive for S days
        int totalFoodRequired = S * M;

        // Check if survival is impossible
        // Weekly food requirement vs max purchasable food for 6 days
        int weeklyFoodRequirement = 7 * M;
        int maxWeeklyFoodPurchasable = 6 * N;

        if ((weeklyFoodRequirement > maxWeeklyFoodPurchasable && S > 6) || M > N)
        {
            // Impossible to survive if:
            // - Weekly requirement exceeds max purchasable for a week (when S > 6)
            // - Daily requirement exceeds max purchasable in one day
            return -1;
        }

        // Calculate minimum days to buy food
        if (totalFoodRequired % N == 0)
        {
            // Exact division: no extra day needed
            return totalFoodRequired / N;
        }
        else
        {
            // Extra day needed to cover the remainder
            return (totalFoodRequired / N) + 1;
        }
    }
};

int main()
{

    return 0;
}