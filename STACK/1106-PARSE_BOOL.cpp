#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        int n = expression.size();
        stack<char> expressionStack;
        stack<char> operators;

        for (int i = 0; i < n; i++)
        {
            if (expression[i] == ',')
                continue;
            else if (expression[i] == '!' || expression[i] == '|' ||
                     expression[i] == '&')
            {
                operators.push(expression[i]);
            }
            else
            {
                expressionStack.push(expression[i]);
            }
        }

        bool result;

        if (operators.top() == '&')
        {
            result = true;
        }
        else
        {
            result = false;
        }

        while (!operators.empty())
        {
            bool found = false;
            if (operators.top() == '|')
            {
                while (!expressionStack.empty() && expressionStack.top() != '(')
                {
                    if (expressionStack.top() == 't' || expressionStack.top() == 'f')
                    {
                        bool MyValue;
                        if (expressionStack.top() == 't')
                            MyValue = true;
                        else
                            MyValue = false;

                        result = result | MyValue;
                    }
                    expressionStack.pop();
                }
            }
            else if (operators.top() == '&')
            {
                while (!expressionStack.empty() && expressionStack.top() != '(')
                {
                    if (expressionStack.top() == 't' || expressionStack.top() == 'f')
                    {
                        bool MyValue;
                        if (expressionStack.top() == 't')
                            MyValue = true;
                        else
                            MyValue = false;
                        result = result & MyValue;
                    }
                    expressionStack.pop();
                }
            }
            else
            {
                while (!operators.empty() && operators.top() == '!')
                {
                    result = ~result;
                    operators.pop();
                    found = true;
                }
            }
            if (found == true)
                continue;
            if (!operators.empty())
                operators.pop();
        }
        return result;
    }
};

/* Wrong Failed on 
    "|(&(t,f,t),!(t))"
    Expected: true
    Output: false
 */