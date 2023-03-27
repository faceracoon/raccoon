#include <iostream>
#include <list>
#include <iterator>

using namespace std;

bool comp(string a, string b){
    return stoi(a) < stoi(b);
}

int main() {
    int n,k;
    list <string> ofX{"9 Ivanov", "9 Petrov", "11 Sidorod", "9 Grigoryev", "9 Sergeev", "10 Iacovlev" };

    ofX.sort(comp);

    for (auto it : ofX){
        cout << (it) << "\n";
    }

    return 0;
}
