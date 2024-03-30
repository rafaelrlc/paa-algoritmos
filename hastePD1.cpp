#include <iostream>
#include <vector>

using namespace std;

pair<int, vector<int>> HastePD(vector<int> p, int n) {
    vector<int> r(n + 1, -9999999);
    vector<int> s(n + 1, 0);
    
    r[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (r[i] < p[j] + r[i - j]) {
                r[i] = p[j] + r[i - j];
                s[i] = j;
            }
        }
    }

    return make_pair(r[n], s);
}

int main() {
    vector<int> p = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = p.size() - 1;

    pair<int, vector<int>> result = HastePD(p, n);

    cout << "Maior val: " << result.first << endl;
    
    // cout << "Tamanhos das hastes cortadas: ";
    
    // while (n > 0) {
    // cout << result.second[n] << " ";
    // n -= result.second[n];
    // }


    return 0;
}
