#pragma once
#include <iostream>
#include <string>
#include "tuile.h"
#include "affichable.h"

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
    Position getE() const  { return Position(x + 1, y); }
    Position getSE() const { return Position(x, y + 1); }
    Position getSW() const { return Position(x - 1, y + 1); }
    Position getW() const  { return Position(x - 1, y); }
    Position getNW() const { return Position(x, y - 1); }
    Position getNE() const { return Position(x + 1, y - 1); }
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

    const Tuile* getTuile() const {return tuile;}
    animalOuPas getJeton() const {return jeton;}
    virtual void deplacer(const Position& p);
    virtual void tourner(const int n);
    void ajouterJeton(const animalOuPas a);
};

class TuilePlaceeDeplacable : public TuilePlacee {
public:
    TuilePlaceeDeplacable() = default;
    ~TuilePlaceeDeplacable() = default;

    void deplacer(const Position& p2) override {pos.SetPosition(p2);}
    void tourner(int n) override {rotation = (rotation + n) % 6;}
    Position getPosition() const {return pos;}
    int getRotation() const {return rotation;}
};