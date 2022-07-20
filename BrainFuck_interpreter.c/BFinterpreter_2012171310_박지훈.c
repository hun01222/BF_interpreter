#include <stdio.h>
#include <stdlib.h>

void plus(void);
void minus(void);
void increment(void);
void decrement(void);
void comma(void);
void fullstop(void);
void loop(void);
void loopout(void);
void input(void);
void opt(void);

struct NODE
{
    int value;
    struct NODE *next;
} * head, *curr, *ptr, *loopptr[100];

int i = -1, j = -1;
char n;
char a[60000] = {
    0,
};
char k[100] = {
    0,
};

int main()
{
    ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->value = 0;
    ptr->next = NULL;
    curr = ptr;
    head = ptr;

    while (n != -1)
    {
        input();
        opt();
    }
    printf("\n");

    return 0;
}

void plus(void)
{
    curr->value += 1;
    ptr = curr;
}

void minus(void)
{
    curr->value -= 1;
    ptr = curr;
}

void increment(void)
{
    if (curr->next == NULL)
    {
        ptr = (struct NODE *)malloc(sizeof(struct NODE));
        ptr->value = 0;
        ptr->next = NULL;
        curr->next = ptr;
    }
    else
        ptr = curr->next;
    curr = ptr;
}

void decrement(void)
{
    ptr = head;
    while (ptr->next != curr)
    {
        ptr = ptr->next;
    }
    curr = ptr;
}

void comma(void)
{
    scanf("%d", &curr->value);
    ptr = curr;
}

void fullstop(void)
{
    printf("%c", curr->value);
}

void loop(void)
{
    j++;
    k[j] = i;
    loopptr[j] = curr;
}

void loopout(void)
{
    while (curr->value != 0)
    {
        i = k[j];
        curr = loopptr[j];

        while (a[i] != ']')
        {
            n = a[i];
            opt();
            i++;
        }
        curr = loopptr[j];
    }
    j--;
}

void opt(void)
{
    if (n == '+')
        plus();
    else if (n == '-')
        minus();
    else if (n == '>')
        increment();
    else if (n == '<')
        decrement();
    else if (n == ',')
        comma();
    else if (n == '.')
        fullstop();
    else if (n == '[')
        loop();
    else if (n == ']')
        loopout();
    else
        n = -1;
}

void input(void)
{
    scanf("%c", &n);
    i++;
    a[i] = n;
}
