def solve():
    n, m = map(int, input().split())
    u = []
    for _ in range(m): u.append(int(input()))
    # for m 1xu[i] ubins to configure 1xn, THEY DONT HAVE TO BE UNIQUE?

    # Knowledge from ICPC in case Pa Yozef reads these
    # to store combination of each iteration
    memo = [0] * (n+1) # n is index 0 to n for 1xn

    # BASE CASE to config 1x0 tile is made of
    memo[0] = 1 # only 1 config of only 0 tile

    # Induction Step ? to calculate ith combination
    for i in range(1, n+1):
        for tiles in u: # each tiles size in u
            if i >= tiles: # only if the 1xi is big enough for each tiles
                # memo[i - tiles] meant to sum previous configs of i-tiles size
                # memo[i] meant to sum all possible configs for all tiles
                memo[i] = (memo[i] + memo[i - tiles]) % 1000000007

    # result would be located at index n
    print(memo[n])

solve()
# # generate basecases(bc)
# max_bc = max(u)
# memo = [0] * max_bc
# for n in range(max_bc):
#     # HOW DO I GENERATE THE BASE CASES
#     pass

# # calculate to n
# for i in range(max_bc+1, n+1):
#     memo[i % max_bc] = sum(memo)

# # final result is located at n % max_bc
# print(memo[n % max_bc] % 1000000007)