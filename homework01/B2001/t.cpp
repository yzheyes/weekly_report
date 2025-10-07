#include <iostream>
using namespace std;
int main()
{
    long long a, b; // 64 位，和最大约 8e18，安全
    if (cin >> a >> b)
    {
        cout << a + b << '\n';
    }
    return 0;
}
