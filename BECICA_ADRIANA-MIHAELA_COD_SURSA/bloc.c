#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include "bloc.h"

typedef struct bloc
{
    int nr_bloc;
    int nr_etaj;
    int nr_apart;
    int nr_camere;
    char *pret;
    char *ocv;

} BLOC;


BLOC *blocuri;
int n;


BLOC* citire_informatii_bloc(int *n)
{
    BLOC *v;
    char var[255],ocv[30],pret[30];
    FILE *f=fopen("bloc.txt","rt");
    if(f==NULL)
    {
        printf("EROARE la deschiderea fisierului!");
        return 0;
    }
    fscanf(f,"%d", n);
    v=malloc((*n)*sizeof(BLOC));
    for(int i=0; i<*n; i++)
    {
        fscanf(f,"%d",&v[i].nr_bloc);
        fscanf(f,"%d",&v[i].nr_etaj);
        fscanf(f,"%d",&v[i].nr_apart);
        fscanf(f,"%d",&v[i].nr_camere);

        fgets(var,sizeof(var),f);
        strcpy(pret,strtok(var,","));
        strcpy(ocv,strtok(NULL,","));
        v[i].pret=malloc(strlen(pret)+1*sizeof(char));
        v[i].ocv=malloc(strlen(ocv)+1*sizeof(char));
        strcpy(v[i].pret,pret+1);
        strcpy(v[i].ocv,ocv);

    }
    fclose(f);
    return v;
}

void afisare(BLOC *b, int n)
{

    for(int i = 0; i < n; i++)
    {
        printf(" NUMAR BLOC %d\n", b[i].nr_bloc);
        printf(" NUMAR etaj %d\n", b[i].nr_etaj);
        printf("NUMAR apartament %d\n", b[i].nr_apart);
        printf("NUMAR camere %d\n", b[i].nr_camere);
        printf("pret %s\n", b[i].pret);
        printf("observatie %s\n\n", b[i].ocv);


    }

}



PERSOANE *persoane;
LOGIC errFisier, ans;
int numarpersoane;

int s;
void mainmenu()
{
    char choice;

    while(1)
    {
        system("cls");
        blocuri= citire_informatii_bloc(&n);

        int i;

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENIUL PROIECTULUI \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 1. Harta blocuri  ");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 2. Informatii bloc");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 3. Inchiriere apartamente");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 4. Cumparate apartamente");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 5. Aratati informatiile persoanelor care au inchiriat apartamente");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 6. Aratati informatiile persoanelor care au cumparat apartamente");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 7. Iesire din program");

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\t\t");
        t();

        printf("\n\t\t");
        printf("Alege optiunea:");
        choice = toupper(getch());
        switch(choice)
        {
        case '1':
            harta();
            break;
        case '2':
            informatii();
            break;
        case '3':
            afisare_apartamente_inchiriate(blocuri,n);
            break;
        case '4':
            afisare_apartamente_vanzare(blocuri,n);
            break;
        case '5':
        {
            system("cls");
            free(persoane);
            persoane = citirepersoane("apartamentc.txt",&numarpersoane);
            printf("\n\n\t\tPersoanele care au inchiriat apartamente");
            afisarepersoane(persoane, numarpersoane);
        }

        getch();
        break;

        case '6':
        {
            system("cls");
            free(persoane);
            persoane = citirepersoane("apartamentv.txt",&numarpersoane);
            printf("\n\n\t\tPersoanele care au cumparat apartamente");
            afisarepersoane(persoane, numarpersoane);
        }
        getch();
        break;

        case '7':
        {
            system("cls");

            printf("\n\n\t\tBlocurile unui oras\n\n");

            printf("\t\tProiect realizat de:\n\n");

            printf("\t\tBecica Adriana-Mihaela\n\n");

            printf("\t\tGrupa 3114B");


            printf("\n\n\n\n\n\n\t\tIesire din program in 3 secunde...........>\n\n");

            Sleep(3000);
            exit(0);
        }

        default:
        {
            printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");
            if(getch())
                mainmenu();
        }
        }
        fflush(stdin);
    }

}


