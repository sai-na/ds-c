#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void push(int);
int pop();
int priority(char);
int top = -1;
int stack[20];
char *infixtopostfix();
int evaluatepostfix(char *);

void main()
{
    char *postfix;
    int ans;
    postfix = infixtopostfix();
    printf("postfix expression is %s\n", postfix);
    ans = evaluatepostfix(postfix);
    printf("result is %d", ans);
}

char *infixtopostfix()
{
    char infix[20], ch;
    static char postfix[20];
    int i, j = 0;
    printf("Enter the infix expression:");
    scanf("%s", infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (ch == '(')
            push(ch);
        else if (isdigit(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (priority(ch) <= priority(stack[top]) && top != -1)
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    return postfix;
}

int priority(char ch)
{
    if (ch == '(')
        return 0;

    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
}

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluatepostfix(char *postfix)
{
    int op1, op2;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            push(postfix[i] - 48);

        else
        {
            op1 = pop();
            op2 = pop();
            switch (postfix[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op2 / op1);
                break;
            }
        }
    }
    return pop();
}