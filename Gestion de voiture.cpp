#include <stdio.h>

#include <string.h>

struct utilisateur {
    char nom[20];
};

typedef struct Voiture {
    char marque[50];
    char modele[50];
    int matricule;
    char carburant[50];
    int places;
    char transmission[50];
    float prix;
    char Disponibilite[30];
} Voiture;

void saisirNomUtilisateur(struct utilisateur *Util) {
    printf("Entrez votre nom : ");
    scanf("%s", Util->nom);
}

void ajouter_voiture(Voiture *voitures, int *nbr) {
    Voiture nouvelle_voiture;

    printf("Entrez la marque de la voiture : ");
    scanf("%s", nouvelle_voiture.marque);

    printf("Entrez le modèle de la voiture : ");
    scanf("%s", nouvelle_voiture.modele);
  
    printf("Entrez le numéro d'immatriculation de la voiture : ");
    scanf("%d", &nouvelle_voiture.matricule);

    printf("Entrez le carburant de la voiture : ");
    scanf("%s", nouvelle_voiture.carburant);
  
    printf("Entrez le nombre de places de la voiture : ");
    scanf("%d", &nouvelle_voiture.places);
  
    printf("Entrez la transmission de la voiture : ");
    scanf("%s", nouvelle_voiture.transmission);
  
    printf("Entrez le prix de location de la voiture : ");
    scanf("%f", &nouvelle_voiture.prix);
  
    printf("Entrez la disponibilité de la voiture (Disponible/Non disponible) : ");
    scanf("%s", nouvelle_voiture.Disponibilite); 

    voitures[*nbr] = nouvelle_voiture;
    *nbr += 1;
}

void modifier_voiture(Voiture *voitures, int nbr) {
    int i;
    int matricule;
    printf("Entrez le numéro d'immatriculation de la voiture à modifier : ");
    scanf("%d", &matricule);

    for (i = 0; i < nbr; i++) {
        if (voitures[i].matricule == matricule) {
            break;
        }
    }
    if (i == nbr) {
        printf("Voiture non trouvée.\n");
        return;
    }
    printf("Entrez la nouvelle marque : ");
    scanf("%s", voitures[i].marque);

    printf("Entrez le nouveau modèle : ");
    scanf("%s", voitures[i].modele);
  
    printf("Entrez le nouveau numéro d'immatriculation de la voiture : ");
    scanf("%d", &voitures[i].matricule);
    
    printf("Entrez le nouveau carburant de la voiture : ");
    scanf("%s", voitures[i].carburant);
  
    printf("Entrez le nouveau nombre de places de la voiture : ");
    scanf("%d", &voitures[i].places);
  
    printf("Entrez la nouvelle transmission de la voiture : ");
    scanf("%s", voitures[i].transmission);
  
    printf("Entrez le nouveau prix de location de la voiture : ");
    scanf("%f", &voitures[i].prix);
  
    printf("Entrez la nouvelle disponibilité de la voiture (Disponible/Non disponible) : ");
    scanf("%s", voitures[i].Disponibilite); 

    printf("Voiture modifiée avec succès.\n");
}

void supprimer_voiture(Voiture *voitures, int *nbr) {
    int i, j;
    int matricule;

    printf("Entrez le matricule de la voiture à supprimer : ");
    scanf("%d", &matricule);

    for (i = 0; i < *nbr; i++) {
        if (voitures[i].matricule == matricule) {
            break;
        }
    }

    if (i == *nbr) {
        printf("Voiture non trouvée.\n");
        return;
    }

    for (j = i; j < *nbr - 1; j++) {
        voitures[j] = voitures[j + 1];
    }

    *nbr -= 1;

    printf("Voiture supprimée avec succès.\n");
}

void afficher_voitures_disponibles(Voiture *voitures, int nbr, struct utilisateur User) {
    int i;

    printf("\nListe des voitures disponibles à la location :\n\n");
    printf("ID | Marque | Nom d'utilisateur | Modèle | Type de carburant | places | Transmission | Prix | Disponibilité\n");

    for (i = 0; i < nbr; i++) {
        // Afficher les informations de la voiture
        printf("%d | %s | %s | %s | %s | %d | %s | %.2f | %s\n",
               i + 1, 
               voitures[i].marque, 
               User.nom, 
               voitures[i].modele, 
               voitures[i].carburant, 
               voitures[i].places, 
               voitures[i].transmission, 
               voitures[i].prix,
               voitures[i].Disponibilite);
    }
}

