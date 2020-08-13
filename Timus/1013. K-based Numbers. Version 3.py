#
#    Tutorial on matrix exponentiation for solving linear recurrence:
#    https://www.youtube.com/watch?v=eMXNWcbw75E
#
#    In this problem, the recurrence is: f(n) = (k-1)*f(n-2) + (k-1)*f(n-1)
#    So we can use tranformation Matrix T(2x2) = [0 (k-1)]
#                                                [1 (k-1)]
#    and base matrix (1x2) = [1 (k-1)].
#    Then compute base * T^(n-1).

MAXN = 2
n = int(input()); k = int(input()); MOD = int(input())

def MatMul(a, b):
    ans = [[0 for x in range(MAXN)] for y in range(MAXN)]

    for i in range (MAXN):
        for j in range(MAXN):
            for kk in range(MAXN):
                temp = ((a[i][kk] % MOD) * (b[kk][j] % MOD)) % MOD
                ans[i][j] = (ans[i][j] + temp) % MOD
    return ans


def MatPow(base, p):
    ans = [[0 for x in range(MAXN)] for y in range(MAXN)]

    for i in range(MAXN):
        ans[i][i] = 1

    while(p > 0):
        if(p % 2 == 1):
            ans = MatMul(ans, base)
        base = MatMul(base, base)
        p //= 2

    return ans


t = [[0 for x in range(MAXN)] for y in range(MAXN)]
t[0][0] = 0; t[0][1] = (k-1)
t[1][0] = 1; t[1][1] = (k-1)

base = [[0 for x in range(MAXN)] for y in range(MAXN)]
base[0][0] = 1; base[0][1] = (k-1)

ans = MatMul(base, MatPow(t, n-1))
print(ans[0][1]);