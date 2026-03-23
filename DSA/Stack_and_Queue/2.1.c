                        //___STACK___//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Stack[20];
int tos = -1;

void push(char x){
    Stack[++tos] = x;
}

char pop(){
    if (tos == -1) {
        return '\0';
    } else {
        return Stack[tos--];
    }
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' ||  x == '-'){
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
}

int main()
{
    char exp[20];
    char *e, x;

    printf("Enter the expression: \n");
    scanf("%s", exp) ;
    e = exp;

    while (*e != '\0')               /* Denotes a null value */
    {
        if (isalnum(*e))
        {
            printf("%c",*e);
        }
        else if (*e == '(') {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while (priority(Stack[tos]) >= priority(*e)) {
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }

    while (tos != -1)
    {
        putchar(pop());
    }
    
    return 0;
}
