#include <iostream>
using namespace std;
int main()
{
    char c;
    cin >> c;
    cout << "  " << c << "\n";           // 两个空格 + 1个字符
    cout << " " << string(3, c) << "\n"; // 一个空格 + 3个字符
    cout << string(5, c) << "\n";        // 5个字符
    return 0;
}
