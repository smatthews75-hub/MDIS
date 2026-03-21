from math import gcd
n = int(input()) - 1

# python's arbitrary precision integers were required to pass 100% of TestCases
# due to extremely large computations on the last 10 TestCases in Hackerrank...
prev_a, prev_b = map(int, input().split())
for _ in range(n):
    a_, b_ = map(int, input().split())
    # use LCM to minimize denominator growth maybe
    LCM = (prev_b // gcd(prev_b, b_)) * b_;
    prev_a = prev_a*(LCM // prev_b) + a_*(LCM // b_);
    prev_b = LCM;
    # reduce
    GCD = gcd(prev_a, prev_b);
    prev_a //= GCD; prev_b //= GCD;
print(prev_a, prev_b)