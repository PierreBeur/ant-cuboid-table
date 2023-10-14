#include <iostream> // cout, cin
#include <cmath> // sqrt

using namespace std;

string cases[4] = {"1", "2.1", "2.2", "2.3"};

int main() {
    double w, l, h;

    // get input from user
    cout << "Enter width, length, and height (space-separated): ";
    cin >> w >> l >> h;

    // calculate path lengths for each case
    double paths[4];

    // case 1
    paths[0] = w + l;

    // case 2.1
    double wh = w + h, lh = l + h;
    paths[1] = sqrt(wh * wh + lh * lh);

    // case 2.2
    double l2h = l + 2 * h;
    paths[2] = sqrt(w * w + l2h * l2h);

    // case 2.3
    double w2h = w + 2 * h;
    paths[3] = sqrt(w2h * w2h + l * l);

    // find minimum path length
    double min_l = paths[0];
    for (int i = 1; i < 4; i++) {
        min_l = paths[i] < min_l ? paths[i] : min_l;
    }

    // find minimum cases
    bool result[4] = {
        paths[0] <= min_l,
        paths[1] <= min_l,
        paths[2] <= min_l,
        paths[3] <= min_l
    };

    // display results
    cout << "The following cases are optimal with path length " << min_l << ":" << endl;
    for (int i = 0; i < 4; i++) {
        if (result[i]) cout << "Case " << cases[i];
    }

    return 0;
}
