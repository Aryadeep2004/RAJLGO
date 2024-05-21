#include<iostream>
using namespace std;

int intexpoa(int x, int n) 
{
    if (n == 0) 
    {
        return 1;
    }
    if (n == 1) 
    {
        return x;
    }
    if (n % 2 == 0) 
    {
        int y = intexpoa(x, n / 2);
        return y * y;
    }
    else 
    {
        return x * intexpoa(x, n - 1);
    }
}

int main() {
    int x, n;
    cout << "Enter the base: ";
    cin >> x;
    cout << "Enter the power: ";
    cin >> n;
    int ans = intexpoa(x, n);
    cout << "Result is: " << ans << endl;
    return 0;
}

