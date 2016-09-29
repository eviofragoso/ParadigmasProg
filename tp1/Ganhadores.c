/*
Programador: Maxwell Borges Bezerra
Disciplina: Paradigma de Programacao
Programa: Lista de ganhadoras em C

Link do github:
https://github.com/maxbborges/PProgMaxwell.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq, *arq1;

struct ganhadoras
{
    char nome[50];
};

int compara (const void * a, const void * b )
{
    struct ganhadoras *ia = (struct ganhadoras *)a;
    struct ganhadoras *ib = (struct ganhadoras *)b;

    return strcmp(ia->nome, ib->nome);
}

int main ()
{
    struct ganhadoras ganha[20];
    int i=0, j, aux=0;
    arq = fopen("ArqInput.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na Leitura do arquivo\n");
        return 0;
    }

    else
    {
        while(!feof(arq))
        {
            fscanf(arq,"%[^\n]s", ganha[i].nome);
            fscanf(arq,"\n");
            setbuf(stdin, NULL);
            i++;
        }

        printf("\n%d nomes na lista\n", i);
        printf("Ordenando nomes...\n");
        qsort(ganha, i, sizeof(struct ganhadoras), compara);
        printf("Ordenacao Concluida\n");

        arq1 = fopen("ArqOutput.html", "w+");

        fprintf (arq1,"<ul>");
        printf("A Receber vencedores \n");
        for (j=0; j<i; j++)
        {
            if(ganha[j].nome[0]=='R')
            {
                fprintf(arq1,"<li>%s</li>\n",ganha[j].nome);
                aux++;
            }
        }

        printf ("Arqivo de saida completo.\n");
        fprintf (arq1,"</ul>");
        fclose(arq1);
    }

    fclose(arq);

    return 0;
}
