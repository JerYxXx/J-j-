#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "grille.h"
#include <vector>
using namespace std;

class jeu {
private:
    vector<grille> historique;
    int generation;

public:
    jeu();
    void jouer(grille &grille1, int iterations);
    int population(const grille &grille1) const;
    void retour();
    int getGeneration() const { return generation; }
};

#endif // JEU_H_INCLUDED
