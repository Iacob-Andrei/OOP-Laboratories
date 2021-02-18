#include <stdio.h>
#include <string.h>

// I went to the library yesterday

int main()
{
    char str[250] , vector_cuvinte[25][250] , aux[250] ;
    int i , j , k = 0;
    scanf("%[^\n]",str);
    char *token;

    token = strtok(str, " ");
    while( token != NULL )
    {
      strcpy( vector_cuvinte[k] , token );
      k++;
      token = strtok(NULL, " ");
    }

    for (i = 0; i < k-1; i++)
       for (j = 0; j < k-i-1; j++)
            if ( strlen( vector_cuvinte[j] ) < strlen( vector_cuvinte[j+1] ) )
           {
               strcpy( aux , vector_cuvinte[j] );
               strcpy( vector_cuvinte[j] , vector_cuvinte[j+1] );
               strcpy( vector_cuvinte[j+1] , aux );
           }
            else if( strlen( vector_cuvinte[j] ) == strlen( vector_cuvinte[j+1]) )
                    if( strcmp( vector_cuvinte[j] , vector_cuvinte[j+1] ) > 0 )
                        {
                            strcpy( aux , vector_cuvinte[j] );
                            strcpy( vector_cuvinte[j] , vector_cuvinte[j+1] );
                            strcpy( vector_cuvinte[j+1] , aux );
                        }

        for( j = 0 ; j <= k ; j++ )
            printf("%s\n" , vector_cuvinte[j] );
   return 0;
}
