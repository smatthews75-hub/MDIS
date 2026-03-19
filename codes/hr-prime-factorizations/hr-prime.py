def gen_primes(low=2, high=500_000):
    high += 1
    is_prime = [True] * high
    is_prime[0], is_prime[1] = False, False
    for i in range(2, int(high**0.5) + 1):
        if not is_prime[i]: continue
        for i_factors in range(i*i, high, i): is_prime[i_factors] = False
    return [i for i in range(min(2, low), high) if is_prime[i]]

def factors(n:int, primes:list):
    factors = [[i, 0] for i in primes]
    for i in range(len(primes)):
        exponent = 0
        prime = primes[i]
        while n % prime == 0:
            n //= prime
            exponent += 1
        if exponent > 0: factors[i][1] = exponent
    return factors

def print_factors(factors:list):
    buffer = []
    for i in range(len(factors)):
        prime, exponent = factors[i]
        if exponent == 0 : continue
        buffer.append(f"{prime}^{exponent}")
    n = len(buffer)
    n_last = n-1
    for i in range(n):
        print(buffer[i], end="*" if i < n_last else"\n")


def print_GCD_LCM(m_factors:list, n_factors:list, mode:int):
    result = 1
    buffer = []
    for i in range(len(m_factors)):
        m, m_exp = m_factors[i]
        n, n_exp = n_factors[i]
        min_exp = min(m_exp, n_exp) if mode == 1 else max(m_exp, n_exp)
        if min_exp == 0: continue
        result *= m**min_exp
        buffer.append(f"{m}^{min_exp}")
    n = len(buffer)
    if n > 0 :
        n_last = n-1
        for i in range(n):
            print(buffer[i], end="*" if i < n_last else"")
    else : print(result, end='')
    print(f" = {result}")

m = int(input())
n = int(input())
primes = gen_primes(high=max(m,n))
m_factors = factors(m, primes)
n_factors = factors(n, primes)
print_factors(m_factors)
print_factors(n_factors)
print_GCD_LCM(m_factors, n_factors, 1)
print_GCD_LCM(m_factors, n_factors, 0)