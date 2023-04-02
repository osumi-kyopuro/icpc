#include <iostream>
#include <vector>
using namespace std;

// マス m に印をつけるまでの操作回数を求める関数
long long count_steps(long long n, long long d, long long m) {
    long long x = 0;  // 最初のマスは 0
    long long steps = 1;  // 最初の印をつける操作を行ったので、1からカウントする
    while (x != m) {
        x = (x + d) % n;  // x を更新する
        steps++;  // 操作回数を増やす
        if (x == m) {
            // マス m に到達した場合、操作回数を返して終了する
            return steps;
        }
        long long delta = (m - x + n) % n;
        if (delta < d) {
            // delta < d の場合、m に到達するまで x を右に移動する
            steps += delta;
            x = m;
        } else {
            // delta >= d の場合、d だけ x を右に移動する
            x += d;
            steps += d;
        }
        x %= n;
    }
    return steps;
}

int main() {
    std::ios::sync_with_stdio(false); // 入出力を高速化する
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n, k, d;
        cin >> n >> k >> d;
        // 二分探索を行う
        long long left = 0, right = n - 1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (count_steps(n, d, mid) >= k) {
                // mid 以前のマスには k 個未満の印しかつかない
                right = mid - 1;
            } else {
                // mid より後ろのマスには k 個以上の印がつく
                left = mid + 1;
            }
        }
        cout << left << "\n";
    }
    return 0;
}
