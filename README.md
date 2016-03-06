#INFO006_TP1_Caillet-Dilisio

Tables Arc-en-ciel et Attaque Compromis Temps/Mémoire
* Subject: 'http://www.lama.univ-savoie.fr/~lachaud/Cours/INFO006/Tests/doc/html/tp1.html'


##Installation

 ```bash
   make && ./INFO006_TP1_Caillet_Dilisio
 ```

##DONE
- [x] MD5 hash
- [x] Display MD5 hash   
- [x] Hash to index (h2i)
- [x] Index to plain text (i2c) 
- [x] Index to Index (i2i) 
- [x] Index Random 
- [x] Create Rainbow Table 
- [x] Display Rainbow Table 
- [x] Sort rainbow table by idxT
- [x] Save rainbow table
- [x] Load from saved file
- [x] Rainbow table binary search
- [x] Cracker 

##Utilisation 
- Créer une nouvelle table avec M = 100000 et T = 1000 : 
    - Ne pas toucher au code il est paramétré pour cela 
    - Il créera la table arc-en-ciel et un fichier big_dico.txt (~30 secondes) 
    - Puis vous proposera d'indiquez le MD5 à cracker
    - Attention = le mot chiffré doit être de 5 lettres comme "hello" (5d41402abc4b2a76b9719d911017c592) sans majuscules ni caractères alphanumériques
    - BUG = n'arrive pas à déchiffrer avec un alphabet a-zA-Z 
    - Tester avec les mots "hello", "choco", "caill" ... FONCTIONNELLE 
- Charger une table :
    - commenter dans le main.cpp les lignes de : create, save, sort; et décommenter load 
    - il load le fichier (big_dico.txt) 
- La fonction displayChaine permet d'afficher la table ( ex:  ... 1333750206 -i2i(1)-> ... -i2i(999)-> 11879996 ...)
- Le premier bloc commenté dans le main.cpp permet de tester les fonctions : h, h2i, i2c, i2i. 
    - nous trouvons les mêmes résultats que le dernier exemple fournit :
    ```
    taille   = 5
    alphabets = abcdefghijklmnopqrstuvwxyz0123456789
    nblettres= 36
    N        = 60466176
    T        = 100000
    M        = 50`
    ```
    - Note: décommenter les chiffres dans l'alphabet et modifier "_nb_lettres" à 36
    

    
#Dependencies 
- OpenSSL (1.0.2f)