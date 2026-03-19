#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

inline uint64_t factorize(uint64_t &num, uint64_t prime) {
    uint64_t exp = 0; // this function will mutate the num variable
    while (num % prime == 0) {num /= prime; exp++;}
    return exp;
}

int main(void) {
    string m_factor_str; m_factor_str.reserve(100);
    string n_factor_str; n_factor_str.reserve(100);
    string gcd_str; gcd_str.reserve(100);
    string lcm_str; lcm_str.reserve(100);
    uint64_t m_, n_;
    cin >> m_ >> n_;

    // eratosthenes sieve to generate is_prime bool map
    uint64_t max_val = max(m_, n_);
    uint64_t sieve_limit = static_cast<uint64_t>(sqrt((long double)max_val));

    vector<bool> is_prime(max_val + 1, true); // the index max_val itself is needed
    is_prime[0] = is_prime[1] = false; // trivial fact

    for (uint64_t i_ = 2; i_ <= sieve_limit; i_++) {
        if (!is_prime[i_]) {continue;} // j_ is the factor of each prime being sieved
        for (uint64_t j_ = i_*i_; j_ <= max_val; j_ += i_) {is_prime[j_] = false;}
    }

    // evaluate the boolmap while also computing the prime factorization of m_ n_
    uint64_t GCD = 1, LCM = 1; 
    for (uint64_t p_ = 2; p_ <= max_val; p_++) {
        if (!is_prime[p_]) {continue;} // skip non primes

        uint64_t m_exp = 0, n_exp = 0;
        // if either m or n is divisible by this prime, get the factorization
        if (m_ % p_ == 0) {
            m_ /= p_; // factorize will MUTATE m_ !
            m_exp = 1 + factorize(m_, p_);
        }
        if (n_ % p_ == 0) {
            n_ /= p_; // factorize will MUTATE n_ !
            n_exp = 1 + factorize(n_, p_);
        }
        // skip if both exp is 0
        if (m_exp + n_exp == 0) {continue;}
        // append strings of the factors
        if (m_exp > 0) {m_factor_str += to_string(p_) + "^" + to_string(m_exp) + "*";}
        if (n_exp > 0) {n_factor_str += to_string(p_) + "^" + to_string(n_exp) + "*";}
        // get the GCD LCM 
        uint64_t gcd_exp = min(m_exp, n_exp), lcm_exp = max(m_exp, n_exp);
        if (gcd_exp > 0) {
            gcd_str += to_string(p_) + "^" + to_string(gcd_exp) + "*";
            for (uint64_t i = 0; i < gcd_exp; i++) {GCD *= p_;}
        }
        if (lcm_exp > 0) {
            lcm_str += to_string(p_) + "^" + to_string(lcm_exp) + "*";
            for (uint64_t i = 0; i < lcm_exp; i++) {LCM *= p_;}
        } 
    }
    // pop_back is to get rid of the last "*"
    if (!m_factor_str.empty()) {m_factor_str.pop_back();} else {m_factor_str = "1";}
    if (!n_factor_str.empty()) {n_factor_str.pop_back();} else {n_factor_str = "1";}
    if (GCD > 1) {
        gcd_str.pop_back(); 
        gcd_str += " = " + to_string(GCD);
    } else {gcd_str = "1 = 1";}
    if (LCM > 1) {
        lcm_str.pop_back();
        lcm_str += " = " + to_string(LCM);
    } else {lcm_str = "1 = 1";}
    
    cout << m_factor_str << "\n";
    cout << n_factor_str << "\n";
    cout << gcd_str << "\n";
    cout << lcm_str << endl;
    return 0;
}