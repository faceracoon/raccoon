#include <iostream>


template<typename type>

type swap(type &a, type &b)
{
    type temp = a;
    a = b;
    b = temp;
}

double* rewrite(double *mas, int n){
    double *mas2 = new double[n];

    double *mas3 = new double[n];
    int last;
    for(int i = 0, k = 0, l = n-1; i < n; i++){
        if (mas[i] < 0) {
            mas2[k] = mas[i];
            k++;
            last = k;
        }
        else{
            mas2[l] = mas[i];
            l--;
        }
    }
    int j = n - 1;
    for (int i = 0; i < n; i++)
        mas3[i] = mas2[i];

    for (int i = last; i < n; i++){
        mas2[i] = mas3[j];
        j--;
    }
    delete []mas3;

    return mas2;
}


int* rewrite2(int *mas, int n){
    int *mas2 = new int[n];

    int *mas3 = new int[n];
    int last;
    for(int i = 0, k = 0, l = n-1; i < n; i++){
        if (mas[i] < 0) {
            mas2[k] = mas[i];
            k++;
            last = k;
        }
        else{
            mas2[l] = mas[i];
            l--;
        }
    }

    int j = n - 1;
    for (int i = 0; i < n; i++)
        mas3[i] = mas2[i];

    for (int i = last; i < n; i++){
        mas2[i] = mas3[j];
        j--;
    }

        bool isDone = true;
        for(int j = last; j < n; j++) {
            isDone = true;
            for (int i = last; i < n - 1; i++)
                if (mas2[i] < mas2[i + 1]) {
                    isDone = false;
                    swap(mas2[i], mas2[i + 1]);
                }
            if (isDone == true) {
                break;
            }
        }

    for (int i = 0; i <= last; i++){
        bool isDone = true;
        for(int j = 0; j < last; j++) {
            isDone = true;
            for (int i = 0; i < last - 1; i++)
                if (mas2[i] < mas2[i + 1]) {
                    isDone = false;
                    swap(mas2[i], mas2[i + 1]);
                }
            if (isDone == true) {
                break;
            }
        }
    }


    delete []mas3;

    return mas2;
}

double summBetween(double **mas, int i, int h){
    int k, summ = 0;
    for (int j = 0; j < h; j++)
        if (mas[i][j] == 0){
        k = j + 1;
        while(mas[i][k] != 0 && k < h){
            summ += mas[i][k];
            k++;
        }
        return summ;
    }
}

int findMaxIdx(int *mas, int n){
    int max, maxId;
    for (int i = 0; i < n; i++)
        if (mas[i] > max){
            max = mas[i];
            maxId = i;
        }
    return maxId;
}

int findMaxRow(double **mas, int n, int m) {
    double max, sum;
    int maxId;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += mas[i][j];
        }
        if (sum > max) {
            max = sum;
            maxId = i;
        }
    }
    return maxId + 1;
}

int findMinRow(double **mas, int n, int m){
    double min = 1000000000000000, sum;
    int minId;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
                sum += mas[i][j];
            }
        if (sum < min) {
            min = sum;
            minId = i;
        }
    }
    return minId + 1;
}

