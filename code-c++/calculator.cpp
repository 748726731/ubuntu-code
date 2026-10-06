#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> a;
    stack<char> b;
    bool cnt = false;
    long long num = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
            cnt = true;
        }
        else if (s[i] == '(')
        {
            b.push('(');
        }
        else if (s[i] == ')')
        {
            if (cnt == true)
            {
                a.push(num);
                cnt = false;
                num = 0;
            }

            while (b.top() != '(')
            {
                int right = a.top(); 
                a.pop();
                int left = a.top(); 
                a.pop();
                char op = b.top(); 
                b.pop();

                if (op == '+')      
                a.push(left + right);
                else if (op == '-') 
                a.push(left - right);
                else                a.push(left * right);
            }
            b.pop();
        }
        else
        {
            if (cnt == true)
            {
                a.push(num);
            }
            cnt = false;
            num = 0;

            while (b.empty() != 1 && b.top() != '(' &&
                   (b.top() == '*' || s[i] != '*'))//当(栈不为空)且(栈顶不是左括号)且(栈顶是乘号)或者(当前字符不是乘号)时，执行运算.
            {
                int right = a.top(); 
                a.pop();
                int left = a.top(); 
                a.pop();
                char op = b.top(); 
                b.pop();//脱离循环条件.

                if (op == '+')      
                a.push(left + right);
                else if (op == '-') 
                a.push(left - right);
                else                
                a.push(left * right);
            }
            b.push(s[i]);
        }
    }

    if (cnt == true)
    {
        a.push(num);
    }

    while (b.empty() != 1)
    {
        int right = a.top(); 
        a.pop();
        int left = a.top(); 
        a.pop();
        char op = b.top(); 
        b.pop();

        if (op == '+')      
        a.push(left + right);
        else if (op == '-') 
        a.push(left - right);
        else                
        a.push(left * right);
    }

    cout << a.top();
    return 0;
}