void enregistrer_voitures_csv(Voiture *voitures, int nbr) {
    FILE *fichier_csv;
    int i;

    fichier_csv = fopen("voitures.csv", "w");

    if (fichier_csv == NULL) {
        printf("Erreur lors de l'ouverture du fichier CSV.\n");
        return;
    }

    fprintf(fichier_csv, "Matricule, Marque,Modèle,Carburant,places,Transmission,Prix,Disponibilité\n");

    for (i = 0; i < nbr; i++) {
        fprintf(fichier_csv, "%d  %s %s %s %d %s %.2f %s\n",
                voitures[i].matricule,
                voitures[i].marque,
                voitures[i].modele,
                voitures[i].carburant,
                voitures[i].places,
                voitures[i].transmission,
                voitures[i].prix,
                voitures[i].Disponibilite);
    }

    fclose(fichier_csv);

    printf("Informations des voitures enregistrées avec succès dans le fichier voitures.csv.\n");
}

void rechercher_voiture(Voiture *voitures, int nbr, char *marque, char *disponibilite) {
    int i;
    int trouve = 0;

    printf("\nRésultat de la recherche :\n\n");

    for (i = 0; i < nbr; i++) {
        if (strcmp(voitures[i].marque, marque) == 0 && strcmp(voitures[i].Disponibilite, disponibilite) == 0) {
            trouve = 1;

            printf("ID |matricule| Marque | Modèle | Type de carburant | places | Transmission | Prix | Disponibilité\n");
            printf("%d |%d| %s | %s | %s | %d | %s | %.2f | %s\n",
                   i + 1,
                   voitures[i].matricule,
                   voitures[i].marque,
                   voitures[i].modele,
                   voitures[i].carburant,
                   voitures[i].places,
                   voitures[i].transmission,
                   voitures[i].prix,
                   voitures[i].Disponibilite);
        }
    }

    if (!trouve) {
        printf("Aucune voiture correspondante à votre recherche n'a été trouvée.\n");
    }
}



void trier_voitures_par_marque_prix(Voiture *voitures, int nbr) {
    int i, j;
    Voiture temp;

    for (i = 0; i < nbr - 1; i++) {
        for (j = i + 1; j < nbr; j++) {
         
            if (strcmp(voitures[i].marque, voitures[j].marque) > 0) {
            
                temp = voitures[i];
                voitures[i] = voitures[j];
                voitures[j] = temp;
            } else if (strcmp(voitures[i].marque, voitures[j].marque) == 0) {
             
                if (voitures[i].prix > voitures[j].prix) {
                   
                    temp = voitures[i];
                    voitures[i] = voitures[j];
                    voitures[j] = temp;
                }
            }
        }
    }
}

int main() {
    struct utilisateur User;
    Voiture voitures[100];
    int nbr = 0;
    int nombre_voitures;
    char marque[50];
    char disponibilite[30];
    int choix;

    saisirNomUtilisateur(&User);
    printf("Bienvenue, %s, dans l'application de gestion de location de voitures !\n", User.nom);

    do {
        // Affichage du menu
        printf("\nMenu :\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Modifier une voiture\n");
        printf("3. Supprimer une voiture\n");
        printf("4. Afficher les voitures disponibles\n");
        printf("5. Enregistrer les voitures dans un fichier CSV\n");
        printf("6. Rechercher une voiture\n");
        printf("7. Trier les voitures par marque puis par prix de location\n");
        printf("0. Quitter\n");

      
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Combien de voitures voulez-vous ajouter ? ");
                scanf("%d", &nombre_voitures);
                for (int i = 0; i < nombre_voitures; i++) {
                    ajouter_voiture(voitures, &nbr);
                }
                break;
            case 2:
                modifier_voiture(voitures, nbr);
                break;
            case 3:
                supprimer_voiture(voitures, &nbr);
                break;
            case 4:
                afficher_voitures_disponibles(voitures, nbr, User);
                break;
            case 5:
                enregistrer_voitures_csv(voitures, nbr);
                break;
            case 6:
                printf("Entrez la marque de la voiture à rechercher : ");
                scanf("%s", marque);
                printf("Entrez la disponibilité de la voiture à rechercher (Disponible/Non disponible) : ");
                scanf("%s", disponibilite);
                rechercher_voiture(voitures, nbr, marque, disponibilite);
                break;
            case 7:
                trier_voitures_par_marque_prix(voitures, nbr);
                printf("\nListe des voitures triées par marque puis par prix de location par jour :\n\n");
                afficher_voitures_disponibles(voitures, nbr, User);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}

