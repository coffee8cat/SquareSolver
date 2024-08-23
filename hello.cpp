#include <stdio.h>

void f();

int main()
{

    for(int i=0; i<5; i++)
    {
        f();
    }
}

void f()
{
    static int x = 0;
    int y = 0;

    x++;
    y++;

    printf("x = %d y = %d", x, y);
}
