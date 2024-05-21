#include <stdio.h>
#include <stdlib.h>

typedef struct stack 
{
    int *a;
    int top;
    int size;
} stack;

void init(stack *s, int n) 
{
    s->size = n;
    s->top = -1;
    s->a = (int *)malloc(s->size * sizeof(int));
}

int isempty(stack *s) 
{
    return (s->top == -1);
}

int isfull(stack *s) 
{
    return (s->top == s->size - 1);
}

void push(stack *p, int item) 
{
    if (isfull(p)) {
        printf("overflow\n");
    } else {
        p->a[++(p->top)] = item;
    }
}

int pop(stack *s1) 
{
    if (isempty(s1)) 
    {
        printf("underflow\n");
        return -1; // Returning -1 as an error code since underflow occurred
    } 
    else 
    {
        return s1->a[(s1->top)--];
    }
}

void multipop(stack *s1, int t1) 
{
    int item;
    while (!isempty(s1) && t1 > 0) 
    {
        item = pop(s1);
        if (item != -1) 
        { // Check if pop was successful
            t1--;
            printf("the popped ele is : %d\n", item);
        }
    }
}

int main() 
{
    stack s1;
    int n, y, t1;

    printf("Enter size: ");
    scanf("%d", &n);

    init(&s1, n);

    printf("Push the elements\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Enter %d Element plz: ", i + 1);
        scanf("%d", &y);
        push(&s1, y);
    }

    printf("How many times you want to pop elements: ");
    scanf("%d", &t1);

    multipop(&s1, t1);

    // Free allocated memory
    free(s1.a);

    return 0;
}

