# For a number x, we can observe that:
# -. If we split it into two number a, b then a*b is maximized when a = b = x / 2. If a = b = x/2 then a*b >= x whenever x >= 4
# -. Another way to see it is if we have a number x, we can split it into k and (x-k), and for k = 2 we'll get a new product 2*x - 4 and for x >= 4 this is >= x
# Whichever observation we use, the end conclusion is if we have a number x >= 4, we can always split it to get a larger product.
# Note that the first observation also implies that no two number should have difference more than 1. Hint: prove a*b >= (a-1) * (b+1) for a <= b

# Now we have a bunch of 2's and 3's, and we can't split any of them anymore. However, we can still get a larger product by merging "2, 2, 2" into "3, 3"

n = int(input())

if n == 1:
    print(1)
    exit()

num2 =  n // 2 if n % 2 == 0 else (n-3) // 2
num3 = (n % 2 != 0)
num3 += (2 * (num2 // 3))
num2 %= 3
print(2**num2 * 3**num3)