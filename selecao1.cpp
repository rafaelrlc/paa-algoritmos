#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int selecao(vector<int>& S, int k) {
    
    if (S.size() < 7) {
        sort(S.begin(), S.end());
        return S[k - 1];
    }
    else {
        vector<int> M;
        for (size_t i = 0; i < S.size(); i += 5) {
            vector<int> subSeq(S.begin() + i, S.begin() + min(i + 5, S.size()));
            sort(subSeq.begin(), subSeq.end());
            M.push_back(subSeq[subSeq.size() / 2]);
        }
    
        int m = selecao(M, M.size() / 2);
    
        vector<int> S1, S2, S3;
        for (int num : S) {
            if (num < m) S1.push_back(num);
            else if (num == m) S2.push_back(num);
            else S3.push_back(num);
        }
    
        if (S1.size() >= k) return selecao(S1, k);
         
        else {
            if (S1.size() + S2.size() >= k) return m;
            else return selecao(S3, k - S1.size() - S2.size());
        }
    }
}



int main() {
    vector<int> S =  {3, 5, 6, 7, 88, 44, 5, 1, 6, 9, 2, 5};
    int k = 9;
    int resultado = selecao(S, k);
    cout << "O " << k << "-ésimo menor elemento é: " << resultado << endl;

    return 0;
}
