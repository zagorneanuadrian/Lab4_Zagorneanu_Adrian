#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

void meniu(){    
printf("\n==========Meniu==========\n");
 printf("1) Alocarea Dinamica\n");
 printf("2) Introducerea elementelor\n");
 printf("3) Completarea tabloului cu valori aleatorii\n");
 printf("4) Sortarea elementelor tabloului(coloane)\n");
 printf("5) Afisarea elementelor tabloului la ecran \n");
 printf("6) Eliberarea memoriei alocate pentru tablou \n");
 printf("0) Iesire din program\n");
 printf("\n==========Alegeti o optiune==========\n");
}
int main (){
int optiune = 0;
float optiunee = 0; 
int **a = NULL;
float mF = 0 , nF = 0; 
int i,j;
int valid = 0; 
int n,m;
 
srand(time(0));




do {
 meniu();
 
 valid = 0; 


while (!valid){
if (scanf("%f",&optiunee) == 1){
    optiune  = optiunee ;
valid = 1;
}
else{
 system("cls");
 printf("\nOptiune invalida. Incercati din nou.");

 
 meniu();

 while ( getchar() != '\n'); 

} 
} 

  system("cls"); 


switch (optiune)
{
case 1:
if(a != NULL){
    for (i=0; i<n; i++) free(a[i]);
    free(a);
    a = NULL;
}



printf("\nIntrodu numarul de randuri si coloane: \n");
scanf("%f%f",&nF,&mF);
 n = (int)nF;
m = (int)mF;
               if (n <= 0) {
                 printf("Dimensiuni invalide!\n");
                n = m = 0;
                }
                else if (m <= 0) {
                 printf("Dimensiuni invalide!\n");
                 n = m = 0;
                }





             a = (int**)malloc(n * sizeof(int*));
                for (i = 0; i < n; i++)
                    a[i] = (int*)malloc(m * sizeof(int));

                printf("ati alocat memorie pentru matricea cu marimea  %d x %d .\n", n, m);
            
break;
    case 2:
                 if (a == NULL) {
                    printf("Nu ati alocat mmorie matricei folositit optiiunea 1.\n");
                    break;
                }

                printf("Introdu elementele matricei\n");
                for (i = 0; i < n; i++)
                    for (j = 0; j < m; j++)
                        scanf("%d", &a[i][j]);

                printf("Ati completat matricea \n");
                break;

    case 3:
    
                if (a == NULL) {
                    printf("Nu ati alocat mmorie matricei folositit optiiunea 1.\n");
                    break;
                }

                printf("Matricea va avea valori aleatori\n");

                for (i = 0; i < n; i++)
                    for (j = 0; j < m; j++)
                        a[i][j] = rand() % 10;  

                printf("Matricea a fost completata cu numere aleatori .\n");
                
        break;
    case 4:
     if (a == NULL) {
        printf("Nu exista matrice alocata!\n");
        break;
    }

    printf("Sortarea coloanelor in o rdine DESCRESCATOARE (metoda selectiei)...\n");

    // Sortam fiecare coloana separat
    for (j = 0; j < m; j++) {          
        for (i = 0; i < n - 1; i++) { 
            int poz_max = i;

            for (int k = i + 1; k < n; k++) {
                if (a[k][j] > a[poz_max][j])
                    poz_max = k;
            }

            if (poz_max != i) {
                int temp = a[i][j];
                a[i][j] = a[poz_max][j];
                a[poz_max][j] = temp;
            }
        }
    }

    printf("Coloanele au fost sortate descrescator.\n");

        break;
    case 5:
      
                if (a == NULL) {
                    printf("Nu exista matrice alocata.\n");
                    break;
                }

                printf("Matricea este:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++)
                        printf(" %d ", a[i][j]);
                    printf("\n");}
break;
 case 6:
   if (a == NULL) {
                    printf("Nu exista memorie de eliberat.\n");
                    break;
                }

                for (i = 0; i < n; i++)
                    free(a[i]);
                free(a);

                a = NULL;
                n = m = 0;

                printf("Memoria a fost eliberata.\n");
break;
      case 0:
                printf("Iesire...\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }
        if (optiune != 0) {
            printf("\nApasa o tasta pentru a reveni la meniu...");
           getch();
            system("cls");
}
} while (optiune != 0);

    return 0;

}