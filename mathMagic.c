#include <stdio.h>
#include <stdlib.h>
#define MAX 99
typedef enum { false, true } bool;


/**
 * inicijalizira matricu
 *
 * @param M matrica
 * @param N dimenzije matrice
 */
void inicijalizacija_matrice(int M[][MAX], int N){
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            M[i][j]=0;
}


/**
 * printa ispunjeu matricu na ekran
 *
 * @param M matrica
 * @param N dimenzije matrice
 */
void ispis(int M[][MAX], int N){
    int i, j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++)
            printf("%d \t", M[i][j]);
        printf("\n");
    }
}


/**
 * helperi za parne matrice nedjeljive s 4
 *
 * @param M   matrica
 * @param i   redak
 * @param j   stupac
 * @param br  trenutni broj
 *
 */
void doL(int M[][MAX], int i, int j, int br){
    M [i]   [j]   =br;
    M [i+1] [j-1] =br+1;
    M [i+1] [j]   =br+2;
    M [i]   [j-1] =br+3;
}
void doU(int M[][MAX], int i, int j, int br){
    M [i]   [j-1] =br;
    M [i+1] [j-1] =br+1;
    M [i+1] [j]   =br+2;
    M [i]   [j]   =br+3;
}
void doX(int M[][MAX], int i, int j, int br){
    M [i]   [j-1] =br;
    M [i+1] [j]   =br+1;
    M [i+1] [j-1] =br+2;
    M [i]   [j]   =br+3;
}


/**
 * broj polja je neparan
 *
 * @param M    matrica
 * @param size dimenzije matrice
 */
void magic_neparni(int M[][MAX], int size){
    int redak = 0, stupac = size/2, i, j;
    int redak_zadnji = redak, stupac_zadnji = stupac;
    int br = size*size;

    M[redak][stupac]=1;
    for (i=2; i<br+1; i++){
        if (redak-1<0)
            redak = size-1;
        else redak--;

        if (stupac+1 == size)
            stupac = 0;
        else stupac++;

        if (M[redak][stupac]==0)
            M[redak][stupac] = i;
        else{
            redak = redak_zadnji;
            stupac = stupac_zadnji;

            if (redak+1 == size)
                redak = 0;
            else redak++;
            M[redak][stupac]=i;
        }
        redak_zadnji = redak;
        stupac_zadnji = stupac;
    }
}


/**
 * broj polja je paran ali NIJE djeljiv sa 4
 *
 * @param M    matrica
 * @param size dimenzije matrice
 */
void magic_parni(int M[][MAX], int size){
    int returnM(int);
    int m =  (size-2)/4;
    int L = ((m+1)*2)-1;
    int U = ((m+1)*2)+1;
    int X = ((m-1)*2)-1;

    int redak = 0, stupac = (size/2), i, j;
    int redak_zadnji = redak, stupac_zadnji = stupac;
    int n = size*size;
    int br = 1;

    doL(M, redak, stupac, br);
    br+=4;

    while(br<n+1){
        if (redak-2<0)
            redak = size-2;
        else redak-=2;

        if (stupac+2 > size)
            stupac = 1;
        else stupac+=2;

        if (M[redak][stupac]==0){
            if (redak<=L){
                if(redak==m*2 && stupac==(m*2)+1)
                    doU(M, redak, stupac, br);
                else
                    doL(M,redak, stupac, br);
            }
            else if (redak>L && redak <=U){
                if(redak==(m+1)*2 && stupac==((m+1)*2)-1)
                    doL(M, redak, stupac, br);
                else
                    doU(M, redak, stupac, br);
            }
            else if(redak>U)
                doX(M, redak, stupac, br);

            br+=4;
        }
        else{
            redak=redak_zadnji;
            stupac=stupac_zadnji;

            if (redak+4==size)
                redak=0;
            else redak+=4;
            stupac-=2;

        }
        redak_zadnji = redak;
        stupac_zadnji = stupac;
    }
}


/**
 * broj polja je paran ALI I djeljiv sa 4
 *
 * @param M    matrica
 * @param size dimenzije matrice
 */
