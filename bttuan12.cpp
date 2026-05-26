#include <iostream>
using namespace std;

void inMang(int a[], int n)
{
    for(int i = 1;i<=n;i++)
    {
        cout<<a[i] << " ";
    }
    cout << endl;
}

void VunDong(int a[], int i, int n)
{
    int x = a[i];
    int j=i*2;

    while(j<=n)
    {
        if(j<n && a[j]<a[j+1])
        {
            j= j+1;
        }

        if(x>=a[j])
        {
            break;
        }

        a[j/2]=a[j];
        j=j*2;
    }

    a[j/2]=x;
}

void SapXepVunDong(int a[], int n)
{
    cout <<"Mang ban dau:" << endl;
    inMang(a, n);

    cout << endl;
    cout << "Tao dong" << endl;

    for(int i=n/2; i>=1; i--)
    {
        VunDong(a, i, n);

        cout << "Sau lan vun dong " << i << ":" << endl;
        inMang(a, n);
    }

    cout << endl;
    cout << "Sap xep vun dong" << endl;

    for(int i=n; i>=2;i--)
    {
        int t=a[1];
        a[1]=a[i];
        a[i]=t;

        cout <<"Sau khi doi:" << endl;
        inMang(a, n);

        VunDong(a, 1, i - 1);

        cout << "Sau khi vun lai:" << endl;
        inMang(a, n);

        cout << endl;
    }

    cout << "Mang sau cung:" << endl;
    inMang(a, n);
}

int main()
{
    int a1[11] = {0,4,1,3,2,16,9,10,14,8,7};
    int n1=10;

    SapXepVunDong(a1, n1);

    cout << "====================" << endl;

    int a2[13] = {0,11,54,32,106,38,78,203,16,84,17,39,15};
    int n2=12;

    SapXepVunDong(a2, n2);

    cout << "====================" << endl;

    int a3[10] = {0,96,83,45,75,51,11,27,32,66};
    int n3=9;

    SapXepVunDong(a3, n3);

    return 0;
}
