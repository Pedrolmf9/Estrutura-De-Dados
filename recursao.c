#include <stdio.h>
#include <stdlib.h>


void recursiveFunction(int num)
{
    if (num < 5)
    {
        printf("%d\n", num);
        recursiveFunction(num + 1);
        printf("%d\n", num);
    }
}

int main() {
    recursiveFunction(0);
}