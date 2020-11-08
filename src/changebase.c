#include <stdio.h>
#include <stdlib.h>
void convertBase(int a, int base);

int main(int argc, char** argv)
{
    if (argc < 3) exit(EXIT_FAILURE);

    int number = atol(argv[1]), base = atol(argv[2]);
    convertBase(number, base);
    exit(EXIT_SUCCESS);
}

void convertBase(int a, int base)
{
    if (a / base == 0)
    {
        printf("%d", a % base);
        return;
    }
    convertBase(a / base, base);
    printf("%d", a % base);
}
