#include <iostream>
#include <list>
#include <queue>

using namespace std;


int main() {
    int k;
    queue <int> first;
    queue <int> second;

    first.push(1);
    first.push(3);
    first.push(5);
    first.push(7);
    first.push(9);


    second.push(2);
    second.push(4);
    second.push(6);
    second.push(8);
    second.push(0);

    while(!first.empty() && !second.empty()) {

        if ((first.front() > second.front() || first.front() == 0) && second.front() != 0){
            first.push(first.front());
            first.push(second.front());
            first.pop();
            second.pop();
        }

        if ((first.front() < second.front() || second.front() == 0) && first.front() != 0){
            second.push(first.front());
            second.push(second.front());
            first.pop();
            second.pop();
        }


            k++;

    }

    if (first.empty())
        cout << "second " << k << endl;
    else if (second.empty())
        cout << "first " << k << endl;
    return 0;
}
