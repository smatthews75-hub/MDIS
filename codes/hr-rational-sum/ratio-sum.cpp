#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(void) {
    uint64_t  a_, b_;
    __uint128_t prev_a, prev_b, GCD, LCM;
    uint16_t  n_, n_loop; cin >> n_;

    cin >> a_ >> b_; // get the first ratio
    prev_a = a_; prev_b = b_;
    n_loop = n_ - 1; // loop through all ratio
    for (uint16_t i_ = 0; i_ < n_loop; i_++) {
        cin >> a_ >> b_; // get ratio
        // use LCM to minimize denominator growth maybe
        LCM = (prev_b / __gcd((uint64_t)prev_b, b_)) * b_; // think !
        prev_a = prev_a*(LCM / prev_b) + a_*(LCM / b_);
        prev_b = LCM;
        // reduce
        GCD = __gcd(prev_a, prev_b);
        prev_a /= GCD; prev_b /= GCD;
    }
    cout << (uint64_t)prev_a << " " << (uint64_t)prev_b << endl;
    return 0;
}