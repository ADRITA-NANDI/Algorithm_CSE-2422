#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    char ch;
    int freq;
    string code;
};

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<Item> a(n);

    cout << "Enter character and frequency:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i].ch >> a[i].freq;
        a[i].code = "";
    }

    sort(a.begin(), a.end(), [](Item x, Item y){
        return x.freq < y.freq;
    });

    for (int i = 0; i < n; i++) {
        a[i].code = string(i + 1, '1');
    }

    reverse(a.begin(), a.end());

    cout << "\nHuffman-like Variable Length Codes:\n";
    for (auto &x : a) {
        cout << x.ch << ": " << x.code << endl;
    }

    return 0;
}
