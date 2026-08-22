#include <stdio.h>

struct Frame
{
    int n;
    char from, to, aux;
    int step;
};

int main()
{
    int n, top = -1;
    struct Frame stack[100];

    printf("Enter number of disks: ");
    scanf("%d", &n);

    top++;
    stack[top].n = n;
    stack[top].from = 'A';
    stack[top].to = 'C';
    stack[top].aux = 'B';
    stack[top].step = 0;

    while(top >= 0)
    {
        if(stack[top].n == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   stack[top].from, stack[top].to);
            top--;
        }
        else if(stack[top].step == 0)
        {
            stack[top].step = 1;

            top++;
            stack[top].n = stack[top - 1].n - 1;
            stack[top].from = stack[top - 1].from;
            stack[top].to = stack[top - 1].aux;
            stack[top].aux = stack[top - 1].to;
            stack[top].step = 0;
        }
        else if(stack[top].step == 1)
        {
            printf("Move disk %d from %c to %c\n",
                   stack[top].n,
                   stack[top].from,
                   stack[top].to);

            stack[top].step = 2;

            top++;
            stack[top].n = stack[top - 1].n - 1;
            stack[top].from = stack[top - 1].aux;
            stack[top].to = stack[top - 1].to;
            stack[top].aux = stack[top - 1].from;
            stack[top].step = 0;
        }
        else
        {
            top--;
        }
    }

    return 0;
}
