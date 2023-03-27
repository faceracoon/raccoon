#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    int n,k;
    double x;
    list <double> ofX;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x;
        ofX.push_back(x);
    }

    for (auto it : ofX) {
        cout << (it) << " ";
    }

    ofX.sort();
    ofX.unique();

    for (auto it : ofX) {
        k++;
    }

    cout << "\nNumber of unique numbers: " << k << endl;

    return 0;
}
