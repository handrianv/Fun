# Classic subset sum. Pardon the shitty python code :(

n, s = [int(x) for x in input().split()]

if s%2 != 0:
	print(0);
	exit();

dp = [0] * 505;
dp[0] = 1;

for i in range(1, n+1):
	for sum in range(9*i, -1, -1):
		for d in range(1, 10):
			if d > sum:
				continue;
			dp[sum] += dp[sum-d];
			
print(dp[s//2] * dp[s//2])