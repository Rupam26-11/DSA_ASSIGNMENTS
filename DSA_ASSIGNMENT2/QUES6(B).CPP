#include <iostream>
using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    int a[n][3];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int r1, c1, n1;
    cin >> r1 >> c1 >> n1;

    if (r != r1 || c != c1) return 0;

    int b[n1][3];
    for (int i = 0; i < n1; i++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }

    int s[n + n1][3];
    int k = 0;

    for (int i = 0; i < n; i++) {
        s[k][0] = a[i][0];
        s[k][1] = a[i][1];
        s[k][2] = a[i][2];
        k++;
    }

    for (int i = 0; i < n1; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (s[j][0] == b[i][0] && s[j][1] == b[i][1]) {
                s[j][2] += b[i][2];
                found = true;
                break;
            }
        }
        if (!found) {
            s[k][0] = b[i][0];
            s[k][1] = b[i][1];
            s[k][2] = b[i][2];
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
    }

    return 0;
}
