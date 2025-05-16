# Cascadia

## Répartition


## Convention typage C++


### 1. Noms de Variables

- **Variables locales** : Utilisez le style `camelCase`.
  - Exemple :
    ```cpp
    int myVariable = 10;
    double distanceInKm = 15.5;
    ```

- **Variables globales** : Préfixez les variables globales avec `g_` en utilisant le style `snake_case`.
  - Exemple :
    ```cpp
    int g_maxValue;
    double g_currentSpeed;
    ```

- **Constantes** : Utilisez le style `UPPER_SNAKE_CASE` pour les constantes et les macros.
  - Exemple :
    ```cpp
    const int MAX_VALUE = 100;
    #define PI 3.14159
    ```

- **Pointeurs** : Utilisez le type suivi de l'astérisque (`*`) à côté du nom de la variable (plutôt que de l'ajouter au type).
  - Exemple :
    ```cpp
    int* pInt;
    char* pChar;
    ```

## 2. Noms de Fonctions

- **Fonctions** : Utilisez le style `camelCase` pour les noms de fonctions.
  - Exemple :
    ```cpp
    void calculateTotal() { }
    int findMax(int a, int b) { return a > b ? a : b; }
    ```

- **Fonctions membres** : Utilisez également le style `camelCase` pour les noms de fonctions membres.
  - Exemple :
    ```cpp
    class MyClass {
    public:
        void doSomething();
    private:
        int myVar;
    };
    ```

- **Fonctions de type getter/setter** : Les getters commencent par `get` et les setters par `set`, suivis de la variable concernée.
  - Exemple :
    ```cpp
    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }
    ```

## 3. Noms de Classes et Structs

- Utilisez le style `PascalCase` pour les classes et structs.
  - Exemple :
    ```cpp
    class Person {};
    struct Employee {};
    ```

- Pour les structures ou classes qui représentent une ressource système ou une entité dans le domaine, utilisez un nom explicite.
  - Exemple :
    ```cpp
    class DatabaseConnection {};
    ```

## 4. Noms de Fichiers

- Les fichiers d'en-tête (`.h`, `.hpp`) et de source (`.cpp`) doivent être en `camelCase`.
  - Exemple : 
    ```text
    my_class.hpp
    database_connection.cpp
    ```