#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


double toNumber(string s)
{
    double acc = 0;
    for (int i = 0; i < s.size(); i++)
        acc = acc * 10 + s[i] - '0';
    return acc;
}


double polandCalc(const string *problem, int size)
{
    stack <double> poland;
    string a;
    double z,a1,a2;

    for (int i = 0; i < size; i++)
    {

        a = problem[i];

        if (a[0] >= '0' && a[0] <= '9')
        {
            z = toNumber(a);
            poland.push(z);
        }
        else if (!(a[0] >= '0' && a[0] <= '9') && a[0] !=' ')
        {
            a2 = poland.top();
            poland.pop();

            a1 = poland.top();
            poland.pop();

            switch (a[0])
            {
                case '+':
                    z = a1 + a2;
                    break;
                case '-':
                    z = a1 - a2;
                    break;
                case '*':
                    z = a1 * a2;
                    break;
                case '/':
                    if (fabs(a2) < 1.0e-16) {
                        cout << "can't divide by zero\n";
                        break;
                    }
                    z = a1 / a2;
                    break;
                case ' ':
                    break;
            }

            poland.push(z);

        }
    }

    if (poland.size() > 1)
    {
        cout << "wrong notation\n";
        exit(1);
    }
    else
        return poland.top();

}

int main()
{
    string problem[]={"8"," ", "9"," ", "+"," ", "1"," ", "7"," ", "-"," ", "*"," "};

        cout << polandCalc(problem, 14) << endl;


    return 0;
}