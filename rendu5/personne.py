from password import *
from requeteSql import *

PERSONNEL=1
ADHERENT=2
DEBUG=666
QUITTER=777

idPersonne=-1
CategoriePersonne=-1



def print_todo():
    print("non implémenté")

# -------------------------------------------------------------------------
# code pour personne /utilisateur/adherent/personnel/contributeur/editeur/adhesion/sanction
# -------------------------------------------------------------------------




# -------------------------------------------------------------------------
# code pour personne 
# -------------------------------------------------------------------------

def nom_prenom(id):
    sql = f"SELECT nom,prenom FROM vUtilisateur WHERE id={id}"
    res=executeSqlSelectToTuple(sql)
    
    txt=""
    if res :
        txt=f"nom: {res[0]} prénom: {res[1]}"
        
    return txt



# -------------------------------------------------------------------------
# code pour utilisateur
# -------------------------------------------------------------------------

def login():
    """ Demander à l'utilisateur son identifiant, mot de passe et reourne le tupple (id, code)  
                                                avec code = -1 si erreur ou 1 si personnel ou 2 adherent
    """
    username = input("Entrez votre identifiant: ")
    password = input("Entrez le mot de passe: ")
   
    sql = f"""
            SELECT id FROM vPersonnel 
            WHERE login = '{username}' and password = '{password}' 
            """
    id = valeurExecuteSql(sql)
    
    
    if id>=0 :
        return  (id,PERSONNEL)# Utilisateur trouvé 1=personnel
    

    sql = f"""SELECT id FROM vUtilisateur 
                   WHERE login = '{username}' and password = '{password}' 
            """    

    id = valeurExecuteSql(sql)
   
    if id>=0 :
        return  (id,ADHERENT)# adhérent trouvé 
    
    return (-1,-1) # aucun utili trouve


# -------------------------------------------------------------------------
# code pour adherent
# -------------------------------------------------------------------------

def changerAdherent(): #TODO:changerAdherent -> appel login()
    id,ADHERENT=rechercherAdherent()
    return (id,ADHERENT)
    #debug
    idAdh=input("Entrez l'id de l'adherent ")
    idPersonne=int(idAdh)
    CategoriePersonne=int(input("Entrez la categorie 1 admin ou 2 adherent"))
    # CategoriePersonne=ADHERENT 
    # CategoriePersonne=PERSONNEL 
    return idPersonne,CategoriePersonne


def rechercherAdherent(etActiver=True,retournerId=False):
    nom=input("Entrez le nom de l'adherent ( ex DUPONT DUP* )")
    
    if '*' in nom :
        nom = nom.replace('*','%')
    if nom :
        sql=f"SELECT id, nom, prenom FROM vAdherent WHERE nom ILIKE '{nom}'" #ILIKE = insensitive LIKE
    else:
        sql=f"SELECT id, nom, prenom FROM vAdherent"
        
    choix =executeSqlSelect(sql,['id','nom','prénom'],True)
    if choix[0] <0: #non trouvé
        return (-1,ADHERENT)
    id= choix[1]
    if(id>=0):
        print("vous avez choisi :")
        AfficheAdherent(id)
        
    if etActiver and not retournerId:
        choix=input("Voulez vous l'activer (O/N)?").lower()
        if choix=='o':
            return (id,ADHERENT) #= (idAdherent, _ )
    
    if retournerId :
        return (id,ADHERENT)
    
    return(-1,-1)

