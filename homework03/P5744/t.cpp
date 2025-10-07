#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

// 培训函数
Student train(Student s)
{
    s.age += 1;
    s.score = int(s.score * 1.2); // 提升 20%
    if (s.score > 600)
        s.score = 600; // 不超过 600
    return s;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Student stu;
        cin >> stu.name >> stu.age >> stu.score;
        stu = train(stu); // 调用培训函数
        cout << stu.name << " " << stu.age << " " << stu.score << endl;
    }
    return 0;
}
