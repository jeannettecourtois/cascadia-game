#pragma once
#include <iostream>
#include <string>
#include "tuile.h"

class TuilePlaceeDeplacable; // déclaration anticipée pour TuilePlacee

class Position {
public:
    int x;
    int y;
    Position(int a=0, const int b=0):x(a),y(b){}
    Position(const Position& pos):x(pos.x),y(pos.y){}
    ~Position() = default;
    void SetPosition(int a, int b){x=a; y=b;}
    void SetPosition(const Position& pos){x=pos.x; y=pos.y;}
    Position getE() const  { return Position(q + 1, r); }
    Position getSE() const { return Position(q, r + 1); }
    Position getSW() const { return Position(q - 1, r + 1); }
    Position getW() const  { return Position(q - 1, r); }
    Position getNW() const { return Position(q, r - 1); }
    Position getNE() const { return Position(q + 1, r - 1); }
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
    TuilePlacee(const TuilePlaceeDeplacable* t);
    ~TuilePlacee();

    const Tuile* GetTuile() const {return tuile;}
    animalOuPas GetJeton() const {return jeton;}
    virtual void Deplacer(const Position& p);
    virtual void Tourner(const int n);
    void AjouterJeton(const animalOuPas a);
};

class TuilePlaceeDeplacable : public TuilePlacee {
public:
    TuilePlaceeDeplacable() = default;
    ~TuilePlaceeDeplacable() = default;

    void Deplacer(const Position& p2) override {pos.SetPosition(p2);}
    void Tourner(int n) override {rotation = (rotation + n) % 6;}
    Position GetPosition() const {return pos;}
    int GetRotation() const {return rotation;}
};