void magic_parni_dupli(int M[][MAX], int size){
    int size_na_kvadrat=(size*size) + 1;
    int i,j,br=1;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(((i%4==0)||(i%4==3)) && ((j%4==0)||(j%4==3))){
                M[i][j]=size_na_kvadrat-br;
                br++;
            }
            else if(((i%4==1)||(i%4==2)) && ((j%4==1)||(j%4==2))){
                M[i][j]=size_na_kvadrat-br;
                br++;
            }

            else {
                M[i][j]=br;
                br++;
            }
        }
    }
}

/**
 * naslovna funkcija
 */
void naslovna(){
    printf("**********************************************************************************\n");
    printf("** \t\t\tDOBRODOSLI U MAGICNI GENERATOR\n");
    printf("** -------------------------------------------------------------------------------\n");
    printf("** \tOvaj program je izraden kako bi ljudima omogucio \n");
    printf("** \tsto kvalitetnije ubijaju visak vremena.. odnosno da zabusavaju uceci \n");
    printf("** \tOvaj program se vodi pravilima izracunavanja magicnih\n");
    printf("** \tkvadrata te kako ne bi bilo zabune ovdje cemo ih izlistati\n");
    printf("** \n");
    printf("** \t1) kvadrat sve cetiri stranice ima jednake :p\n");
    printf("** \t2) na poseban nacin se racuna ako je broj celija u jednom retku neparan\n");
    printf("** \t3) na poseban nacin se racuna ako je taj broj paran i djeljiv sa 4\n");
    printf("** \t4) na poseban nacin se racuna ako je taj broj paran i NIJE djeljiv sa 4\n");
    printf("** \n");
    printf("** \tEvo sad nakon sto smo vam dali uvid u princip rada.. zabavite se\n");
    printf("**********************************************************************************\n");
}


/**
 * main funkcija
 *
 * @var matrix[MAX][MAX]  2d array koji se inicijalizira sa MAX vrijednoscu deklariranomna vrhu
 *                        dakle ostaje staticki, pokusao sam ne raditi dinamicke nizove jer iako
 *                        bi bilo brze, bilo bi sve puno pointera i memorijske alokacije,
 *                        a ne znam koliko si radila takve stvari
 *
 * @var size              prima jedan int i koristi ga da postavi dimenzije matrice
 * @var mod[20]           prima prirodni broj ili string 'ajd_ti' - ako primi broj konvertira ga
 *                        u tip int preko atoi() funkcije, ako primi string koristi
 * @var flag[1]           prima 1 znak i ako je taj znak 'n' prekida s izvrsavanjem programa
 *                        u suprotnom daje korisniku mogucnost da stvori jos jedan kvadrat
 * @var stop_sign         flag za provjeru korisnickog unosa (unutarnja do while petlja)
 */
int main(){

    int matrix[MAX][MAX];
    int size;
    char mod[20], flag[1];
    bool stop_sign = true;

    naslovna();

    do{
        printf("\n\n Upisite NORMALNI, prirodni, broj da bi odredili dimenzije matrice \n");
        printf(" ILI ");
        printf("\n Upisite 'ajdeti', ako zelite da to program napravi umjesto vas \t");
        scanf("%s", &mod);
        printf("\n");


        if (strcmp(mod, "ajdeti") == 0){
            size = rand() % 15 + 3;     //nasumicno izvlacenje dimenzija (ne prevelik interval) 
            printf("** Uzivajte u ovom prekrasnom kvadratu dimenzija %dx%d\n\n", size, size);
        }else{
            size = atoi(mod);
                if (size<3){
                    printf("Neema magicnog kvadrata ovih dimenzija.. molim unesite neki normalni broj iduci put!!\n");
                    exit(0);
                }
        }

        inicijalizacija_matrice(matrix, size);

        if (size%2!=0)
            magic_neparni(matrix, size);
        else if (size%2==0 && size %4!=0)
            magic_parni(matrix, size);
        else if (size%4==0 && size%2==0)
            magic_parni_dupli(matrix, size);

        ispis(matrix, size);

        do {
            printf("\n\n**********************************************************************************\n");
            printf("** UUU hocemo opet hocemo opet??? (y/n)\t");
            scanf("%s", &flag);
            printf("\n\n");
            if ((strcmp(flag, "n") == 0) || (strcmp(flag, "y") == 0)) stop_sign = false;
        }while(stop_sign);
    }while(strcmp(flag, "n") != 0);

    printf("\n\n**********************************************************************************\n");
    printf("** UZIVAJTEEE :D \n");
    printf("**********************************************************************************\n");

    return 0;
}