void harta()
{
    system("cls");
    int i;

    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2HARTA ORASULUI\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\t\t\t\t|\t\t\t\t|\t\t\t\t     /\n");
    printf("\t\t\t\t|\t\tF\t\t|\t\t\t\t\    /\n");
    printf("\t\tBLOC 8\t\t|\t\tA\t\t|\t\t\t\t   /\n");
    printf("\t\t\t\t|\t\tR\t\t| \t\tSPITAL\t\t  /\n");
    printf("\t\t\t\t|\t\tM\t\t|\t\t\t\t /\n");
    printf("\t\t\t\t|\t\tA\t\t|\t\t\t\t/\n");
    printf("\t\t________________|\t\tC\t\t|______________________________/\tBLOC 5\n");
    printf("\t\t\t\t\\\t\tI\t\t/\t\t\t\t\\ \n");
    printf("\t\t\t\t \\ \t\tE\t\t/\t\t\t\t \\_____________/\n");
    printf("\t\t\t\t \\\t\t\t\t/\t\tBLOC 6 \t\t \\ \t\n");
    printf("\t\tBISERICA\t \\______________________________/_________________________________\\ \t\n");
    printf("\t\t\t\t  / \t\t\t\t\t\t\t\t  |\n");
    printf("\t\t\t\t /\t\tPIATA\t\t\t\t\t\t  |\tPRIMARIA\n");
    printf("\t\t\t\t/\t\t\t\tCENTRALA\t\t\t  |\n");
    printf("\t\t_______________/\t\t\t\t\t\t\t\t  |__________________\n");
    printf("\t\t\t       |\t\t\t\t\t\t\t\t  |\n");
    printf("\t\t\t       |\t\t\t\t\t\t\t\t  |\n");
    printf("\t\tBLOC 9\t       |__________________________________________________________________|\n");
    printf("\t\t\t       |\t\t\t\t\t\t\t\t  |\n");
    printf("\t\t_______________|\t\t\t\t\t\t\t\t  \\ \tBLOC 3\n");
    printf("\t\t\t       |\t\t\t\tBLOC 7\t\t\t\t  \\ \n");
    printf("\t\t\t       |\t\t\t\t\t\t\t\t  \\ \n");
    printf("\t\tBLOC  10       |__________________________________________________________________\\\n");
    printf("\t\t_______________|\t\t\t|\t\t\t|\t\t   \\\n");
    printf("\t\t\t       |\tSCOALA\t\t|\tBLOC 2\t\t|\tPOLITIA\t    \\\n");
    printf("\t\t\t       |\t\t\t|\t\t\t|\t\t     \\\n");
    printf("\t\tBLOC 1\t       |\t\t\t|\t\t\t|\t\t      \\\n");
    printf("\t\t\t       |\t\t\t|\t\t\t|\t\t       \\\n");

    printf("Apasa orice tasta pentru a reveni la meniul principal. ");

    if(getch())
        mainmenu();




}

int t(void)
{
    time_t t;
    time(&t);
    printf("Data:%s\n",ctime(&t));

    return 0 ;
}

void informatii()
{
    int choice;

    //blocuri= citire_informatii_bloc(&n);
    while(1)
    {
        system("cls");

        int i;

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 1. BLOC 1  ");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 2. BLOC 2");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 3. BLOC 3");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 4. BLOC 4");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 5. BLOC 5");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 6. BLOC 6");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 7. BLOC 7");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 8. BLOC 8");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 9. BLOC 9");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 10. BLOC 10");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 11. Revenire la meniul principal");

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\t\t");
        t();

        printf("\t\t");
        printf("Alege optiunea:");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        {
            blocul(blocuri,n,choice);
            getch();
        }
        break;

        case 11:
            mainmenu();
            break;

        default:
            printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!\n");
            printf("\t\tApasati orice tasta pentru a continua... ");
            getch();


        }
        fflush(stdin);
    }


}



