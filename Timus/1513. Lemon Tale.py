# Denote Lemon as '0' and Banana as '1'. We will use DP.
# State -> dp[n] = number of valid ways with length n.
# Transition -> Suppose we are allowed at most k = 2 Lemon.
# -. If in the last place we want to have no '0', then we can append '1' to every valid way of length (n-1)
# -. If in the last place we want to have a single '0', then the previous place must be a '1', so we can append '10' to every valid way of length (n-2)
# -. If in the last place we want to have two '0', then we can append '100' to every valid way of length (n-3)
# So transition is dp[n] = dp[n-1] + dp[n-2] + .. dp[n-1-k]
# We can solve this in O(n) by maintaining prefix sum of dp, or we can simplify the formula a bit.
# Let's take k = 2 for example. dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
# dp[n-1] = dp[n-2] + dp[n-3] + dp[n-4]
# So dp[n] = 2*dp[n-1] - dp[n-4], or more generally dp[n] = 2*dp[n-1] - dp[n-2-k]

# Alternative way of thinking. Suppose we append both '0' and '1' at last place without caring whether it is valid or not
# Then dp[n] = 2*dp[n-1]
# The only invalid combination is when we append '0' to a string of length (n-1) that ends with k '0'.
# So we want to subtract number of string of length (n-1) that ends with k '0', how? 
# Well since we know the last k place is '0', that means the previous place (digit at position n-k-1) must be '1', the number of ways is predetermined by the first (n-2-k) digit.
# For example, how many ways string of length '6' ends with three '0'. The last four place must be '..1000', so it is equal number of ways with length 2.
# Then we get dp[n] = 2*dp[n-1] - dp[n-2-k]

n, k = map(int, input().split())
dp = [0] * (n+5)
dp[0] = 1

for i in range(1, n+1):
    dp[i] = 2 * dp[i-1]
    if i > k:
        dp[i] -= dp[max(0, i-k-2)]
print(dp[n])