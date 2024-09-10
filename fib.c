#include <time.h>
#include <stdio.h>

// Author: Mauricio Curiel
// Date: 2024-09-10
// Description: Implements and benchmarks implementations of the fibonacci sequence.
// fibSkip is a solution I came up with before learning DP. I want to see how significant
// the improvement is over recursiveFib.

// Time: O(2^n)
// Space: O(n) because of the call stack
int fib(int n)
{
   int firstFew[] = {0, 1, 1};
   if (n < 3)
   {
      return firstFew[n];
   }
   else
   {
      return (fib(n - 1) + fib(n - 2));
   }
}

// Time: O(2^(n-1))
// Space: O(n) because of the call stack but, is 50% less than fib
// And the more balanced the tree is, the more efficient this
// solution is when run in parallel.
int fibSkip(int n)
{
   int firstFew[] = {0, 1, 1};
   if (n < 3)
   {
      return firstFew[n];
   }
   else
   {
      return (2 * fib(n - 2) + fib(n - 3));
   }
}

// Time: O(n)
// Space: O(n)
int fibMemo(int n)
{
   int memo[n + 1];
   memo[0] = 0;
   memo[1] = 1;
   memo[2] = 1;

   for (int i = 3; i <= n; i++)
   {
      memo[i] = memo[i - 1] + memo[i - 2];
   }

   return memo[n];
}

// Time: O(n)
// Space: O(1)
int fibMemo3(int n)
{
   int memo[3];
   memo[0] = 0;
   memo[1] = 1;
   memo[2] = 1;

   for (int i = 3; i <= n; i++)
   {
      memo[i % 3] = memo[(i - 1) % 3] + memo[(i - 2) % 3];
   }

   return memo[n % 3];
}

int main()
{
   int target = 50;

   // Benchmark fib
   printf("fib of %d\n", target);
   clock_t begin = clock();
   int x = fib(target);
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time: %f\n", time_spent);
   printf("Result: %d\n\n", x);

   // Benchmark fibSkip
   printf("fibSkip of %d\n", target);
   begin = clock();
   x = fibSkip(target);
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time: %f\n", time_spent);
   printf("Result: %d\n\n", x);

   // Benchmark fibMemo
   printf("fibMemo of %d\n", target);
   begin = clock();
   x = fibMemo(target);
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time: %f\n", time_spent);
   printf("Result: %d\n\n", x);

   // Benchmark fibMemo3
   printf("fibMemo3 of %d\n", target);
   begin = clock();
   x = fibMemo3(target);
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time: %f\n", time_spent);
   printf("Result: %d\n", x);

   return 0;
}