void afisare_apartamente_inchiriate(BLOC *b,int n)
{


    char key[]="inchiriere\n";
    int choice,max=0,l[100][5];

    // while(1)
    // {

    system("cls");

    int i,nr=0,ok=0;

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Apartamentele disponibile pentru inchiriere \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    for(int i = 0; i < n; i++)
        if(strcmp(key,b[i].ocv)==0)
        {
            nr++;
            printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2%d. Apartament %d Etaj %d Bloc %d\n",nr,b[i].nr_apart,b[i].nr_etaj,b[i].nr_bloc);
            l[nr][3]=b[i].nr_apart;
            l[nr][2]=b[i].nr_etaj;
            l[nr][1]=b[i].nr_bloc;

        }


    if(nr==0)
        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nu mai exista aprtamente disponibile spre inchiere");
    printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2%d. Revenire la meniul principal",nr+1);

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\t\t");
    t();

    printf("\t\t");
    printf("Alege optiunea:");
    scanf("%d",&choice);

    int j;
    for(j=1; j<=nr; j++)
        if(j==choice)
        {
            apartament(blocuri,n,l[j][1],l[j][2],l[j][3],2);
            getch();
        }


    if(nr+1==choice)
    {
        mainmenu();
        getch();
    }
    else
    {
        printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");
        getch();
        afisare_apartamente_inchiriate(blocuri,n);
    }






}
void afisare_apartamente_vanzare(BLOC *b,int n)
{


    char key[]="vanzare\n";
    int choice,max=0,l[100][5];

    // while(1)
    // {

    system("cls");

    int i,nr=0,ok=0;

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Apartamentele disponibile pentru vanzare \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    for(int i = 0; i < n; i++)
        if(strcmp(key,b[i].ocv)==0)
        {
            nr++;
            printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2%d. Apartament %d Etaj %d Bloc %d\n",nr,b[i].nr_apart,b[i].nr_etaj,b[i].nr_bloc);
            l[nr][3]=b[i].nr_apart;
            l[nr][2]=b[i].nr_etaj;
            l[nr][1]=b[i].nr_bloc;

        }


    if(nr==0)
        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nu mai exista aprtamente disponibile spre vanzare");

    printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2%d. Revenire la meniul principal",nr+1);

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\t\t");
    t();

    printf("\t\t");
    printf("Alege optiunea:");
    scanf("%d",&choice);

    int j;
    for(j=1; j<=nr; j++)
        if(j==choice)
        {
            apartament(blocuri,n,l[j][1],l[j][2],l[j][3],3);
            getch();
        }


    if(nr+1==choice)
    {
        mainmenu();
        getch();
    }
    else
    {
        printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");
        getch();
        afisare_apartamente_vanzare(blocuri,n);
    }






}

void inchiriere(int a,int x,int y)
{
    char choice;

    while(1)
    {


        int i;


        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 1. Inchiriati acest apartament ");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 2. Reviniti la meniul anterior");




        printf("\n\n\t\t");
        printf("Alege optiunea:");
        choice = toupper(getch());
        switch(choice)
        {
        case '1':
            persoane_inchiriere(a,x,y);
            break;
        case '2':
            afisare_apartamente_inchiriate(blocuri,n);
            break;

        default:
        {
            printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");
            if(getch())
                inchiriere(a,x,y);

        }
        }
        fflush(stdin);
    }
}
void vanzare(int a,int x,int y)
{
    char choice;

    while(1)
    {


        int i;


        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 1. Cumparati acest apartament ");

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 2. Reviniti la meniul anterior");




        printf("\n\n\t\t");
        printf("Alege optiunea:");
        choice = toupper(getch());
        switch(choice)
        {
        case '1':
            persoane_vanzare(a,x,y);
            break;
        case '2':
            afisare_apartamente_vanzare(blocuri,n);
            break;

        default:
        {
            printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");
            if(getch())
                inchiriere(a,x,y);

        }
        }
        fflush(stdin);
    }
}
void blocul(BLOC *b,int n, int x)
{
    system("cls");
    int choice,max=0;
    for(int i = 0; i < n; i++)
        if((b[i].nr_bloc==x)&&(max<b[i].nr_etaj))
            max=b[i].nr_etaj;
    printf("%d",max);
    //while(1)
    //{
    system("cls");

    int i;

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    for(i=1; i<=max; i++)
        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 %d. ETAJ %d ",i,i);

    printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 %d. Revenire la meniul principal",max+1);

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\t\t");
    t();

    printf("\t\t");
    printf("Alege optiunea:");
    scanf("%d",&choice);


    for(i=1; i<=max; i++)
        if(i==choice)

        {
            etaj(blocuri,n,x,i);
            getch();
            //apartament();
        }

    if(max+1==choice)
        mainmenu();
    else
    {
        printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!\n");
        printf("\t\tApasati orice tasta pentru a continua... ");
        getch();
        fflush(stdin);
    }



    //  }




}

