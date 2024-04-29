1. Définition de la structure   
   `utilisateur` et de la structure `Voiture`:
   - La structure `utilisateur` est utilisée pour stocker le nom de l'utilisateur.
   - La structure `Voiture` est utilisée pour stocker les informations sur chaque voiture, telles que la marque, le modèle, le numéro d'immatriculation, le carburant, etc.

2. Fonctions de gestion des voitures :
   - `saisirNomUtilisateur(struct utilisateur *Util)` : Demande à l'utilisateur de saisir son nom.
   - `ajouter_voiture(Voiture *voitures, int *nbr)` : Permet d'ajouter une nouvelle voiture à la liste des voitures disponibles.
   - `modifier_voiture(Voiture *voitures, int nbr)` : Permet de modifier les informations d'une voiture existante.
   - `supprimer_voiture(Voiture *voitures, int *nbr)` : Permet de supprimer une voiture de la liste des voitures disponibles.
   - `afficher_voitures_disponibles(Voiture *voitures, int nbr, struct utilisateur User)` : Affiche la liste des voitures disponibles.
   - `enregistrer_voitures_csv(Voiture *voitures, int nbr)` : Enregistre les informations des voitures dans un fichier CSV.
   - `rechercher_voiture(Voiture *voitures, int nbr, char *marque, char *disponibilite)` : Permet de rechercher une voiture par marque et disponibilité.
   - `trier_voitures_par_marque_prix(Voiture *voitures, int nbr)` : Trie les voitures par marque, puis par prix de location.

3. Fonction `main()` :
   - Demande à l'utilisateur de saisir son nom.
   - Affiche un menu d'options permettant à l'utilisateur d'ajouter, modifier, supprimer, afficher, enregistrer, rechercher ou trier des voitures.
   - Selon le choix de l'utilisateur, les fonctions appropriées sont appelées pour effectuer les actions correspondantes sur les voitures.
   - Le programme continue de s'exécuter jusqu'à ce que l'utilisateur choisisse l'option pour quitter.

