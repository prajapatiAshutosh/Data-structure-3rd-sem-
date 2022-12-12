#include <iostream>
#include <stack>
#include <string>

using namespace std;

float calc(float o1,float o2,char c)
{
    if(c=='+') return o1+o2;
    if(c=='-') return o1-o2;
    if(c=='*') return o1*o2;
    if(c=='/') return o1/o2;
    else return 0;
}

float evaluate(string exp)
{
    float result=0;
    stack<int> s ;
    int dig = 0;
    int i=0;
    while(i<exp.length())
    {
        char e = exp[i];
        if(isdigit(exp[i])) {
            dig = dig*10 + (exp[i]-'0');
        } else if (exp[i] == ' ') {
            s.push(dig);
            dig = 0; 
        } else {
            float o2=s.top();
            s.pop();
            float o1=s.top();
            s.pop();
            result = calc(o1,o2,e);
            s.push(result);
            i++;

        }i++;
    }
    return s.top();
}

int main()
{
    string exp="28 2 / 5 -";
    cout<<evaluate(exp);
    return 0;
}