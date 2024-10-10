Note De Clarification (NDC) :Bibliothèque      Groupe: Yvont , Jeannette et Jilani 

1)Les Objets avec leur propriétés:

Table Ressources
Attributs: 
Code Ressource: (Entier); Titre: (Entier); date: (type Date); Éditeur , Genre(Chaîne de caractère) ; Code_class :(Entier)
-> Un contributeur peut être lié à plusieurs ressources .
-> Une ressource peut avoir plusieurs exemplaires.

Table Films (Sous classe de Ressources)
Attributs: 
Langue: (Chaine de caractère); Longueur: ‘entier); Synopsis: (Chaine de caractère)
Table Livres (Sous classe de Ressources)
Attributs: 
ISBN:Chaine de caractère; Résumé: (texte); Langue: (Chaine de caractère)
Tables Oeuvres (Sous classe de Ressources)
Attributs: 
Longueur: (entier); Langue: (Chaine de caractère)
Table Exemplaires 
Attributs: 
Etat: (Chaine de caractère)
->Association avec “Ressources".
->Un exemplaire peut être prêté plusieurs fois.
Table Contributeurs
Attributs: 
Nom,Prénom:(Chaine de caractère) ; Date_naissance: (type date) nationalité: Chaine de caractère
-> possède différents rôles.
Classe d’association : Contribuer : 
	 	Attributs: Role:(Chaine de caractère)
Table Personnel
Attributs:
Login:Chaine de caractère; Nom:,Prénom: Chaine de caractère; Adresse: (texte); Email:( Chaîne de caractère)
-> peut gérer plusieurs ressources .
Table “Adhérent”
Attributs: Login_Adh: ,Mot_de_Passe,Nom: VARCHAR,Prénom: (Chaine de caractère) Date: DATE; Adresse_email:Chaine de caractère; Tel:entier
-> Un adhérent peut avoir plusieurs prêts.
->Un adhérent peut recevoir plusieurs sanctions.
Table Prêts
Attributs: 
date_prêt: DATE; Durée_Prêt: (entier)	
->Un prêt est effectué par un adhérent.
Table Sanctions:
Attributs: Type_Sanctions: Chaine de caractère; Durée: entie ; Date:type date
	->Chaque sanction est appliquée à un adhérent spécifique.



2) Rôles:
	-Ressources :gère les ressources de la bibliothèque de différents types.
	-Exemplaire: gère les exemplaires physiques des ressources.
	-Contributeur: stocke les informations sur les personnes qui ont contribué à la création des ressources.
	-Contribuer:  fait le lien entre les ressources et leurs contributeurs(classe d’association).
	-Personnel:  gère les comptes des membres du personnel de la bibliothèque.
	-Prêt: enregistre chaque opération de prêt effectuée par un adhérent et conserve les informations.
	-Sanctions: gère les sanctions  aux adhérents.
	-Adhérant:  contient les informations sur les adhérents.

	


3)Contraintes: 
La durée de prêt est limitée à certains nombres de joueurs. 
Un adhérent ne peut emprunter qu’un nombre limité d’exemplaires. 
Un rôle est spécifié pour chaque contribution d’un contributeur à une ressource. 
 Un prêt ne peut être effectué que si l'exemplaire est en bon état et disponible.
En cas de retard, une suspension proportionnelle au nombre de jours de retard s'applique.
Un adhérent  peut être blacklisté en cas de sanctions répétées.