int main() {
    //Задание 1
    double a, b;
    a = 3;
    b = 44;
    swap(a, b);
    //std::cout << a << "\n" << b << std::endl;

    //Задание 2
    /*
    int n;
    std::cin >> n;

    double mas[n];

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];


    double *pa = &mas[0];
    double *pla = &mas[n-1];

    double tmp = *pa;

    *pa=*pla;
    *pla=tmp;

    for (int i = 0; i < n; i++)
        std::cout << mas[i] << std::endl; */

    //Задание 3


    //Задание 4
    int m = 12, count;
    double max;
    double real [] = {2,1,4,9,5,7,19,10,8,13,21,32};
    std::cout << "before" << std::endl;
    for (int i = 0; i < m; i++)
        std::cout << real[i] << " ";
    std::cout << std::endl;

    bool isDone = true;
    for(int j = 0; j < m; j++) {
        isDone = true;
        for (int i = 0; i < m - 1; i++)
            if (real[i] < real[i + 1]) {
                isDone = false;
                swap(real[i], real[i + 1]);
                count++;
            }
        if (isDone == true) {
            break;
        }
    }
    std::cout << "after" << std::endl;
    for (int i = 0; i < m; i++)
        std::cout << real[i] << " ";
    std::cout << std::endl;

    std::cout << "num of swaps: " << count << std::endl;

    //Задание 5
    count = 0;
    int k = 4;
    double *mass2 = new double[k];
    double mass[] = {2,-1,4,-9};

    mass2 = rewrite(mass,k);

    for (int i = 0; i < k; i++)
        std::cout << mass2[i] << " ";
    std::cout << std::endl;


    //Задание 6
    count = 0;
    int f = 14;
    double massive[] = {2,-1,4,-9,0,23,1,13,6,9,11,32,99,65};
    for (int i = 0; i < 7; i++){
        if(massive[i] != massive[i + 7]) {
            swap(massive[i], massive[i + 7]);
            count++;
        }
    }

    for (int i = 0; i < f; i++)
        std::cout << massive[i] << " ";
    std::cout << std::endl;

    std::cout << "num of swaps: " << count << std::endl;


    //Задание 7
    count = 0;
    int q = 9;
    double seven[] = {7,3,4,5,0,23,1,13,6};
    for (int i = 1; i < q - 1; i++){
        if((seven[i] < seven[i - 1]) && (seven[i] < seven[i + 1]))
            count++;
    }

    std::cout << "num of loc mins: " << count << std::endl;

    //Задание 8
    count = 0;
    int h = 4, summ;
    double **eight = new double* [h];
    for (int i = 0; i < h; i++)
        eight[i] = new double [h];


    //Ручной ввод
    //for (int i = 0; i < h; i++)
    //    for (int j = 0; j < h; j++)
    //        std::cin >> eight[i][j];

    eight[0][0] = 0;
    eight[0][1] = 2;
    eight[0][2] = 1;
    eight[0][3] = 0;

    eight[1][0] = 0;
    eight[1][1] = 5;
    eight[1][2] = 0;
    eight[1][3] = 2;

    eight[2][0] = 0;
    eight[2][1] = 1;
    eight[2][2] = 11;
    eight[2][3] = 0;

    eight[3][0] = 0;
    eight[3][1] = 0;
    eight[3][2] = 1;
    eight[3][3] = 2;


    //Тут сам выбирай, какой варик оставить это первый
    int leftIn, rightIn;
    for (int i = 0; i < h; i++){
        summ = 0;
        leftIn = -1;
        rightIn = -1;
        for (int j = 0; j < h; j++){
            if (eight[i][j] == 0 && leftIn < 0){
                leftIn = j;
            } else if (eight[i][j] == 0 && leftIn >= 0)
                rightIn = j;
        }

        for (int m = leftIn + 1; m < rightIn; m++)
            summ += eight[i][m];

        std::cout << "summ of elements in " << i+1 <<" row between zeroes: " << summ << std::endl;
    }

    //Это второй
    for (int i = 0; i < h; i++){
        summ = summBetween(eight, i, h);
        std::cout << "summ of elements in " << i+1 <<" row between zeroes: " << summ << std::endl;
        summ = 0;
    }


    //Задание 9
    count = 0;
    int g = 15;
    int nine[] = {2,-1,4,-9,0,23,1,13,6,9,11,32,99,65, 33};
    int *nine2 = new int[g];
    nine2 = rewrite2(nine,g);

    for (int i = 0; i < g; i++)
        std::cout << nine2[i] << " ";
    std::cout << std::endl;

    //Задание 10
    int nTf = 5, nTs = 7;
    int tenF[] = {2,-1,4,-9,0};
    int tenS[] = {23,1,13,6,9,11,32};

    int n1, n2;
    n1 = findMaxIdx(tenF, nTf);
    n2 = findMaxIdx(tenS, nTs);

    swap(tenF[n1], tenS[n2]);

    std::cout << "swapped max elem" << std::endl;

    for (int i = 0; i < nTf; i++)
        std::cout << tenF[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < nTs; i++)
        std::cout << tenS[i] << " ";
    std::cout << std::endl;


    //Задание 11
    int v  = 3;
    double tmp;
    double **eleven = new double* [v];
    for (int i = 0; i < v; i++)
        eleven[i] = new double [v];

    eleven[0][0] = 0;
    eleven[0][1] = 2;
    eleven[0][2] = 1;

    eleven[1][0] = 3;
    eleven[1][1] = 5;
    eleven[1][2] = 0;

    eleven[2][0] = 0;
    eleven[2][1] = 1;
    eleven[2][2] = 11;

    std::cout << "not replaced" << std::endl;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            std:: cout << eleven[j][i] << " ";}
        std::cout << std::endl;}

    for(int i = 0; i < v; i ++){
        for(k = 0; k < 1; k++){
            tmp = eleven[v - 1][i];
            for(int j = v - 1; j > 0; j--)
                eleven[j][i] = eleven[j - 1][i];
            eleven[0][i] = tmp;
        }
    }
    std::cout << "replaced" << std::endl;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
             std:: cout << eleven[j][i] << " ";}
        std::cout << std::endl;}

    delete []eleven;

    //Задание 12
    int s  = 3;
    double **twelve = new double* [v];
    for (int i = 0; i < v; i++)
        twelve[i] = new double [v];

    std::cout << "12 task" << std::endl;

    twelve[0][0] = 0;
    twelve[0][1] = 2;
    twelve[0][2] = 1;

    twelve[1][0] = 3;
    twelve[1][1] = 5;
    twelve[1][2] = 0;

    twelve[2][0] = 0;
    twelve[2][1] = 1;
    twelve[2][2] = 11;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            std:: cout << eleven[i][j] << " ";}
        std::cout << std::endl;}

    std::cout << "row with max summ: " << findMaxRow(twelve, s, s) << std::endl;
    std::cout << "row with min summ: " << findMinRow(twelve, s, s) << std::endl;

    return 0;
}
