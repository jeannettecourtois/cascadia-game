DROP VIEW IF EXISTS vfilm, vlivre , vmusique,vpersonnel,vutilisateur, vadherent, vcontributeur;
DROP TABLE IF EXISTS editeur, exemplaire, film , genre  , livre ,  musique ,  ressources ,  adhesion, adherent, contribue, contributeur, personnel, utilisateur, personne, pret, sanction, adresse, ville  CASCADE;



CREATE TABLE Ville(
    codePostal CHAR(10) PRIMARY KEY, 
    nom VARCHAR NOT NULL,
    pays VARCHAR NOT NULL
);

CREATE TABLE Adresse(
    numero CHAR(5),
    rue VARCHAR,
    codePostal CHAR(10) NOT NULL,
    FOREIGN KEY (codePostal) REFERENCES Ville(codePostal),
    PRIMARY KEY (numero, rue, codePostal)
);

CREATE TABLE Genre(
    nom VARCHAR PRIMARY KEY
);

CREATE TABLE editeur(
    nom VARCHAR PRIMARY KEY
);

CREATE TABLE Ressources(
    CodeRessource INT PRIMARY KEY, 
    titre VARCHAR, 
    dateApparition DATE, 
    codeClassification INT, 
    nomGenre VARCHAR NOT NULL,
    nomEditeur VARCHAR NOT NULL,
    FOREIGN KEY (nomGenre) REFERENCES Genre(nom),
    FOREIGN KEY (nomEditeur) REFERENCES editeur(nom) 
);

CREATE TABLE Livre(
    CodeRessource INT PRIMARY KEY,
    ISBN CHAR(20) UNIQUE, 
    resume VARCHAR, 
    langue CHAR(30),
    FOREIGN KEY (CodeRessource) REFERENCES Ressources(CodeRessource)
);

CREATE TABLE Musique(
    CodeRessource INT PRIMARY KEY,
    duree CHAR(8),
    FOREIGN KEY (CodeRessource) REFERENCES Ressources(CodeRessource)
);

CREATE TABLE Film(
    CodeRessource INT PRIMARY KEY,
    synopsis VARCHAR,
    duree CHAR(8), 
    langue CHAR(30),
    FOREIGN KEY (CodeRessource) REFERENCES Ressources(CodeRessource)
);

CREATE VIEW vlivre AS
SELECT  R.CodeRessource, R.titre, R.dateApparition, R.codeClassification, R.nomGenre, R.nomEditeur, L.ISBN, L.resume, L.langue
FROM Ressources R
JOIN Livre L ON R.CodeRessource =L.CodeRessource;

CREATE VIEW vMusique AS
SELECT  R.CodeRessource, R.titre, R.dateApparition, R.codeClassification, R.nomGenre, R.nomEditeur, M.duree
FROM Ressources R
JOIN Musique M ON R.CodeRessource =M.CodeRessource;

CREATE VIEW vFilm AS
SELECT  R.CodeRessource, R.titre, R.dateApparition, R.codeClassification, R.nomGenre, R.nomEditeur, F.synopsis, F.duree, F.langue
FROM Ressources R
JOIN Film F ON R.CodeRessource =F.CodeRessource;


CREATE TABLE Personne(
    id INT PRIMARY KEY, 
    nom VARCHAR NOT NULL, 
    prenom VARCHAR NOT NULL, 
    dateDeNaissance DATE,
    email VARCHAR,
    telephone CHAR(20),
    numero CHAR(5) NOT NULL,
    rue VARCHAR NOT NULL,
    codePostal CHAR(10),
    FOREIGN KEY (numero, rue, codePostal) REFERENCES Adresse(numero, rue, codePostal)
);



CREATE TABLE Contributeur(
    id INT PRIMARY KEY,
    nationalite CHAR(50),
    FOREIGN KEY (id) REFERENCES Personne(id)
);

CREATE TABLE Utilisateur(
    id INT PRIMARY KEY,
    login VARCHAR NOT NULL,
    password VARCHAR NOT NULL,
    FOREIGN KEY (id) REFERENCES Personne(id)
);


