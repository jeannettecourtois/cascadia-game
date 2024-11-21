import psycopg2
from password import * 

def test (sql):
    print ('-'*10)
    conn = psycopg2.connect("host=%s dbname=%s user=%s password=%s" % (HOST, DATABASE, USER, PASSWORD))
    # Open a cursor to send SQL commands
    cur = conn.cursor()
    
    # sql = "SELECT name, century FROM v_philosopher"
    cur.execute(sql)
    raw = cur.fetchone()
    while raw:
        print (raw)
        raw = cur.fetchone()
 
 
def executeSqlSelect(sql,nomChamp=[]):
    "affiche les résultats d'une requète select"
    # Connexion à la base de données PostgreSQL
    conn = psycopg2.connect("host=%s dbname=%s user=%s password=%s" % (HOST, DATABASE, USER, PASSWORD))
    # print (conn)

    cursor = conn.cursor()
    cursor.execute(sql)
    rows = cursor.fetchall()

    if (not nomChamp):
        for row in rows:
            for i, champ  in enumerate(row) :
                print(i,champ)
            print("-"*20)
            
    else : 
        for row in rows:
            for i,champ  in enumerate(row) :
                print(f"{nomChamp[i]} :\t{champ}")
            print("-"*20)

    conn.close()
    

def afficheEmpruntParRessource():
    sql = """
        SELECT E.CodeRessource, R.titre, count(E.CodeRessource) FROM Pret as P
        JOIN vAdherent as A ON P.id_adh = A.id
        JOIN Exemplaire as E ON P.id_exp = E.id
        JOIN Ressources as R ON E.CodeRessource = R.CodeRessource
        GROUP BY (E.CodeRessource, R.titre);
        """
    
    executeSqlSelect(sql,["CodeRessource","titre","nb d'emprunts"])

def compteExemplaires():
    sql= """
    SELECT E.CodeRessource, titre ,count(*)
            FROM Exemplaire as E JOIN Ressources  as R ON E.CodeRessource=R.CodeRessource
                            LEFT JOIN Film as F ON  R.CodeRessource =F.CodeRessource
                            LEFT JOIN Musique M ON R.CodeRessource =M.CodeRessource
                            LEFT JOIN Livre L ON R.CodeRessource =L.CodeRessource
                            
                            GROUP BY (E.CodeRessource, titre );
    
    """
    
    executeSqlSelect(sql,["idRessource","titre","Nombre d'exemplaires"])


def afficheGenreFilms():
    sql="""SELECT nomGenre ,count(nomGenre) 
                FROM vFilm
                GROUP BY nomGenre"""
    executeSqlSelect(sql,["genre","nombre de films"])   

def afficheEmpruntParAdherent():
    sql="""
    SELECT   P.id_Adh, A.nom,A.prenom,count(P.id_exp) FROM Pret as P
        JOIN vAdherent as A ON P.id_adh = A.id
        JOIN Exemplaire as E ON P.id_exp = E.id
        JOIN Ressources as R ON E.CodeRessource = R.CodeRessource
        GROUP BY (P.id_Adh, A.nom,A.prenom);

    """
    executeSqlSelect(sql,["idAdh","nom\t","prénom\t","nb exemplaires empruntés"])   

def compteBlackliste():
    sql= """
    SELECT Blackliste ,COUNT(Blackliste) 
                FROM Adherent
                 GROUP BY (Blackliste)                 
                
    
    """
    
    executeSqlSelect(sql,["bLACKLISTÉ","Nombre "])

def afficheGenrePopulaire() :
        sql="""
        SELECT G.nom AS Genre, COUNT(Pr.id_exp) AS Nombre_Pretes
            FROM Genre G
            JOIN Ressources R ON G.nom = R.nomGenre
            JOIN Exemplaire E ON R.CodeRessource = E.CodeRessource
            JOIN Pret Pr ON E.id = Pr.id_exp
            GROUP BY G.nom
            ORDER BY Nombre_Pretes DESC;
        """
        executeSqlSelect(sql,["genre","nb emprunts"])

def afficheMenu():
    print("\n"*50)
    print("1.affiche personnes")
    print("2.affiche films")
    print("3.compteExemplaires")
    print("4.affiche films par genre")
    print("5.affiche Emprunt Par Adherent")
    print("6.affiche Emprunt Par Ressource")
    print("7.compte Blacklisté")
    print("0.quitter")
    choix = int( input("choix ?"))
    return choix

