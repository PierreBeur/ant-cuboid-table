#include <iostream> // cout, cin, endl
#include <iomanip> // setw
#include <cmath> // sqrt
#include <limits> // numeric_limits

using namespace std;

string cases[4] = {"1  ", "2.1", "2.2", "2.3"};

int main() {
    double w, l, h;

    // get input from user
    bool valid = false;
    while (!valid) {
        cout << "Enter width, length, and height (space-separated): ";
        if ((cin >> w >> l >> h) && w >= 0 && l >= 0 && h >= 0) {
            valid = true; // input is valid, exit the loop
        } else {
            cout << "Invalid input. Please enter positive decimals." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

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
    bool result[4];
    for (int i = 0; i < 4; i++) {
        result[i] = paths[i] <= min_l;
    }

    // display results
    cout << endl << "Results:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Case " << cases[i] << ": " << paths[i] << endl;
    }

    cout << endl << "The following cases are optimal with path length " << min_l << ":" << endl;
    for (int i = 0; i < 4; i++) {
        if (result[i]) cout << "Case " << cases[i] << endl;
    }

    return 0;
}
