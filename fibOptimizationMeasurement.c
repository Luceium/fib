#include <stdio.h>

// Author: Mauricio Curiel
// Date: 2024-09-10
// Description: Helps analyze fibSkip to understand the difference between fibSkip and recursive fib.
// The methodology is to collect data points of how many recursive calls are made and the depth of
// the call tree for each n from 0 to 50.

void fibNodes(int n, int memo[])
{
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2] + 1;
    }
}

void fibSkipNodes(int n, int memo[])
{
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        memo[i] = memo[i - 2] + memo[i - 3] + 1;
    }
}

int main()
{
    int n = 44;
    int nodes[n + 1];
    fibNodes(n, nodes);
    int skipNodes[n + 1];
    fibSkipNodes(n, skipNodes);

    for (int i = 2; i <= n; i++)
    {
        printf("fib-%d: nodes %d, depth %d\n", i, nodes[i], i - 2);
        printf("fibSkip-%d: nodes %d, depth %d\n", i, skipNodes[i], (i - 2) / 2);
        printf("Nodes: diff %d, reduction %.2f%%\n", nodes[i] - skipNodes[i], (nodes[i] - skipNodes[i]) / ((float)nodes[i]));
    }
    return 0;
}
