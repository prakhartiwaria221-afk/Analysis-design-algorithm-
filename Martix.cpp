// Matrix Method :

#include <iostream>
using namespace std;

int main() {
    int n, p, r, m;

    cout << "Enter the number of rows and columns for first matrix: ";
    cin >> n >> p;

    cout << "Enter the number of rows and columns for second matrix: ";
    cin >> r >> m;

    int a[n][p];
    int b[r][m];
    int product[n][m];

    int sum = 0;

    if (r == p) {
        cout << "Enter elements of first matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                cin >> a[i][j];
            }
        }

        cout << "Enter elements of second matrix:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }

        cout << "Final matrix of product is:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum = 0;
                for (int k = 0; k < p; k++) {
                    sum += a[i][k] * b[k][j];
                }
                product[i][j] = sum;
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Sorry!.. Matrix multiplication is not possible." << endl;
    }

    return 0;
}

// Strassen's Matrix Multiplication Method:
/*
#include <iostream>
using namespace std;

void add(int A[10][10], int B[10][10], int C[10][10], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int A[10][10], int B[10][10], int C[10][10], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int A[10][10], int B[10][10], int C[10][10], int n)
{
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int mid=n/2;

    int A11[10][10],A12[10][10],A21[10][10],A22[10][10];
    int B11[10][10],B12[10][10],B21[10][10],B22[10][10];

    int M1[10][10],M2[10][10],M3[10][10],M4[10][10];
    int M5[10][10],M6[10][10],M7[10][10];

    int T1[10][10],T2[10][10];

    int C11[10][10],C12[10][10],C21[10][10],C22[10][10];

    for(int i=0;i<mid;i++)
    {
        for(int j=0;j<mid;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+mid];
            A21[i][j]=A[i+mid][j];
            A22[i][j]=A[i+mid][j+mid];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+mid];
            B21[i][j]=B[i+mid][j];
            B22[i][j]=B[i+mid][j+mid];
        }
    }

    add(A11,A22,T1,mid);
    add(B11,B22,T2,mid);
    strassen(T1,T2,M1,mid);

    add(A21,A22,T1,mid);
    strassen(T1,B11,M2,mid);

    sub(B12,B22,T2,mid);
    strassen(A11,T2,M3,mid);

    sub(B21,B11,T2,mid);
    strassen(A22,T2,M4,mid);

    add(A11,A12,T1,mid);
    strassen(T1,B22,M5,mid);

    sub(A21,A11,T1,mid);
    add(B11,B12,T2,mid);
    strassen(T1,T2,M6,mid);

    sub(A12,A22,T1,mid);
    add(B21,B22,T2,mid);
    strassen(T1,T2,M7,mid);

    add(M1,M4,T1,mid);
    sub(T1,M5,T2,mid);
    add(T2,M7,C11,mid);

    add(M3,M5,C12,mid);

    add(M2,M4,C21,mid);

    sub(M1,M2,T1,mid);
    add(T1,M3,T2,mid);
    add(T2,M6,C22,mid);

    for(int i=0;i<mid;i++)
    {
        for(int j=0;j<mid;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+mid]=C12[i][j];
            C[i+mid][j]=C21[i][j];
            C[i+mid][j+mid]=C22[i][j];
        }
    }
}

int main()
{
    int n;
    cout<<"Enter size (power of 2): ";
    cin>>n;

    int A[10][10],B[10][10],C[10][10];

    cout<<"Enter matrix A:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    cout<<"Enter matrix B:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>B[i][j];

    strassen(A,B,C,n);

    cout<<"Result matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
*/

// Matrix recursive Method 
/*
#include <iostream>
using namespace std;

void add(int A[10][10], int B[10][10], int C[10][10], int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void multiply(int A[10][10], int B[10][10], int C[10][10], int n)
{
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int mid=n/2;

    int A11[10][10],A12[10][10],A21[10][10],A22[10][10];
    int B11[10][10],B12[10][10],B21[10][10],B22[10][10];
    int C11[10][10],C12[10][10],C21[10][10],C22[10][10];
    int P1[10][10],P2[10][10];

    for(int i=0;i<mid;i++)
    {
        for(int j=0;j<mid;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+mid];
            A21[i][j]=A[i+mid][j];
            A22[i][j]=A[i+mid][j+mid];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+mid];
            B21[i][j]=B[i+mid][j];
            B22[i][j]=B[i+mid][j+mid];
        }
    }

    multiply(A11,B11,P1,mid);
    multiply(A12,B21,P2,mid);
    add(P1,P2,C11,mid);

    multiply(A11,B12,P1,mid);
    multiply(A12,B22,P2,mid);
    add(P1,P2,C12,mid);

    multiply(A21,B11,P1,mid);
    multiply(A22,B21,P2,mid);
    add(P1,P2,C21,mid);

    multiply(A21,B12,P1,mid);
    multiply(A22,B22,P2,mid);
    add(P1,P2,C22,mid);

    for(int i=0;i<mid;i++)
    {
        for(int j=0;j<mid;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+mid]=C12[i][j];
            C[i+mid][j]=C21[i][j];
            C[i+mid][j+mid]=C22[i][j];
        }
    }
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int A[10][10],B[10][10],C[10][10];

    cout << "Enter matrix A:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    cout << "Enter matrix B:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>B[i][j];

    multiply(A,B,C,n);

    cout << "Result matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
    */