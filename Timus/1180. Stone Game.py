
# Let's work out some base case first. W means a winning position and L is losing.
# [0] = L --> Default losing position
# [1] = W --> It can get to [0], a losing position for the next player
# [2] = W --> It can get to [0], a losing position for the next player
# [3] = L --> Every next position from this position is winning for the next player
# [4] = W --> It can get to [0] or [3], a losing position for the next player
# [5] = W --> It can get to [3], a losing position for the next player
# [6] = L --> Every next position from this position is winning for the next player
# [7] = W --> It can get to [3] or [6], a losing position for the next player
# [8] = W --> It can get to [0] or [6], a losing position for the next player
# [9] = L --> Every next position from this position is winning for the next player
# [10] = W --> It can get to [6] or [9], a losing position for the next player

# Now it would seem that every multiple of 3 (including 0) is a losing position.
# Proof: 
# From a position [n] where [n] mod 3 == 0, the next position [m] cannot have [m] % 3 == 0. 
# The observation is that powers of two modulo 3 is cyclic and doesn't contain zero
# Starting from 2^0 mod 3, the residue is {1, 2, 1, 2, 1, 2, ...}. So from position where [n] % 3 == 0, you can only reduce the residue by 1 or 2, but not 3

# From a position [n] where [n] mod 3 != 0, we can always get to position [m] where [m] % 3 == 0
# To do this we simply subtract [n] mod 3, which is always a power of two (either 1 or 2).
# Now the winning strategy is to simply force the opposing player to be in position [n] where [n] mod 3 == 0. Eventually he/she will get to position where [n] mod 3 == 0 and [n] is [0].

# You can also use Sprague Grundy Theorem to solve this (or at least, to see the winning pattern)

n = int(input())
if n % 3 == 0:
    print(2)
else:
    print(1)
    print(n%3)