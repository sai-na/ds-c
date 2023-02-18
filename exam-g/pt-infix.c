#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
    {
        // printf("Stack is empty");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char ch)
{
    if (ch == '(')
        return 0;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return -1; // handle other characters
}

int main()
{
    char infix[20], postfix[20];
    int i = 0, j = 0;
    char ch;
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else
        {
            while (priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    } // end of main while

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\npost is : %s", postfix);
} // end of main function