#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;                // 基准条件
    return n * factorial(n - 1); // 递归调用
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
