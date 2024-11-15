# MLD  


## choix :


#### choix de l'héritage :




Contributeur et Utilisateur (classe mère=Personne): Héritage par référence
Explication: c’est un héritage non complet parce que les classes filles contiennent des attributs et la classe mère (Personne) est abstraite mais elle est en association externe avec Adresse, ce qui justifie l’héritage par référence.


Personnel et Adherent (classe mère=Utilisateur): Héritage par référence
Explication:C’est un héritage non complet avec la classe mère (Utilisateur) qui hérite de Personne et donc de l’association avec Adresse, donc pour la même raison nous choisissons un héritage par référence.


Livre, Musique, Film (classe mère = Ressources): Héritage par référence
Explication:C’est un héritage non complet avec la classe mère (Ressources) est en association externe avec d’autres tables (par exemple Genre).


#### choix des clés primaires (PK):


pour 
- Personne : il faut une clé artificielle = id  car homonymes possibles, et créer une clé avec nom + adresse ne convient pas (l'adresse peut changer)
- Contributeur, Utilisateur, Adhérent : héritent de cette clé qui va identiifer de manière unique le contibuteur ou utilisateur ou adhérent -> id = PK
- Ville : CodePostal car est unique, identifie chaque ville
- Adresse : PK= rue+numéro+CP (car rue + no ne suffit pas, nom de rue commun à de nombreuses villes)
- Genre et Editeur : PK= nom suffit, pas de doublons 
- Ressource : le CodeRessource est unique (cf cahier des charges)
- livre, Musique et film : héritent de ce CodeRessource  ->PK
- Exemplaire : une ressource peut être présent en plusieurs exemplaires donc le CodeRessource ne peut pas être utilisé comme PK : on crée une clé artificielle id
- Pret : possède 2 clés étrangères (Adherent.id et Exemplaire.id) mais cela ne suffit pas pour la PK de Pret car un adhérent doit pouvoir enprunter le mêe exemplaire à 2 dates différentes. On ajoute debut pour former la PK (debut,Adherent.id, Exemplaire.id)
- Contribue : on choisit (role, Ressources.CodeRessource, Contributeur.id) On aurait pu choisir uniquement contributeur et codeRessource mais un contributeur peut avoir plusieurs rôle pour une même ressource (ex: scénariste et réalisateur d'un film)
- Adhesion PK=(Adherent.id,NoCarteAdherent) car un adhérent peut adhérer plusieurs fois à différentes périodes (il aura un nouveau numéro de carte)
- Sanction PK= (date , Adherent.id ) un adhérent peut avoir plusieurs sanctions à des dates différentes




## MLD :




```sql
- Ville(#codePostal:CHAR(10), nom:VARCHAR, pays:VARCHAR) 
avec nom NOT NULL et pays NOT NULL


- Adresse(#numero:CHAR,#rue:VARCHAR, #codePostal=>Ville) 
Contrainte: Adresse.codePostal NOT NULL


- Genre(#nom:VARCHAR);
- editeur(#nom:VARCHAR);




- Ressources(#CodeRessource:INT, titre:VARCHAR, dateApparition:DATE, codeClassification:INT, nomGenre=>Genre, nomEditeur=>editeur); 
Contrainte: Ressources.nomGenre NOT NULL et Ressources.nomEditeur NOT NULL
PROJECTION(Ressources,CodeRessource)= PROJECTION(Livre,CodeRessource) UNION PROJECTION(Musique,CodeRessource) UNION PROJECTION(Film,CodeRessource) 


- Livre(#CodeRessource:INT=>Ressources, ISBN:CHAR(20), resume;VARCHAR, langue:CHAR(30) ) 
avec ISBN KEY ;


- Musique(#CodeRessource:INT=>Ressources, duree:CHAR(8) )


- Film(#CodeRessource:INT=>Ressources, synopsis:VARCHAR, duree:CHAR(8), langue:CHAR(30) );


-vLivre=jointure(Ressources, Livre, Ressources.CodeRessource=Livre.CodeRessource)
-vFilm=jointure(Ressources, Film, Ressources.CodeRessource=Film.CodeRessource)
-vMusique=jointure(Ressources, Musique, Ressources.CodeRessource=Musique.CodeRessource)


Contraintes: INTERSECTION(PROJECTION(Livre,CodeRessource),PROJECTION(Musique, CodeRessource)={},
INTERSECTION((PROJECTION(Film,CodeRessource),PROJECTION(Livre,CodeRessource))={}
INTERSECTION((PROJECTION(Film,CodeRessource),PROJECTION(Musique,CodeRessource))={}


- Personne(#id:INT, nom:VARCHAR, prenom:VARCHAR, dateDeNaissance:DATE, email:VARCHAR, telephone:CHAR(20), numero=>Adresse,rue=>Adresse, codePostal=>Adresse ) 
avec nom NOT NULL, prenom NOT NULL
contraintes:INTERSECTION(PROJECTION(Contributeur,id),PROJECTION(Utilisateur,id))={} et
PROJECTION(Personne,id) = PROJECTION(Contributeur,id) UNION PROJECTION(Utilisateur,id) et
et Personne.numero NOT NULL  Personne.rue NOT NULL  Personne.codePostal NOT NULL


- Contributeur(#id=>Personne, nationalite:CHAR(50)) 
Contrainte: INTERSECTION (PROJECTION(Contributeur,id),PROJECTION(Utilisateur,id))={}




- Utilisateur(#id=>Personne, login:VARCHAR, password:VARCHAR) avec login NOT NULL et password NOT NULL
Contrainte: PROJECTION(Utilisateur,id) = PROJECTION(Personnel,id) UNION PROJECTION(Adherent,id)


-vUtilisateur=jointure(Personne,Utilisateur, Personne.id=Utilisateur.id)
-vContributeur=jointure(Personne,Contributeur,Personne.id=Contributeur.id)




- Personnel(#id=>Utilisateur);


- Adherent(#id=>Utilisateur, Blackliste:BOOL)
Contrainte:  INTERSECTION (PROJECTION(Adherent,id),PROJECTION(Personnel,id))={}


-vPersonnel=jointure(Utilisateur,Personnel,Utilisateur.id=Personnel.id)
-vAdherant=jointure(Utilisateur,Adherant,Utilisateur.id=Adherant.id)




- Exemplaire(#id, etat:VARCHAR, CodeRessource=>Ressources) avec etat NOT NULL
Contrainte: Exemplaire.CodeRessource NOT NULL






- Pret(#debut:DATE, duree:INT, dateRendu:DATE, #id_exp=>Exemplaire, #id_adh=>Adherent) avec:  duree NOT NULL 
Contrainte:  dateRendu >= debut ;






- Contribue(#role:VARCHAR, #CodeRessource=>Ressources, #id=>Contributeur) 




- Adhesion(#NoCarteAdherent:INT, debut:DATE, fin:DATE, #idAdherent=>Adherent) avec debut NOT NULL 
Contraintes: Adhesion.idAdherent NOT NULL et fin>debut ;


- Sanction(#date:DATE, duree:INT, motif:CHAR, #id=>Adherent) avec date NOT NULL et duree NOT NULL
­
```






## autres contraintes


- le personnel (seulement) peut modifier la base de données 
- l'utilisateur doit s'autentifier pour emprunter (il ne doit pas être suspendu / blacklisté)
- le nombre d'emprunt simultanné est limité
- le document emprunté doit être en bon état (au moins=bon état ou neuf) (et disponible!)
- la durée d'emprunt est limité