void etaj(BLOC *b,int n, int x,int a)
{
    system("cls");
    int choice,max=0;
    for(int i = 0; i < n; i++)
        if((b[i].nr_bloc==x)&&(b[i].nr_etaj==a)&&(max<b[i].nr_apart))
            max=b[i].nr_apart;
    printf("%d",max);
    while(1)
    {
        system("cls");

        int i;

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selecteaza \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        for(i=1; i<=max; i++)
            printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 %d. APARTAMENT %d ",i,i);

        printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 %d. Revenire la meniul principal",max+1);

        printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");



        printf("\t\t");
        printf("Alege optiunea:");
        scanf("%d",&choice);


        for(i=1; i<=max; i++)
            if(i==choice)

            {

                apartament(blocuri,n,x,a,i,1);
                getch();

            }

        if(max+1==choice)
            mainmenu();
        else
            printf("\n\n\t\tOptiune gresita!Va rog alegeti una din optiunile de mai sus!");





    }




}


void apartament(BLOC *b,int n, int a,int x, int y, int q)
{
    system("cls");
    int choice,max=0;
    char c;

    for(int i = 0; i < n; i++)
        if((b[i].nr_bloc==a)&&(b[i].nr_etaj==x)&&(b[i].nr_apart==y)&&(max<b[i].nr_apart))
        {
            printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

            printf("\t\t\xDB\xDB\xB2  NUMAR BLOC %d\n\n", b[i].nr_bloc);

            printf("\t\t\xDB\xDB\xB2  NUMAR ETAJ %d\n\n", b[i].nr_etaj);

            printf("\t\t\xDB\xDB\xB2  NUMAR APARTAMENT %d\n\n", b[i].nr_apart);

            printf("\t\t\xDB\xDB\xB2  NUMAR CAMERE %d\n\n", b[i].nr_camere);

            printf("\t\t\xDB\xDB\xB2  PRET %s\n\n", b[i].pret);

            printf("\t\t\xDB\xDB\xB2  OBSERVATIE %s \n", b[i].ocv);

            printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        }

    if(q==1)
        printf("\n\nApasa enter pentru revenire la meniul anterior.");
    else if (q==2)
        inchiriere(a,x,y);
    else if(q==3)
        vanzare(a,x,y);






}





void persoane_inchiriere(int a,int x,int y)//aici trebuie salvat in fisier
{

    free(persoane);
    persoane = citirepersoane("apartamentc.txt",&numarpersoane);

    PERSOANE p = citirepersoana();
    persoane = adaugarepersoanamemorie(persoane, &numarpersoane, p);
    if(adaugarepersoane("apartamentc.txt", persoane, numarpersoane) == 1)
        printf("\n\t\tDatele s-au salvat.\n");
    else
        printf("Eroare la deschiderea fisierului.\n");
    schimbare ("bloc.txt", blocuri, n,a, x, y);


    printf("\t\tApasati orice tasta pentru a reveni la meniul anterior.");

    getch();
    afisare_apartamente_inchiriate(blocuri,n);

}

