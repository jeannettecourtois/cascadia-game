SELECT * FROM Ville;
SELECT * FROM adresse;


-- SELECT * FROM vPersonne;
-- SELECT * FROM Contributeur;

 
SELECT * FROM vContributeur;
SELECT * FROM vUtilisateur;
SELECT * FROM vPersonnel;
SELECT * FROM vAdherent;

-- SELECT * FROM Ressources;

SELECT * FROM vFilm;

-- -------- affiche tous les exemplaires 

SELECT E.CodeRessource, id as idExemplaire,etat, titre ,dateApparition
            FROM Exemplaire as E JOIN Ressources  as R ON E.CodeRessource=R.CodeRessource
                            LEFT JOIN Film as F ON  R.CodeRessource =F.CodeRessource
                            LEFT JOIN Musique M ON R.CodeRessource =M.CodeRessource
                            LEFT JOIN Livre L ON R.CodeRessource =L.CodeRessource;

SELECT debut , duree, daterendu , etat ,nom , prenom ,numero ,rue,codepostal, ville 
        FROM Pret as P 
        JOIN Exemplaire as E ON P.id_exp = E.id
        JOIN vAdherent as A ON P.id_adh = A.id;   


-- -------- affiche les films et contributeurs

SELECT vC.nom,Vc.prenom, C.role ,F.titre
                FROM vFilm as F 
                JOIN Contribue as C ON F.CodeRessource = C.CodeRessource 
                JOIN vContributeur as vC ON C.id = vC.id;                         

SELECT A.NoCarteAdherent,A.debut,A.fin,P.nom,P.prenom,P.Blackliste FROM adhesion as A 
         JOIN vAdherent as P ON A.idAdherent = P.id;


-- -------- affiche les prets

SELECT R.titre, P.debut, P.duree, P.daterendu, P.id_exp, P.id_adh, A.blackliste, A.nom,A.prenom FROM Pret as P
        JOIN vAdherent as A ON P.id_adh = A.id
        JOIN Exemplaire as E ON P.id_exp = E.id
        JOIN Ressources as R ON E.CodeRessource = R.CodeRessource;



SELECT E.CodeRessource, id as idExemplaire,etat, titre ,dateApparition
            FROM Exemplaire as E JOIN Ressources  as R ON E.CodeRessource=R.CodeRessource
                            LEFT JOIN Film as F ON  R.CodeRessource =F.CodeRessource
                            LEFT JOIN Musique M ON R.CodeRessource =M.CodeRessource
                            LEFT JOIN Livre L ON R.CodeRessource =L.CodeRessource;
