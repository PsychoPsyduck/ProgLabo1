#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[500], lastName[500], id[500],isEmpty[500];
    int cont=1;

    FILE * pFile;

    pFile = fopen ("data.csv", "r");

 fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);
 printf("%s--%s--%s--%s\n", id, name, lastName, isEmpty);
    while(!feof(pFile))
    {
if(cont==5)
    system("pause");

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

        printf("%s - %s, %s - %s\n", id, name, lastName, isEmpty);
        cont++;
    }

    fclose(pFile);

    return(0);
}
