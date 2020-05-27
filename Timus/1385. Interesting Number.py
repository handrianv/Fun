# There is a solution by observing pattern, but here we'll discuss a more algorithmic one.
# 
# Let's name the left half of the number as A and right half as B. So the entire number is (A * 10^n) + B.
# e.g. 1234 -> A = 12, B = 34, and the entire number is (A * 10^2) + B

# Requirement 1: A divides the entire number
# ((A * 10^n) + B) % A == 0 
# The term in parentheses is cleary 0 mod A, so we need only consider
# B % A == 0
# Which means B is a multiple of A, or it can be written as
# B = k * A, k < 10 and B < 10^n. The 2nd & 3rd condition is to force B to stay as a N digit number.

# Requirement 2: B divides the entire number
# ((A * 10^n) + B) % B == 0 
# (A * 10^n) % B == 0
# We know B = k * A, so k = 10^n. Combining this with observation from req 1, the prime factor of k must be the same as prime factor of 10^n and k < 10. So the possible values for k are:
# k = {1, 2, 4, 5, 8}
# This satisfies k < 10, but might not satisfy (A * k) < 10^n. 
# 
# The rest is implementation details. Since A < 10^n, we can find for each k number of A such that A*k < 10^n from the size of half-open interval [ceil(10^n / (k+1)), ceil(10^n / k)).
# E.g. n = 2 and k = 3 means we want to find how many number A < 100 such that A*3 < 100. The answer is every number in range [25, 34)

import math

n = int(input())
limit = 10**n

possibleK = [1, 2, 4, 5, 8]
if (limit < 1000):
    possibleK.remove(8)
if (limit < 100):
    possibleK.remove(4)

ans = 0
high = limit
prevLow = -1

# Invariant: All number A in [low, high) can be multiplied by d and still satisfy (A * d) < 10^n
for d in range(1, 10):
    low = limit // (d+1) + (limit % (d+1) != 0) # Somehow using math.ceil(limit / (d+1)) is imprecise

    # Special case for small n e.g. 10, where decreasing d might result in same low 
    if (low == prevLow):
        continue
    prevLow = low

    # How many possible k can the numbers take
    mxMult = 0
    for mult in possibleK:
        if (mult > d):
            break
        mxMult += 1

    # For each A in [low, high), we can have mxMult value for B
    ans += ((high - low) * mxMult)
    high = low

print(ans)