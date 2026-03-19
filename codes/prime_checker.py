prev, next = map(int, input().split())

def check_prime(num):
    if num == 2 or num == 3: return True
    if num < 2 or num % 2 == 0 or num % 3 == 0: return False
    divisor = 5
    while (divisor * divisor <= num):
        if num % divisor == 0 or num % (divisor + 2) == 0: return False
        divisor += 6
    return True

import math
def generate_primes(low = 0, high = 1000):
    is_prime = [True] * high
    is_prime[0] = is_prime[1] = False
    for num in range(2, math.isqrt(high) + 1):
        if is_prime[num]:
            for factors in range(num*num, high, num): is_prime[factors] = False
    return [num for num in range(max(2, low), high) if is_prime[num]]



print(generate_primes(prev, next))
print("YES" if check_prime(prev) else "NO")
print("YES" if check_prime(next) else "NO")
print("YES" if (check_prime(prev) and check_prime(next)) else "NO")