#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>

using namespace std;

// due to hackerrank not supporting arbitrary precision library for C++
// this C++ implementation is limited to the maximum performance of __uint128_t
// which regardless is insufficient for the massive numbers in the test cases..

// custom big string printer
inline string big_print(__uint128_t x_) {
    if (x_ == 0) {return "0";}
    string s_; s_.reserve(100);
    while (x_ > 0) {
        s_.push_back('0' + (int)(x_ % 10));//ascii integer
        x_ /= 10;// cut the last digit
    }// note the stored string is in reverse so esrever it back
    reverse(s_.begin(), s_.end());
    return s_;
}

// custom gcd to handle super-massive numbers muse reference
inline __uint128_t gcd128(__uint128_t a_, __uint128_t b_) {
    __uint128_t tmp;
    while (b_ != 0) { // ensures no 0 division error
        tmp = a_ % b_;// b is quaranteed non zero
        a_ = b_;
        b_ = tmp;
    } return a_;
}

int main(void) {
    uint64_t  a_buffer, b_buffer;
    __uint128_t prev_a, prev_b, GCD, LCM, a_, b_;
    uint16_t  n_; cin >> n_;

    cin >> a_buffer >> b_buffer; // get the first ratio
    prev_a = a_buffer; prev_b = b_buffer;
    n_--; // loop through all ratio
    for (uint16_t i_ = 0; i_ < n_; i_++) {
        cin >> a_buffer >> b_buffer; // get ratio
        a_ = a_buffer; b_ = b_buffer;
        // use LCM to minimize denominator growth maybe
        LCM = (prev_b / gcd128(prev_b, b_)) * b_; // think !
        prev_a = prev_a*(LCM / prev_b) + a_*(LCM / b_);
        prev_b = LCM;
        // reduce
        GCD = gcd128(prev_a, prev_b);
        prev_a /= GCD; prev_b /= GCD;
    }
    cout << big_print(prev_a) << " " << big_print(prev_b) << endl;
    return 0;
}