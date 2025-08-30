#include <iostream>
using namespace std;

int main() {
    int r1, c1, n1;
    cin >> r1 >> c1 >> n1;
    int a[n1][3];
    for (int i = 0; i < n1; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    int r2, c2, n2;
    cin >> r2 >> c2 >> n2;
    if (c1 != r2) return 0;
    int b[n2][3];
    for (int i = 0; i < n2; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    int s[n1 * n2][3];
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i][1] == b[j][0]) {
                int r = a[i][0];
                int c = b[j][1];
                int val = a[i][2] * b[j][2];

                bool found = false;
                for (int p = 0; p < k; p++) {
                    if (s[p][0] == r && s[p][1] == c) {
                        s[p][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    s[k][0] = r;
                    s[k][1] = c;
                    s[k][2] = val;
                    k++;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;

    return 0;
}
