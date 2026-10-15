#include <bits/stdc++.h>
using namespace std;

vector<string> turn90(const vector<string>& a)   
// &传引用，不拷贝。放类型后而非a后；返回新图案
//a是一个字符串类型的数组，a[i],纵向长度是0到i-1，横向是字符串长度。
{
    int n = a.size();
    vector<string> c(n, string(n, ' '));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[j][n - 1 - i] = a[i][j];
    return c;
}

vector<string> flip(const vector<string>& a)     // 水平翻转
{
    vector<string> c = a;
    for (string& s : c) reverse(s.begin(), s.end());
    //for一次循环，reverse也在循环,1234567循环s.size()/2次,
    //变成7654321
    return c;
}

int main()
{
    int n; cin >> n;
    vector<string> a(n), b(n);//一维数组a，b，有n行，每行都是字符串
    /*
    vector<string> v(3);    // () 创建：造 1 个 vector，里面【装 3 个元素】
    vector<string> w[3];    // [] 创建：造【3 个 vector】构成的数组，每个都是空的*/

    for (string& s : a) cin >> s;
    /*
    for (int i = 0; i < (int)a.size(); i++) 
    {
        string& s = a[i];  s绑定这个a[i],int& a==int &a,     ”
        在类型后ji说明是引用，给已有变量起别名，不是指针
        cin>>s;
    }
    */
      //这个如果不加&,相当于int hanshu(int a)里的a
      //只是个副本，用完就丢，不会再从cin那里返回给a;
    for (string& s : b) cin >> s;

    vector<string> c = turn90(a);
    if (c == b) { cout << 1; return 0; }       // string 版：直接 == 比较
    c = turn90(c);
    if (c == b) { cout << 2; return 0; }
    c = turn90(c);
    if (c == b) { cout << 3; return 0; }

    c = flip(a);
    if (c == b) { cout << 4; return 0; }

    c = turn90(c);
    if (c == b) { cout << 5; return 0; }
    c = turn90(c);
    if (c == b) { cout << 5; return 0; }
    c = turn90(c);
    if (c == b) { cout << 5; return 0; }

    if (a == b) { cout << 6; return 0; }
    cout << 7;
    return 0;
}