def creerAdherent(type=ADHERENT):#TODO:creerAdherent()
    
    # INSERT INTO Personne  (id, nom , prenom , dateDeNaissance , email ,  telephone, numero ,rue, codePostal )
    # INSERT INTO Adherent ( id , Blackliste )
    # INSERT INTO Personnel ( id ) 
    id = getNextId("personne")
    choix=''
    nom=""
    prenom=""
    numero=""
    rue=""
    codePostal=""
    login=""
    password=""
    while(choix!='o' and choix!='q'):
        while (not nom):
            nom=input("nom? ")
        while (not prenom):
            prenom=input("prénom? ")
        while (not numero):
            numero=input("numéro? ")
        while (not rue):
            rue=input("rue? ")
        while (not codePostal):
            codePostal=input("code postal? ")
            ville=validerCodePostal(codePostal)
            if (not ville):
                print("abandon")
                return
        dateDeNaissance=inputDate("date de naissance? ")
        email=input("mail? ")
        telephone=input("téléphone? ")
        while (not login):
            login=input("choisissez un login :")
        while (not password):
            password=input("choisissez un mot de passe: ")
        print(f"{id}, {nom} , {prenom} , {dateDeNaissance} , {email} ,  {telephone}, {numero} ,{rue}, {codePostal}, {ville}")    
        choix = input("valider ? (O/N/Q(uit))").lower()
        creationAdresse(numero,rue,codePostal)
        sql=f"INSERT INTO Personne  (id, nom , prenom , dateDeNaissance , email ,  telephone, numero ,rue, codePostal )\
            VALUES ({id}, '{nom}' , '{prenom}' , '{dateDeNaissance}' , '{email}' ,  '{telephone}', '{numero}' ,'{rue}', '{codePostal}')"
    res=executeSqlUpdate(sql)
    if res>0 :
        if (type==ADHERENT):
            sql = f"""INSERT INTO Utilisateur(id, login , password )
                    VALUES ({id},'{login}','{password}')"""
            res=executeSqlUpdate(sql)
            sql = f"""INSERT INTO Adherent(id, blackliste )
                    VALUES ({id},'false')"""
            res=executeSqlUpdate(sql)
            
    
    if res>0 :
        print("adhérent inséré")
    else :
        print("erreur création utilisateur")

def creationAdresse(numero,rue,codePostal):
    sql= f"SELECT rue FROM adresse WHERE codepostal = '{codePostal}' and rue='{rue}' and numero='{numero}'"
    res=valeurExecuteSql(sql,entier=False)
    if not res :
        sql=f"INSERT INTO adresse (numero,rue,codePostal) VALUES ('{numero}','{rue}','{codePostal}')"
        executeSqlUpdate(sql)
    
    
def validerCodePostal(codePostal):
    
    sql= f"SELECT nom FROM ville WHERE codepostal = '{codePostal}'"
    ville = valeurExecuteSql(sql,entier=False)
    if not ville :
        choix=input(f"voulez vous ajouter la ville ({codePostal} O/N)?").lower()
        if (choix=='o'):
            ville=input('ville?')
            pays=input("pays?")
            sql=f"INSERT INTO ville ( codePostal , nom, pays ) VALUES ('{codePostal}','{ville}','{pays}')"
            executeSqlUpdate(sql)
    
    
    return ville

    
def sanctionnerAdherent(id_adherent=-1,dateDebut=None,dateFin=None):
    choix='n'
    if ( id_adherent and id_adherent>=0):
        choix = input(f"\nvoulez vous sanctionner {nom_prenom(id_adherent)} (id={id_adherent}) (O/N)?").lower()
    if (choix=='o'):
        id = id_adherent
    else:
        id ,_ = rechercherAdherent(retournerId=True)
    
    if (id>=0):
        motif = getMotifSanction()
        while(motif==""):
            print("il faut un motif")
            motif = getMotifSanction()
        duree = calculerDureeSanction(motif,dateDebut,dateFin)
        date=inputDate("à partir de quelle date (aaaa-mm-jj)? ")
        print(f"adhérent : {nom_prenom(id)} (id{id})")
        print(f"motif : {motif} durée sanction:{duree}j à partir de {date}")

        choix=input( "confirmez la sanction (O/N)").lower()
        if choix=='o':
            res=sanctionnerAdherentSql(id,date,duree,motif)
            if (res>=0):
                print("n+++sanction appliquée+++\n")
        else :
            print("abandon")
    