if __name__ == "__main__" :
    
    choix=-1
    fin=False
    #  while (choix != 0):
    while (not fin):
        choix = afficheMenu() 
        while (( choix<0 or choix>7)and not fin):
            choix = afficheMenu() 
            
            
        match choix :
            
            case 1 :  
                executeSqlSelect("SELECT * FROM vPersonne") 
            case 2:
                executeSqlSelect("SELECT titre,nomGenre, synopsis FROM vFilm",["titre film","genre\t","synopsis"])   
            case 3:
                compteExemplaires()
            case 4:
                afficheGenreFilms()
            case 5:
                afficheEmpruntParAdherent()
            case 6:
                afficheEmpruntParRessource()
            case 7:
                compteBlackliste()
            case 8:    
                afficheGenrePopulaire() 
            
            case 0:
                fin=True  
            
        choix=-1
        if (not fin):
            input("tapez entree")
    
    """ 
    requetes à tester
    
    -- Nombre de ressources par genre
SELECT G.nom AS Genre, COUNT(R.CodeRessource) AS Nombre_Ressources
FROM Genre G
LEFT JOIN Ressources R ON G.nom = R.nomGenre
GROUP BY G.nom
ORDER BY Nombre_Ressources DESC;
-- Nombre de contributeurs par nationalité
SELECT C.nationalite AS Nationalité, COUNT(C.id) AS Nombre_Contributeurs
FROM Contributeur C
GROUP BY C.nationalite
ORDER BY Nombre_Contributeurs DESC;
-- Nombre d'exemplaires par état
SELECT E.etat AS Etat, COUNT(E.id) AS Nombre_Exemplaires
FROM Exemplaire E
GROUP BY E.etat
ORDER BY Nombre_Exemplaires DESC;
-- Nombre d'adhérents blacklistés par ville
SELECT V.nom AS Ville, COUNT(A.id) AS Nombre_Adherents_Blacklistes
FROM Ville V
JOIN Adresse Adr ON V.codePostal = Adr.codePostal
JOIN Personne P ON Adr.numero = P.numero AND Adr.rue = P.rue AND Adr.codePostal =
P.codePostal
JOIN Adherent A ON P.id = A.id
WHERE A.Blackliste = TRUE
GROUP BY V.nom
ORDER BY Nombre_Adherents_Blacklistes DESC;
-- Durée moyenne des prêts par adhérent
  ERREUR faire differene dates
            SELECT A.id AS ID_Adherent, P.nom, P.prenom, AVG(Pr.duree) AS Duree_Moyenne
            FROM Adherent A
            JOIN Personne P ON A.id = P.id
            JOIN Pret Pr ON A.id = Pr.id_adh
            GROUP BY A.id, P.nom, P.prenom
            ORDER BY Duree_Moyenne DESC;
-- Nombre de prêts par ressource
SELECT R.titre AS Titre_Ressource, COUNT(Pr.id_exp) AS Nombre_Pretes
FROM Ressources R
JOIN Exemplaire E ON R.CodeRessource = E.CodeRessource
JOIN Pret Pr ON E.id = Pr.id_exp
GROUP BY R.titre
ORDER BY Nombre_Pretes DESC;
-- Adhérents avec le plus de sanctions
SELECT A.id AS ID_Adherent, P.nom, P.prenom, COUNT(S.date) AS Nombre_Sanctions
FROM Adherent A
JOIN Personne P ON A.id = P.id
JOIN Sanction S ON A.id = S.id
GROUP BY A.id, P.nom, P.prenom
ORDER BY Nombre_Sanctions DESC;
-- Ressources disponibles par éditeur
SELECT E.nom AS Editeur, COUNT(R.CodeRessource) AS Nombre_Ressources
FROM editeur E
LEFT JOIN Ressources R ON E.nom = R.nomEditeur
GROUP BY E.nom
ORDER BY Nombre_Ressources DESC;
-- Nombre d'adhésions par année
SELECT YEAR(Ah.debut) AS Annee, COUNT(Ah.NoCarteAdherent) AS
Nombre_Adhesions
FROM Adhesion Ah
GROUP BY YEAR(Ah.debut)
ORDER BY Annee ASC;
-- Genres les plus populaires empruntés
SELECT G.nom AS Genre, COUNT(Pr.id_exp) AS Nombre_Pretes
FROM Genre G
JOIN Ressources R ON G.nom = R.nomGenre
JOIN Exemplaire E ON R.CodeRessource = E.CodeRessource
JOIN Pret Pr ON E.id = Pr.id_exp
GROUP BY G.nom
ORDER BY Nombre_Pretes DESC;

    
    """
    