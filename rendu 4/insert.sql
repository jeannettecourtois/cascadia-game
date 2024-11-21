DELETE FROM Film;
DELETE FROM Pret;
DELETE FROM Exemplaire;
DELETE FROM Contribue;
DELETE FROM Ressources;


DELETE FROM Personnel;
DELETE FROM Adhesion;
DELETE FROM Adherent;
DELETE FROM Utilisateur;


DELETE FROM Contributeur;
DELETE FROM Personne;

DELETE FROM Genre;


DELETE  FROM editeur;
DELETE  FROM Adresse;
DELETE  FROM Ville;


INSERT INTO Ville (codePostal , nom, pays ) 
VALUES  
        ('1','inconnu','inconnu'),
        ('60200','COMPIEGNE','FRANCE'),
        ('60100','LACROIX SAINT OUEN','FRANCE'),
        ('35800','DINARD','FRANCE'),
        ('GB-BR3','LONDON','ENGLAND'),
        ('US90001','Los Angeles','USA');


INSERT INTO Adresse (numero, rue, codePostal) 
    VALUES  ('0','0','1'),
            ('25','Rue Roger Couttolenc', '60200'),
            ('125','Rue de Paris', '60200'),
            ('10', 'Gabriel Ancelet', '60200'),
             ('1','Rue du Général Giraud', '35800'),
            ('120', 'Gabriel Ancelet', '60200'),
            ('1','Westminster','GB-BR3'),
            ('15','Hollywood Bd','US90001');



-- --------------- creation des genres et éditeur (ou producteur pour un film)

INSERT INTO Genre (nom) VALUES ('Drame romantique'),('Thriller'),('Espionnage, Thriller'),
 ('Science Fiction, Thriller'),('Science Fiction'),('Drame, Histoire'),('Drame'),
 ('Aventure, Fantasy');

INSERT INTO editeur (nom) VALUES ('James Cameron'),
                        ('Les films classiques'),
                        ('Warner Bros'),
                        ('Universal Pictures');  


-- --------------- creation de personnes : contributeur, utilisateur, personnel, adherent + adhésion

INSERT INTO Personne  (id, nom , prenom , dateDeNaissance , email ,  telephone, numero ,rue, codePostal )
     VALUES (1, 'Jilani', 'Amine', '2003-02-24', 'amine.jilani@gmail.com', '0123456789', '10', 'Gabriel Ancelet', '60200'),
      (2, 'Hitchock', 'Alfred', '1900-02-24', 'no mail', '0713456789', '125', 'Rue de Paris', '60200'),
      (3, 'Hitchock', 'Berthe', '1900-01-24', 'no mail', '', '125', 'Rue de Paris', '60200'),
      (4, 'Point', 'Yvon', '1995-04-20', 'no mail', '0666456789', '1', 'Rue du Général Giraud', '35800'),
      (5, 'Jack', 'L''eventreur', '2000-04-20', 'no mail', '0666456789', '1','Westminster','GB-BR3'),
      (6, 'Point', 'Marie', '2001-09-05', 'no mail', '0666456789', '1', 'Rue du Général Giraud', '35800'),
      (7,'Eastwood','Clint','1930-05-31','clint@gmail.com','','15','Hollywood Bd','US90001'),
      (8, 'Grant','Cary','1904-01-19','','','0','0','1'),
    (9, 'Dupont', 'Jean', '1995-05-10', 'jean.dupont@email.com', '0612345678', '25','Rue Roger Couttolenc','60200'),
    (10, 'Martin', 'Claire', '1990-03-15', 'claire.martin@email.com', '0612345679', '125','Rue de Paris','60200');


INSERT INTO Contributeur (id,nationalite) 
    VALUES  (2,'Britanique'),
            (8,'Américain');


INSERT INTO Utilisateur(id, login , password )
    VALUES (1,'amine.jilani','1234');

INSERT INTO Utilisateur(id, login , password )
    VALUES (4,'point_y','546'),
            (5,'killer','666'),
            (6,'marie_p','abc!'),
            (7,'mp6','abc!'),
            (8,'mp','abc!'),
            (9,'m4p','abc!'),
            (10,'m47p','abc!');

INSERT INTO Personnel ( id ) 
    VALUES (4);

INSERT INTO Adherent ( id , Blackliste )
    VALUES (5, true),
            (6,false),
            (7,false),
            (8,false),
            (9,false),
            (10, true);

INSERT INTO Adhesion ( NoCarteAdherent ,  debut, fin ,  idAdherent )
    VALUES (123,'2000-01-01','2010-01-01',5),
            (5503,'2020-01-01',NULL,6);

    
--    ---------------------- creation d'une ressource film (avec 2 contributeurs : 1 acteur, 1 réalisateur + 1 producteur(editeur))  en 2 exemplaires

-- INSERT INTO Ressources   (CodeRessource , titre ,  dateApparition ,  codeClassification ,  nomGenre ,  nomEditeur) 
--     VALUES (1,'La mort aux trousses','1959-01-01',100,'Thriller','Les films classiques');

INSERT INTO Ressources (CodeRessource, titre, dateApparition, codeClassification, nomGenre, nomEditeur)
VALUES
    (1, 'La mort aux trousses', '1959-01-01', 100, 'Thriller', 'Les films classiques'),
    (2, 'Le Seigneur des Anneaux', '2001-12-19', 101, 'Aventure, Fantasy', 'Les films classiques'),
    (3, 'Inception', '2010-07-16', 102, 'Science Fiction, Thriller', 'Warner Bros'),
    (4, 'La Liste de Schindler', '1993-12-15', 103, 'Drame, Histoire', 'Universal Pictures');



INSERT INTO Contribue( role, CodeRessource ,id )
    VALUES ('réalisateur',1,2),
            ('acteur',1,8);


INSERT INTO Film( CodeRessource ,synopsis ,duree, langue)
    VALUES (1,'Le publiciste Roger Tornhill se retrouve par erreur dans la peau d''un espion.','2h16','Anglais'),
     (2, 'Lhistoire épique du voyage de Frodon Sacquet pour détruire lAnneau Unique.', '3h20', 'Anglais'),
    (3, 'Un voleur de rêves professionnels est chargé de planter une idée dans lesprit dun héritier.', '2h28', 'Anglais'),
    (4, 'Lhistoire vraie dun industriel qui sauve des milliers de Juifs durant la Seconde Guerre mondiale.', '3h15', 'Anglais');

    

INSERT INTO Exemplaire( id, etat ,  CodeRessource )
    VALUES (1,'bon',1),
     (2,'trés bon',1),
    (3, 'Neuf', 3),
    (4, 'Usagé', 4),
    (5, 'Neuf', 2);


--   ------------ pret d'un exemplaire (film) à Marie -------

INSERT INTO  Pret( debut, duree, dateRendu , id_exp , id_adh )
            VALUES ('2024-11-14',20,NULL,1,6);


INSERT INTO  Pret( debut, duree, dateRendu , id_exp , id_adh )
            VALUES ('2024-11-14',20,NULL,3,6);

INSERT INTO  Pret( debut, duree, dateRendu , id_exp , id_adh )
            VALUES ('2024-11-14',20,NULL,3,5),
            ('2024-11-16',20,NULL,3,5),
            ('2024-11-15',20,NULL,3,5),
            ('2024-11-13',20,NULL,3,5);
