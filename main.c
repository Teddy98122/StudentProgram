#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define clear() printf("\033[H\033[J")
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
struct node
{
    char prenume[20],nume[20],facultatea[20],specializarea[20];
    int note[10],media;
    struct node *adr_urm;
};
struct node *primul=NULL;
struct node *ultimul=NULL;
struct node* createNode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return temp;
};
int cautare();
void inserare_fata();
void inserare_spate();
void printare();
void modifica_student();
void adauga_nota_student();
int afisare_medie();
void sterge_student();
void inserare_in_fisier();
void inserare_alfabetic_in_fisier();
void afisare_alfabetica();
void afisare_nr_studenti();
int main()
{
    char nume[20],prenume[20],specializare[20],facultate[20];
    int nota,index;
    int choice=0;
    do
    {
    printf(ANSI_COLOR_MAGENTA "\n\tMENIU STUDENTI");//MENIUL PRINCIPAL
    printf("\n\t------------------------------" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n\t 1. ADAUGA STUDENT LA INCEPUT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n\t 2. MODIFICA STUDENT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t 3. AFISEAZA LISTA DE STUDENTI" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\n\t 4. ADAUGA STUDENT LA SFARSIT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "\n\t 5. MODIFICAREA NOTELOR UNUI STUDENT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t 6. AFISAREA MEDIEI NOTELOR UNUI STUDENT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "\n\t 7. STERGEREA UNUI STUDENT" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n\t 8. SALVATI: INSERATI TOTUL INTR-UN FISIER !!!" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "\n\t 9. SALVATI: INSERATI TOTUL INTR-UN FISIER ALFABETIC !!!" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE "\n\t 10. AFISARE ALFABETICA !!!" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\n\t 11. AFISAREA NUMARUL STUDENTIILOR INSCRISI IN LISTA !!!" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t 12. EXIT !!!" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n\n INSERATI NUMARUL DORIT: " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA);
    scanf("%d",&choice);
   // clear();
    printf("\n");
    switch(choice)
    {
    case 1:
        printf("\n INTRODUCE-TI STUDENTII IN LISTA \n");
        printf("PRENUME:\n");
        scanf("%s",prenume);
        printf("NUME: \n");
        scanf("%s",nume);
        printf("FACULTATE:\n");
        scanf("%s",facultate);
        printf("SPECIALIZARE:\n");
        scanf("%s",specializare);
        printf("NOTA:\n");
        scanf("%d",&nota);
        printf("NR NOTA:\n");
        scanf("%d",&index);
        inserare_fata(prenume,nume,facultate,specializare,nota,index);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        break;
    case 2:
        printf("\nATI SLECTAT OPTIUNEA DE MODIFICARE A UNUI STUDENT  \n");
        printf("PRENUME:\n");
        scanf("%s",prenume);
        printf("NUME: \n");
        scanf("%s",nume);
        modifica_student(nume,prenume);
        break;
    case 3:
        printf("\nATI SLECTAT OPTIUNEA DE AFISARE A STUDENTIILOR  \n");
        printare();
        break;
    case 4:
        printf("\n INTRODUCE-TI STUDENTII IN LISTA \n");
        printf("PRENUME:\n");
        scanf("%s",prenume);
        printf("NUME: \n");
        scanf("%s",nume);
        printf("FACULTATE:\n");
        scanf("%s",facultate);
        printf("SPECIALIZARE:\n");
        scanf("%s",specializare);
        printf("NOTA:\n");
        scanf("%d",&nota);
        printf("NR NOTA:\n");
        scanf("%d",&index);
        inserare_spate(prenume,nume,facultate,specializare,nota,index);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        break;
    case 5:
        printf("\nATI SLECTAT OPTIUNEA PT MODIFICAREA NOTEI UNUI STUDENT  \n");
        printf("PRENUME:\n");
        scanf("%s",prenume);
        printf("NUME: \n");
        scanf("%s",nume);
        adauga_nota_student(nume,prenume);
        break;
    case 6:
        printf("PRENUME:\n");
        scanf("%s",prenume);
        printf("NUME: \n");
        scanf("%s",nume);
        afisare_medie(nume,prenume);
        break;
    case 7:
        sterge_student();
        break;
    case 8:
        inserare_in_fisier();
        printf("\n SALVARE EFECTUATA CU SUCCES \n");
        break;
    case 9:
        inserare_alfabetic_in_fisier();
        printf("\n INSERARE IN FISIER EFECTUATA CU SUCCES\n");
        break;
    case 10:
        afisare_alfabetica();
        printf("\n STUDENTII AU FOST AFISATI IN ORDINE ALFABETICA\n");
        break;
    case 11:
        afisare_nr_studenti();
        break;
    case 12:
        printf("\nATI SELECTAT CEA DE-A PATRA ACTIUNE, \n MULTUMIM PENTRU UTILIZARE \n");
        exit(0);
        break;
    default:
        printf("\nALEGERE INVALIDA...Te rog sa mai incerci !!! \n");
    }
}while(choice!=12);
    return 0;
}
 int cautare(char *pren,char *num)//FUNCTIE DE CAUTARE
{
    struct node *traverse;
    traverse=createNode();
    traverse=primul;
    int i=0;
    while(traverse!=NULL)
    {
        i++;
        if((strcmp(traverse->nume,num)&&strcmp(traverse->prenume,pren))==0)
        {
            return i;
        }
        traverse=traverse->adr_urm;
    }
    return 0;
}
void inserare_fata(char pren[20],char num[20],char fac[20],char spec[20],int not,int index)//FUNCTIE PENTRU INSERAREA UNUI STUDENT IN FATA LISTEI
{
    struct node *temp;
    temp=createNode();
    strcpy(temp->nume,num);
    strcpy(temp->prenume,pren);
    strcpy(temp->facultatea,fac);
    strcpy(temp->specializarea,spec);
    if(not<11)
    {
        temp->note[index]=not;
    }
    if(primul==NULL)
    {
        primul=temp;
    }
    else
    {
        temp->adr_urm=primul;
        primul=temp;
    }
}
void inserare_spate(char pren[20],char num[20],char fac[20],char spec[20],int not,int index)//FUNCTIE PENTRU INSERAREA UNUI STUDENT IN SPATELE LISTEI
{
    struct node *temp;
    struct node *traverse;
    traverse=primul;
    temp=createNode();
    strcpy(temp->nume,num);
    strcpy(temp->prenume,pren);
    strcpy(temp->facultatea,fac);
    strcpy(temp->specializarea,spec);
    if(not<11)
    {
        temp->note[index]=not;
    }
    if(primul==NULL)
    {
        primul=temp;
    }
    else
    {
        while(traverse->adr_urm!=NULL)
        {
            traverse=traverse->adr_urm;
        }
        traverse->adr_urm=temp;
    }
}
void printare()//FUNCTIE DE AFISAREA
{
    struct node *traverse;
    traverse=primul;
    int i;
    while(traverse!=NULL)
    {
        printf("PRENUME: %s \n ",traverse->prenume);
        printf("NUME: %s\n",traverse->nume);
        printf("FACULTATE: %s \n",traverse->facultatea);
        printf("SPECIALIZARE: %s\n",traverse->specializarea);
        printf("NOTE: \n");
        for(i=0;i<10;i++)
        {
            printf("%d ",traverse->note[i]);
        }
        printf("\n");
        afisare_medie(traverse->nume,traverse->prenume);
        traverse=traverse->adr_urm;
        printf("\n");
        printf("\n");
    }
}
void modifica_student(char num[20],char prenum[20])//FUNCTIE PENTRU MODIFICAREA DATELOR UNUI STUDENT
{
    char facultate[20],specializare[20];
    int nota,index,n=0;
    struct node *traverse;
    traverse=primul;
    while(traverse!=NULL&&n!=-1)
    {
        if((strcmp(traverse->nume,num)&&strcmp(traverse->prenume,prenum))==0)
        {
            printf("STUDENT GASIT !!! \n \n \n");
            printf("FACULTATE:\n");
            scanf("%s",facultate);
            strcpy(traverse->facultatea,facultate);
            printf("SPECIALIZARE:\n");
            scanf("%s",specializare);
            strcpy(traverse->specializarea,specializare);
            printf("NR NOTA:\n");
            scanf("%d",&index);
            printf("NOTA:\n");
            scanf("%d",&nota);
            traverse->note[index]=nota;
            printf("PENTRU REVENIREA LA MENIUL PRINCIPAL INSERATI -1 \n\n");
            scanf("%d",&n);
        }
        traverse=traverse->adr_urm;
    }
}
void adauga_nota_student(char num[20],char prenum[20])//FUNCTIE PT ADAUGAREA DE NOTE UNUI STUDENT
{
    int nota,index,n=0;
    struct node *traverse;
    traverse=primul;
    while(traverse!=NULL&&n!=-1)
    {
        if((strcmp(traverse->nume,num)&&strcmp(traverse->prenume,prenum))==0)
        {
            printf("STUDENT GASIT, PUTETI MODIFICA NOTA !!! \n \n \n");
            printf("NR NOTA:\n");
            scanf("%d",&index);
            printf("NOTA:\n");
            scanf("%d",&nota);
            traverse->note[index]=nota;
            printf("PENTRU REVENIREA LA MENIUL PRINCIPAL INSERATI -1 \n\n");
            scanf("%d",&n);
        }
        traverse=traverse->adr_urm;
    }
}
int afisare_medie(char num[20],char prenum[20])//FUNCTIE PENTRU AFISAREA MEDIE NOTELOR
{
    struct node *traverse;
    struct node *temp;
    temp=createNode();
    traverse=primul;
    int sum=0,i,nr=0;
    while(traverse!=NULL)
    {
        if((strcmp(traverse->nume,num)&&strcmp(traverse->prenume,prenum))==0)
        {
           for(i=0;i<10;i++)
           {
               if(traverse->note[i]!=0)
               {
                   sum=sum+traverse->note[i];
                   nr++;
               }
           }
        }
        traverse=traverse->adr_urm;
    }
    temp->media=sum/nr;
    printf("MEDIA NOTELOR STUDENTULUI ESTE: %d \n",temp->media);
    return temp->media;
}
void sterge_student()//FUNCTIE DE STERGERE A UNUI STUDENT
{
    char nume[20],prenume[20];
    printf("PRENUME:\n");
    scanf("%s",prenume);
    printf("NUME: \n");
    scanf("%s",nume);
    int i,n=cautare(prenume,nume);
    struct node *temp=primul,*prev;
    prev=createNode();
    if(n==0)
    {
        printf("\n EROARE, STERGEREA NU S-A PUTUT EFECTUA !!! \n");
    }
    if(n==1)
    {
        primul=temp->adr_urm;
        free(temp);
        printf("\n STERGEREA S-A EFECTUAT CU SUCCES ! \n");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(i==n)
            {
                if(temp->adr_urm==NULL)
                {
                    prev->adr_urm=NULL;
                    ultimul=prev;
                    free(temp);
                    printf("\n STERGEREA S-A EFECTUAT CU SUCCES ! \n");
                }
                else
                {
                    prev->adr_urm=temp->adr_urm;
                    free(temp);
                    printf("\n STERGEREA S-A EFECTUAT CU SUCCES!  \n");
                }
            }
            prev=temp;
            temp=temp->adr_urm;
        }
}
}
void inserare_in_fisier()//FUNCTIE PENTRU INSERAERA INTR-UN FISIER
{
    FILE *fp;
    fp=fopen("studenti.txt","w");
    int i,med;
    struct node *temp;
    temp=primul;
    while(temp!=NULL)
    {
        fprintf(fp,"Prenume: %s",temp->prenume);
        fprintf(fp," Nume: %s",temp->nume);
        fprintf(fp," Facultate: %s",temp->facultatea);
        fprintf(fp," Specializare: %s",temp->specializarea);
        fprintf(fp," Note: ");
        for(i=0;i<10;i++)
        {
            fprintf(fp," %d",temp->note[i]);
        }
        fprintf(fp," ");
        med=afisare_medie(temp->nume,temp->prenume);
        fprintf(fp,"Media studentului: %d ",med);
        fprintf(fp,"\n\n\n");
        temp=temp->adr_urm;
    }
    fclose(fp);
}
void inserare_alfabetic_in_fisier()//FUNCTIE PENTRU INSERAREA IN ORDINE ALFABETICA INTR-UN FISIER
{
    char temp_var[20];
    int temp_var2,med;
    int i,j,z,count=0;
    struct node *temp;
    temp=primul;
    struct studenti
    {
        char prenume[20],nume[20],facultatea[20],specializarea[20];
        int note[10],media;
    };
    while (temp!=NULL)
    {
        count++;
        temp=temp->adr_urm;
    }
    struct studenti stud[count];
    FILE *fs;
    fs=fopen("studenti_alfabetic.txt","w");
    temp=primul;
    for(i=0;i<count;i++)
    {
        if(temp!=NULL)
        {
            strcpy(stud[i].prenume,temp->prenume);
            strcpy(stud[i].nume,temp->nume);
            strcpy(stud[i].facultatea,temp->facultatea);
            strcpy(stud[i].specializarea,temp->specializarea);
            for(j=0;j<10;j++)
            {
                stud[i].note[j]=temp->note[j];
            }
        }
        temp=temp->adr_urm;
    }
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(strcmp(stud[j].nume,stud[j+1].nume)>0)
            {
                strcpy(temp_var,stud[j].nume);
                strcpy(stud[j].nume,stud[j+1].nume);
                strcpy(stud[j+1].nume,temp_var);
                strcpy(temp_var,stud[j].prenume);
                strcpy(stud[j].prenume,stud[j+1].prenume);
                strcpy(stud[j+1].prenume,temp_var);
                strcpy(temp_var,stud[j].facultatea);
                strcpy(stud[j].facultatea,stud[j+1].facultatea);
                strcpy(stud[j+1].facultatea,temp_var);
                strcpy(temp_var,stud[j].specializarea);
                strcpy(stud[j].specializarea,stud[j+1].specializarea);
                strcpy(stud[j+1].specializarea,temp_var);
                for(z=0;z<10;z++)
                {
                    temp_var2=stud[j].note[z];
                    stud[j].note[z]=stud[j+1].note[z];
                    stud[j+1].note[z]=temp_var2;
                }
            }
        }
    }
    for(i=0;i<count;i++)
    {
        fprintf(fs,"\n");
        fprintf(fs,"Nume: %s\n",stud[i].nume);
        fprintf(fs,"Prenume: %s\n",stud[i].prenume);
        fprintf(fs,"Facultatea: %s\n",stud[i].facultatea);
        fprintf(fs,"Specializarea: %s\n",stud[i].specializarea);
        for(j=0;j<10;j++)
        {
            fprintf(fs,"%d ",stud[i].note[j]);
        }
        fprintf(fs,"\n");
        med=afisare_medie(stud[i].nume,stud[i].prenume);
        fprintf(fs,"Media studentului: %d ",med);
    }
    fprintf(fs,"\n");
    fprintf(fs,"\n");
    fclose(fs);
}
void afisare_alfabetica()//FUNCTIE PT AFISAREA IN ORDINE ALFABETICA
{
    char temp_var[20];
    int temp_var2;
    int i,j,z,count=0;
    struct node *temp;
    temp=primul;
    struct studenti
    {
        char prenume[20],nume[20],facultatea[20],specializarea[20];
        int note[10],media;
    };
    while (temp!=NULL)
    {
        count++;
        temp=temp->adr_urm;
    }
    struct studenti stud[count];
    temp=primul;
    for(i=0;i<count;i++)
    {
        if(temp!=NULL)
        {
            strcpy(stud[i].prenume,temp->prenume);
            strcpy(stud[i].nume,temp->nume);
            strcpy(stud[i].facultatea,temp->facultatea);
            strcpy(stud[i].specializarea,temp->specializarea);
            for(j=0;j<10;j++)
            {
                stud[i].note[j]=temp->note[j];
            }
        }
        temp=temp->adr_urm;
    }
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(strcmp(stud[j].nume,stud[j+1].nume)>0)
            {
                strcpy(temp_var,stud[j].nume);
                strcpy(stud[j].nume,stud[j+1].nume);
                strcpy(stud[j+1].nume,temp_var);
                strcpy(temp_var,stud[j].prenume);
                strcpy(stud[j].prenume,stud[j+1].prenume);
                strcpy(stud[j+1].prenume,temp_var);
                strcpy(temp_var,stud[j].facultatea);
                strcpy(stud[j].facultatea,stud[j+1].facultatea);
                strcpy(stud[j+1].facultatea,temp_var);
                strcpy(temp_var,stud[j].specializarea);
                strcpy(stud[j].specializarea,stud[j+1].specializarea);
                strcpy(stud[j+1].specializarea,temp_var);
                for(z=0;z<10;z++)
                {
                    temp_var2=stud[j].note[z];
                    stud[j].note[z]=stud[j+1].note[z];
                    stud[j+1].note[z]=temp_var2;
                }
            }
        }
    }
    for(i=0;i<count;i++)
    {
        printf("\n");
        printf("Nume: %s\n",stud[i].nume);
        printf("Prenume: %s\n",stud[i].prenume);
        printf("Facultatea: %s\n",stud[i].facultatea);
        printf("Specializarea: %s\n",stud[i].specializarea);
        for(j=0;j<10;j++)
        {
            printf("%d ",stud[i].note[j]);
        }
    }
    printf("\n");
    printf("\n");
}
void afisare_nr_studenti()//FUNCTIE PENTRU CONTORIZAREA NUMARULUI DE STUDENTI
{
    struct node *temp;
    temp=primul;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->adr_urm;
    }
    printf("NUMARUL DE STUDENTI DIN LISTA ESTE : %d ",count);
    printf("\n\n");
}
