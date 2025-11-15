#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++)
        cin >> finish[i];

    vector<pair<int, int>> activity;
    for (int i = 0; i < n; i++)
        activity.push_back({finish[i], start[i]});

    sort(activity.begin(), activity.end());

    cout << "\nSelected activities (start, finish):\n";

    int lastFinish = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (activity[i].second >= lastFinish) {
            cout << activity[i].second << " " << activity[i].first << endl;
            lastFinish = activity[i].first;
            count++;
        }
    }

    cout << "\nMaximum number of activities: " << count << endl;

    return 0;
}

