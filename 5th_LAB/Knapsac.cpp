#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight,value;
};

void Knapsack(Item arr[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0){
                  dp[i][w] = 0;
            }

            else if (arr[i - 1].weight <= w){
                    dp[i][w] = max(arr[i - 1].value + dp[i - 1][w - arr[i - 1].weight],dp[i - 1][w]);
            }

            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value in Knapsack = " << dp[n][W] << endl;

    int res = dp[n][W];
    int w = W;

    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
            cout << "(" << arr[i - 1].weight << ", "<< arr[i - 1].value << ")\n";
            res -= arr[i - 1].value;
            w -= arr[i - 1].weight;
        }
    }
}

int main() {
    int n, W;

    cin >> n;

    Item arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight >> arr[i].value;
    }

    cin >> W;

    Knapsack(arr, n, W);

    return 0;
}