#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void imprimir_solucao(vector<vector<int>>& s, int i, int j) {
    if (i == j)
        cout << " M" << i << " ";
    else {
        cout << "(";
        imprimir_solucao(s, i, s[i][j]);
        imprimir_solucao(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void ProgDinMatr(vector<int>& P) {
    int n = P.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
 
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int g = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (g < m[i][j]) {
                    m[i][j] = g;
                    s[i][j] = k;
                }
            }
        }
    }
    
    cout << "Multiplicação Ótima: ";
    imprimir_solucao(s, 1, n);
    cout << endl;
    
}

int main() {
    vector<int> P = {20, 30, 45, 10, 30, 25, 40, 35};

    ProgDinMatr(P);
    return 0;
}
