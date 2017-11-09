#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAILLEMOT 10
#define TAILLEMINI 3

int main(){

    int i=0;
    int compteur=0;
    int compteurdefaite=0;
    char MotADeviner[TAILLEMOT];
    char MotFin[TAILLEMOT];
    char Lettre=0;
    int vie=0;


    // Fonction d'initialisation du mot à deviner
    do{
        memset (MotADeviner, 0, sizeof (MotADeviner));
        printf("ENTREZ LE MOT A DEVINER (3-10 LETTRES):\n");
        scanf("%s",MotADeviner);
    }while(strlen(MotADeviner)>TAILLEMOT || strlen(MotADeviner)<TAILLEMINI);

    //initialisation en minuscule pour éviter la casse
    for(i=0; MotADeviner[i]; i++){
        MotADeviner[i] = tolower(MotADeviner[i]);
    }


    //Switch pour set la vie en fonction de la taille du mot
    switch (strlen(MotADeviner)){
        case 3 : vie=3; break;
        case 4 : vie=4; break;
        case 5 : vie=4; break;
        case 6 : vie=5; break;
        case 7 : vie=5; break;
        case 8 : vie=6; break;
        case 9 : vie=6; break;
        case 10 : vie=7; break;
        }


    // Initialisation du mot de fin
    for (i=0;i<strlen(MotADeviner);i++){
            MotFin[i]='_';
    }


    fflush(stdin);
    printf("LE MOT A DEVINER EST : %s\n",MotADeviner);
    system("pause");
    system("cls");


    //Boucle de jeu principal
    do{
        compteurdefaite=0;  //réinitialisation de mes compteur à chaque bouclage
        compteur=0;

        printf("ENTREZ UNE LETTRE - IL VOUS RESTE %d VIE :\n",vie);
        scanf("%c",&Lettre);
        Lettre = tolower(Lettre);


        //Verification de l'input
        for (i=0;i<=strlen(MotADeviner);i++){
            if (Lettre==MotADeviner[i]){
                MotFin[i]=Lettre;
            }else if (MotFin[i]=='_'){
                MotFin[i]='_';
            }
        }


        //Calcul de perte de vie
        for (i=0;i<=strlen(MotADeviner);i++){
            if (Lettre!=MotADeviner[i]){
                compteurdefaite=compteurdefaite+1;
            }
            if (compteurdefaite==strlen(MotADeviner)+1){
                vie=vie-1;
            }
        }


        //Affichage a l'utilisateur de sa chaine
        for (i=0;i<strlen(MotADeviner);i++){
            putchar(MotFin[i]);
        }
        fflush(stdin);
        putchar('\n');


        //Verification de réussite
        for (i=0;i<strlen(MotADeviner);i++){
            if (MotADeviner[i]==MotFin[i]){
                compteur=compteur+1;
            }
        }
    }while(compteur!=strlen(MotADeviner) &&  vie!=0); //Condition de sortie de la boucle

    if (compteur==strlen(MotADeviner)){
        printf("VOUS AVEZ GAGNE :D");
    }
    else{
        printf("PAS DE CHANCE, C'EST PERDU :/");
    }
    return 0;
}

/*
BUT : Créer un jeu de pendu
ENTREE : Le mot à deviner et les lettres
SORTIE : Victoire/Defaite le mot recherché

VAR
    i,compteur,compteurdefaite,conditionsortie,vie:ENTIER;
    MotADeviner,MotFin:CHAINE;
    Lettre:CARACTERE;
DEBUT
    REPETER
        ECRIRE('ENTREZ LE MOT A DEVINER (3-10 LETTRE)')
        LIRE(MotADeviner)
    JUSQU'A (LongueurChaine(MotADeviner)>TAILLEMOT) OU strlen(MotADeviner)<TAILLEMINI)

    CAS LongueurChaine(MotADeviner)PARMIS :
        3 : vie<-3
        4 : vie<-4
        5 : vie<-4
        6 : vie<-5
        7 : vie<-5
        8 : vie<-6
        9 : vie<-6
        10 : vie<-7

    POUR i<-1 à LongueurChaine(MotADeviner) DE PAS DE 1 FAIRE
            MOTFIN[i]<-'_'
    FINPOUR

    ECRIRE(''LE MOT A DEVINER EST :'&MotADeviner);

    REPETER
        compteurdefaite<-0
        compteur<-0
        ECRIRE(''ENTREZ UNE LETTRE - IL VOUS RESTE',&Vie,'VIE')
        LIRE(Lettre)
        POUR i<-1 à LongueurChaine(MotADeviner) DE PAS DE 1 FAIRE
                SI Lettre=MotADeviner[i]
                    MotFin[i]<-Lettre
                SINON SI MotFin[i]='_'
                    MotFin[i]<-'_'
                FINSI
        FINPOUR
        POUR i<-1 à LongueurChaine(MotADeviner) DE PAS DE 1 FAIRE
                SI Lettre<>MotADeviner[i]
                    compteurdefaite<-compteurdefaite+1
                FINSI
                SI compteurdefaite=LongueurChaine(MotADeviner)
                    vie<-vie-1
                FINSI
        FINPOUR
        ECRIRE(MotFin)
        POUR i<-1 à LongueurChaine(MotADeviner) DE PAS DE 1 FAIRE
            SI MotADeviner[i]=MotFin[i]
                compteur<-compteur+
            FINSI
        FINPOUR

    JUSQU'A (compteur<>strlen(MotADeviner) AND  vie<>0)
    SI compteur=LongueurChaine(MotADeviner)
        ECRIRE('VOUS AVEZ GAGNE')
    SINON ECRIRE('PAS DE CHANCE C'EST PERDU')
    FINSI
FIN */
