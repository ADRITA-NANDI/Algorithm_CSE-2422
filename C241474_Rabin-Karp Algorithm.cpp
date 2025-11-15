#include <iostream>
using namespace std;

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();

    int base = 256;
    int mod = 101;

    int patHash = 0, winHash = 0, h = 1;


    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;


    for (int i = 0; i < m; i++) {
        patHash = (base * patHash + pattern[i]) % mod;
        winHash = (base * winHash + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {

        if (patHash == winHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index: " << i << endl;
        }


        if (i < n - m) {
            winHash = (base * (winHash - text[i] * h) + text[i + m]) % mod;

            if (winHash < 0)
                winHash += mod;
        }
    }

    return 0;
}

