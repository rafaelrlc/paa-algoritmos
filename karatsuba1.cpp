#include <iostream>
#include <cmath>

using namespace std;

int contar_digitos(long long int num) {
    return num == 0 ? 1 : static_cast<int>(log10(abs(num))) + 1;
}


long long int karatsuba(long long int u, long long int v, int n) {
    if (n <= 3) {
        return u * v;
    } else {
        int k = n / 2;
        long long int p = u / pow(10, k);
        long long int q = u % static_cast<long long int>(pow(10, k));
        long long int r = v / pow(10, k);
        long long int s = v % static_cast<long long int>(pow(10, k));

        long long int pr = karatsuba(p, r, k);
        long long int qs = karatsuba(q, s, k);
        long long int y = karatsuba(p + q, r + s, k + (n % 2));
        long long int x = pr * static_cast<long long int>(pow(10, 2 * k)) + (y - pr - qs) * static_cast<long long int>(pow(10, k)) + qs;

        return x;
    }
}

int main() {
    long long int u, v;
    u = 1283618727;
    v = 238722;

    int n = max(contar_digitos(u), contar_digitos(v));

    long long int result = karatsuba(u, v, n);

    cout << "resultado: " << result << endl;

    return 0;
}