void persoane_vanzare(int a,int x,int y)//aici trebuie salvat in fisier
{

    free(persoane);
    persoane = citirepersoane("apartamentv.txt",&numarpersoane);

    PERSOANE p = citirepersoana();
    persoane = adaugarepersoanamemorie(persoane, &numarpersoane, p);
    if(adaugarepersoane("apartamentv.txt", persoane, numarpersoane) == 1)
        printf("\n\t\tDatele s-au salvat.\n");
    else
        printf("Eroare la deschiderea fisierului.\n");
    schimbare ("bloc.txt", blocuri, n,a, x, y);


    printf("\t\tApasati orice tasta pentru a reveni la meniul anterior.");

    getch();
    afisare_apartamente_vanzare(blocuri,n);

}
LOGIC schimbare (char *numeFisier, BLOC *b, int n,int a,int x,int y)
{
    FILE *f = fopen(numeFisier, "wt");
    if(f == NULL)
        return FALS;
    fprintf(f,"%d",n);
    fprintf(f,"\n");
    for(int i = 0; i < n; i++)
    {
        fprintf(f,"%d ",b[i].nr_bloc);
        fprintf(f,"%d ",b[i].nr_etaj);
        fprintf(f,"%d ",b[i].nr_apart);
        fprintf(f,"%d ",b[i].nr_camere);
        fprintf(f,"%s,",b[i].pret);
        if((b[i].nr_bloc==a)&&(b[i].nr_etaj==x)&&(b[i].nr_apart==y))
        {
            strcpy(b[i].ocv,"ocupat");
            fprintf(f,"%s",b[i].ocv);
        }
        else
            fprintf(f,"%s",b[i].ocv);
        fprintf(f,"\n");
    }
    fclose(f);
    return ADEVARAT;

}


PERSOANE* citirepersoane(char *numeFisier, int *m)
{
    PERSOANE *tabpersoane;
    char var[255], s[2] = ",", _nume[100], _prenume[20];
    FILE *f = fopen(numeFisier, "rt");
    if(f == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(0);
    }
    fscanf(f, "%d", m);
    tabpersoane = malloc(*m * sizeof(PERSOANE));
    for(int i = 0; i < *m; i++)
    {
        fscanf(f, "%d", &tabpersoane[i].cnp);
        fgets(var, sizeof(var), f);
        strcpy(_nume, strtok(var, s));
        strcpy(_prenume, strtok(NULL, s));
        tabpersoane[i].nume = calloc(strlen(_nume) + 1, sizeof(char));
        strcpy(tabpersoane[i].nume, _nume + 1);
        tabpersoane[i].prenume = calloc(strlen(_prenume) + 1, sizeof(char));
        strcpy(tabpersoane[i].prenume, _prenume);
    }
    fclose(f);
    return tabpersoane;
}

LOGIC adaugarepersoane (char *numeFisier, PERSOANE *p, int m)
{
    FILE *f = fopen(numeFisier, "wt");
    if(f == NULL)
        return FALS;
    fprintf(f, "%d\n", m);
    for(int i = 0; i < m; i++)
    {
        fprintf(f, "%d ", p[i].cnp);
        fprintf(f, "%s,", p[i].nume);
        fprintf(f, "%s", p[i].prenume);
        fprintf(f, "\n");
    }
    fclose(f);
    return ADEVARAT;

}

PERSOANE citirepersoana()
{
    system("cls");
    PERSOANE p;
    char var[255];
    printf("\n\n\t\tIntroduceti informatile!\n");
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\tCNP persoana: ");
    scanf("%d", &p.cnp);
    printf("\n\t\tNume: ");
    fflush(stdin);
    gets(var);
    p.nume = malloc(strlen(var) + 1);
    strcpy(p.nume, var);
    printf("\n\t\tPrenume: ");
    gets(var);
    p.prenume = malloc(strlen(var) + 1);
    strcpy(p.prenume, var);
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");


    return p;

}

void afisarepersoane(PERSOANE *p, int m)
{

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    for(int i = 0; i < m; i++)
    {
        printf("\t\t");
        printf("%d\t", p[i].cnp);
        printf("%s\t", p[i].nume);
        printf("%s", p[i].prenume);
    }
    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\n\t\tApasa orice tasta pentru a reveni la meniul principal. ");
}

PERSOANE* adaugarepersoanamemorie(PERSOANE *p, int *m, PERSOANE p1)
{
    p = realloc(p, sizeof(PERSOANE) * (*m + 1));
    p[*m].cnp = p1.cnp;
    p[*m].nume = malloc((strlen(p1.nume) + 1));
    strcpy(p[*m].nume, p1.nume);
    p[*m].prenume = malloc((strlen(p1.prenume) + 1));
    strcpy(p[*m].prenume, p1.prenume);
    *m = *m + 1;
    return p;
}
