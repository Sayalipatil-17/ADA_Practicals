int fib_top_down(int n, int memo[]) {
if (n == 0) return 0;
if (n == 1) return 1;
if (memo[n] != -1) return memo[n];
memo[n] = fib_top_down(n - 1, memo) + fib_top_down(n - 2, memo);
return memo[n];
}