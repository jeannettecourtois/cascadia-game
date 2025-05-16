#pragma once
#include "tuile.h"

class Position {
public:
    int x;
    int y;
    Position(const int a, const int b):x(a),y(b){}
    Position(const Position& pos):x(pos.x),y(pos.y){}
    ~Position();
    void SetPosition(const int a, const int b){x=a; y=b; return;}
    void SetPosition(const Position& pos){x=pos.x; y=pos.y; return;}
};

class TuilePlacee {
private:
    const Tuile* tuile;
    animalOuPas jeton;
protected:
    Position pos;
    int rotation;
public:
    TuilePlacee();
    //TuilePlacee(const TuilePlaceeDeplacable*); --> à revoir 
    ~TuilePlacee();
    void Deplacer(const Position){}
    void Tourner(const int){}
    const Tuile* GetTuile() const {return tuile;}
    animalOuPas GetJeton() const {return jeton;}
    void AjouterJeton(const animalOuPas);
};

class TuilePlaceeDeplacable : public TuilePlacee {
public:
    void Deplacer(const Position p2){pos.SetPosition(p2); return;}
    void Tourner(const int n){rotation = (rotation + n)%6; return;}
    Position GetPosition() const { return pos; }
    int GetRotation() const { return rotation; }
};