def sanctionnerAdherentSql(id,date,duree,motif):
    """ 
    - une suspension du droit de prêt d'une durée égale au nombre de jours de retard. 
    - En cas de perte ou détérioration grave d'un document, la suspension du droit de prêt est maintenue jusqu'à ce que l'adhérent rembourse le document
    - la bibliothèque peut choisir de blacklister un adhérent en cas de sanctions répétées.
    """
    sql = f"INSERT INTO Sanction (date,duree,motif,id) VALUES ('{date}',{duree},'{motif}',{id})"
    res=executeSqlUpdate(sql)
    return res


def getMotifSanction():
    print("choisir le motif :")
    print("1:retard ")
    print("2:dégradation ")
    
    choix = input()
    match(choix) :
        case '1':
            motif="retard"
        case '2':
            motif="degradation"
        case _:
            motif=""
    return motif
            

def calculerDureeSanction(motif,dateDebut=None,DateFin=None):
    if (motif=="degradation"):
        duree=999999 #jusqu'à remboursement
    elif (motif=="retard"):
        duree=calculRetardPret(dateDebut,DateFin)
        
    return duree

def calculRetardPret(dateDebut,dateFin):
    """ dates au format aaaa-mm-jj
    """
    duree=10 #défaut
    try :
        a,m,j = dateDebut.split('-')
        a2,m2,j2 = dateFin.split('-')
        duree= (int(a2)-int(a))*365+(int(m2)-int(m))*30+(int(j2)-int(j))
        if(duree<0):
            duree=-duree
        
    except:
        pass #TODO:
        # print("erreur calcul durée sanction")
        
    return duree


def AfficheAdherent(id):
    sql = f""" 
        SELECT id, blackliste, nom, prenom , datedenaissance ,  email,telephone, numero, rue, codepostal,ville,pays,login  
        FROM vAdherent 
        WHERE id = {id}
    
    """
    executeSqlSelect(sql,["id", "blacklisté", "nom", "prénom" , "date de naissance" ,"email",
                          "téléphone", "numéro", "rue", "code postal","ville","pays","login" ])

# -------------------------------------------------------------------------
# code pour personnel
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
# code pour contributeur
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
# code pour editeur
# -------------------------------------------------------------------------


def choixEditeur(menuAjouter=False):
    sql="SELECT nom FROM editeur ORDER BY nom"
    choix =executeSqlSelect(sql,None,True,menuAjouter) # possibilité d'ajouter un éditeur si menuAjouter == True
    
    if(choix==-1): 
        InsertEditeur()
        choix =executeSqlSelect(sql,None,True,menuAjouter)
    
    return choix[1]


#atester
def InsertEditeurSql(nom):
    conn = psycopg2.connect("host=%s dbname=%s user=%s password=%s" % (HOST, DATABASE, USER, PASSWORD))
    cursor = conn.cursor()
    sql = f"INSERT INTO Editeur (nom)  VALUES ('{nom}')"        
    cursor.execute(sql)
    conn.commit()
    print("editeur/producteur insere avec succès.")
    cursor.close()
    conn.close()


def InsertEditeur():
    nom = input("entrez le nom d'un éditeur ")
    
    choix = input(f"ajouter '{nom}' (O/N)?").lower()
    if (choix=='o') :
        InsertEditeurSql(nom)


# -------------------------------------------------------------------------
# code pour adhesion
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
# code pour sanction
# -------------------------------------------------------------------------



def compteBlackliste():
    sql= """
    SELECT Blackliste ,COUNT(Blackliste) 
                FROM Adhent
                 GROUP BY (Blackliste)                 
                
    
    """
    
    executeSqlSelect(sql,["bLACKLISTÉ","Nombre "])


if __name__ == "__main__":
    pass
    # print(nom_prenom(1))
    # print(nom_prenom(10))
    # print(nom_prenom(100))
    # print(calculerDureeSanction("retard",'2023-11-10','2024-12-12'))
    # sanctionnerAdherent(2)
    
    # print(validerCodePostal('60610'))
    # creationAdresse(10,'RUE DES MIMOSAS','60200')
    creerAdherent()