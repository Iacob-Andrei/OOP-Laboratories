#include <stdio.h>
#include <string.h>

int convert_string_to_number(char* s)
{

    int nr = 0, i = 0;

    int n = strlen(s) - 1;

    int ok = 0;
    if (s[0] == '-')
        { ok = 1; i = 1; }

    for (i; i < n; ++i)
    {
        int cifra = s[i] - '0';
        nr = nr * 10;
        nr = nr + cifra;
    }
    if (ok) nr = nr * (-1);

    return nr;

}


int main()
{
    int nr, suma = 0;
    FILE* fp = fopen("ini.txt", "r");

    char s[240];

    while ( fgets(s, sizeof(s), fp) != 0 )
    {
        nr = convert_string_to_number(s);
        suma += nr;
    }
    printf("%d", suma);


    return 0;
}

