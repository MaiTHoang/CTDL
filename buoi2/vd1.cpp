//Tinh tong cac so tu 1 den N
#include<iostream>
using namespace std;

int sum_1_to_n(int n)
{
    int s=0; //1 phep gan
    for(int i=1; i<=n;i++)
    {
        //n vong lap
        s+=1; //1 phep cong va 1 phep gan moi vong lap
    }
    return s;
}

int main()
{
    int n=15;
    cout << "Tong 1...n = " << sum_1_to_n(n) << endl; //Output: 15
    return 0;
}