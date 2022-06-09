#include <iostream>
#include <math.h>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;


void swap( int& n1, int& n2 ) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solution1( int* input, const int n, int k, int*& output ) {
    //output = new int[k];

    if (k>n)
        k = n;

    int* maxIndex = new int;
    int* maxValue = new int;

    for (int i=0; i < k; (i)++ ) {
        *maxIndex = i;
        *maxValue = input[i];

        for ( int j=i+1; j < n; (j)++ ) {
            if ( input[j] >= *maxValue ) {
                *maxIndex = j;
                *maxValue = input[ j ];
            }
        }
        swap( input[i], input[*maxIndex] );
        output[i] = input[i];
    }

    delete maxIndex;
    delete maxValue;

}

static int partition( int input[], int p, int r ) {

    int* x = new int;
    *x = input[ r ];
    int i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] >= *x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[i+1], input[r] );
    delete x;
    return i + 1;
}

static void quickSort( int* input, int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition( input, p, r );
        quickSort( input, p, q - 1 );
        quickSort( input, q + 1, r );
    }
}

void solution2( int* input, const int n, const int k, int*& output ) {

    quickSort( input, 0, n - 1 );

    output = new int[k];
    for ( int i = 0; i < k; i++ ) {
        output[i] = input[i];
    }

}

static int partition( int* input, int a, int p, int r ) {

    int x = a, i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] == x ) {
            swap( input[ j ], input[ r ] );
        }
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[ i + 1 ], input[ r ] );
    return i + 1;
}


static int findMin( int n1, int n2 ) {

    if ( n1 <= n2 )
        return n1;
    else
        return n2;
}

static int select( int* input, int n, int k, int start, int end, int flag ) {

    if ( n <= 5 ) {
        quickSort( input, start, end );
        return input[ start + k - 1 ];
    }
    int i = start, numGroups = (int) ceil( ( double ) n / 5 ), numElements, j = 0;
    int *medians = new int[numGroups];
    while ( i <= end ) {
        numElements = findMin( 5, end - i + 1 );
        medians[( i - start ) / 5] = select( input, numElements, (int) ceil( ( double ) numElements / 2 ), i, i + numElements - 1, 1 );
        i = i + 5;
    }
    int M = select( medians, numGroups, (int) ceil( ( double ) numGroups / 2 ), 0, numGroups - 1, 1 );
    delete[] medians;
    if ( flag == 1 )
        return M;
    int q = partition( input, M, start, end );
    int m = q - start + 1;
    if ( k == m )
        return M;
    else if ( k < m )
        return select( input, m - 1, k, start, q - 1, 0 );
    else
        return select( input, end - q, k - m, q + 1, end, 0 );
}

void solution3( int* input, const int n, const int k, int*& output ) {
    output = new int[k];
    select( input, n, k, 0, n - 1, 0 );

    for( int i = 0; i < k; i++ )
        output[i] = input[i];
}

void displayArray (int arr[],int size) {
    if (size > 0){
        cout << "[ ";
        for (int i = 0; i < size-1;i++)
            cout << arr[i] << ", ";
        cout << arr[size-1] << " ]"<<endl;
    }
}

void constructDefaultArray(int size){
    ofstream writeArray;
    writeArray.open ("array.txt");
    for( int i = 0; i < size; i++)
        writeArray << (rand()%100) + 1 << endl;
       writeArray.close();
}

void createArray(int*& array ,int size){
    ifstream readArray;
    readArray.open ("array.txt");
    for( int i = 0; i < size; i++)
        readArray >> array[i];
    readArray.close();
}


int main() {

    ofstream myfile1;
    ofstream myfile2;
    ofstream myfile3;

    myfile1.open ("solution1.txt");
    myfile2.open ("solution2.txt");
    myfile3.open ("solution3.txt");

    int* arr = NULL;
    int* output = NULL;
    int N = 1;
    int k = 1000;
    double duration1 = 0;
    double duration2 = 0;
    double duration3 = 0;
    int solution = 0;

    //construct the random array
    constructDefaultArray(pow(2,20));

    cout << "Solution 1" << endl;
    cout << "N\tk\tTime" << endl;

    while (N <= pow(2,20))
    {
        int* arr = new int[N];
        k = 1000;

        if(k>N){
            k = N;
            output = new int[N];
        }
        else{
            output = new int[k];
        }

        createArray(arr,N);

        clock_t startTime1 = clock();
        solution1( arr, N, k, output );
        duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;

        cout << N << "\t" << k << "\t" << duration1 <<endl;
        myfile1 << N << "\t" << k << "\t" << duration1 <<endl;

        N = N * 2;

        delete[] arr;
        arr = NULL;
        delete [] output;
        output = NULL;
    }

    cout << "Solution 2" << endl;
    cout << "N\tk\tTime" << endl;

    N = 1;
    k = 1000;

    while (N <= pow(2,20))
    {
        int* arr = new int[N];
        k = 1000;

        if(k>N){
            k = N;
            output = new int[N];
        }
        else{
            output = new int[k];
        }

        createArray(arr,N);

        clock_t startTime2 = clock();
        solution2( arr, N, k, output );
        duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;

        cout << N << "\t" << k << "\t" << duration2 <<endl;
        myfile2 << N << "\t" << k << "\t" << duration2 <<endl;


        N = N * 2;


        delete[] arr;
        arr = NULL;
        delete [] output;
        output = NULL;
    }

    cout << "Solution 3" << endl;
    cout << "N\tk\tTime" << endl;

    N = 1;
    k = 1000;

    while (N <= pow(2,20))
    {
        int* arr = new int[N];
        k = 1000;

        if(k>N){
            k = N;
            output = new int[N];
        }
        else{
            output = new int[k];
        }

        createArray(arr,N);

        clock_t startTime3 = clock();
        solution3( arr, N, k, output );
        duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;

        cout << N << "\t" << k << "\t" << duration3 <<endl;
        myfile3 << N << "\t" << k << "\t" << duration3 <<endl;
        N = N * 2;


        delete[] arr;
        arr = NULL;
        delete [] output;
        output = NULL;

    }

    cout << "Program ended!" << endl;

    myfile1.close();
    myfile2.close();
    myfile3.close();

    return 0;
}



