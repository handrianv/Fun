# To satisfy the equation, the sum of Ai + Bi must not have any carry, where Ai is the i'th digit of A.
# Then for every i'th digit we have 55 possibility, except the first digit which have only 36 because it can't be zero

k = int(input())
print((55**(k-1))*36)