-- vue Personne + adresse
CREATE VIEW vPersonne AS 
SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, P.numero, P.rue, P.codePostal, V.nom AS ville, V.pays
FROM Personne P
Join Adresse A ON P.numero = A.numero AND P.rue = A.rue AND P.codePostal = A.codePostal
JOIN Ville V ON A.codePostal = V.codePostal;

-- CREATE VIEW vUtilisateur AS 
-- SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, U.login, U.password 
-- FROM Personne P 
-- JOIN Utilisateur U ON P.id = U.id;

CREATE VIEW vUtilisateur AS 
SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, P.numero, P.rue, P.codePostal, P.ville, P.pays, U.login, U.password 
FROM vPersonne P 
JOIN Utilisateur U ON P.id = U.id;




-- CREATE VIEW vContributeur AS 
-- SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, C.nationalite
-- FROM  Personne P 
-- JOIN Contributeur C ON P.id = C.id;

CREATE VIEW vContributeur AS 
SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, C.nationalite, P.numero, P.rue, P.codePostal, P.ville, P.pays
FROM  vPersonne P 
JOIN Contributeur C ON P.id = C.id;




CREATE TABLE Personnel(
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Utilisateur(id)
);

CREATE TABLE Adherent(
    id INT PRIMARY KEY,
    Blackliste BOOL,
    FOREIGN KEY (id) REFERENCES Utilisateur(id)
);



-- CREATE VIEW vPersonnel AS 
-- SELECT U.id, U.login, U.password
-- FROM Utilisateur U
-- JOIN Personnel P ON U.id = P.id;

CREATE VIEW vPersonnel AS 
SELECT P.id, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, P.numero, P.rue, P.codePostal, P.ville, P.pays, P.login, P.password   
FROM vUtilisateur P
JOIN Personnel PP  ON P.id = PP.id;

-- CREATE VIEW vAdherent AS
-- SELECT U.id, U.login, U.password, A.Blackliste
-- FROM Utilisateur U
-- JOIN Adherent A ON U.id = A.id;

CREATE VIEW vAdherent AS
SELECT P.id,A.Blackliste, P.nom, P.prenom, P.dateDeNaissance, P.email, P.telephone, P.numero, P.rue, P.codePostal, P.ville, P.pays, P.login, P.password    
FROM vUtilisateur P
JOIN Adherent A ON P.id = A.id;





CREATE TABLE Exemplaire( 
    id INT PRIMARY KEY,
    etat VARCHAR NOT NULL, 
    CodeRessource INT NOT NULL,
    FOREIGN KEY (CodeRessource) REFERENCES Ressources(CodeRessource)
);

CREATE TABLE Pret(
    debut DATE,
    duree INT NOT NULL,
    dateRendu DATE,
    id_exp INT,
    id_adh INT,
    FOREIGN KEY (id_exp) REFERENCES Exemplaire(id),
    FOREIGN KEY (id_adh) REFERENCES Adherent(id),
    PRIMARY KEY (debut, id_exp, id_adh),
    CHECK (dateRendu IS NULL OR dateRendu >= debut)
);

CREATE TABLE Contribue(
    role VARCHAR, 
    CodeRessource INT,
    id INT,
    FOREIGN KEY (CodeRessource) REFERENCES Ressources(CodeRessource),
    FOREIGN KEY (id) REFERENCES Contributeur(id),
    PRIMARY KEY (role, CodeRessource, id)
);

CREATE TABLE Adhesion(
    NoCarteAdherent INT, 
    debut DATE NOT NULL,
    fin DATE, 
    idAdherent INT,
    FOREIGN KEY (idAdherent) REFERENCES Adherent(id),
    PRIMARY KEY (NoCarteAdherent, idAdherent),
    CHECK (fin IS NULL OR fin > debut)
);

CREATE TABLE Sanction(
    date DATE NOT NULL, 
    duree INT NOT NULL, 
    motif VARCHAR, 
    id INT,
    FOREIGN KEY (id) REFERENCES Adherent(id),
    PRIMARY KEY(date, id)
);


 
