#ifndef GESTION_H
#define GESTION_H

#include "IConstante.h"

#include <SFML/Graphics.hpp>
#include "BiomePlanete.h"
#include "Univers.h"
#include "Vaisseau.h"
#include "PersonnageBoss.h"
#include "Personnage.h"

class Gestion : public sf::Event, public IConstante
{
    public:
        int choixMenu = INITIALISED_VALUE;
        Gestion();
        virtual ~Gestion();

        void fenetrePrincipale(); //Window windowjeu
        void menu(sf::RenderWindow & windowJeu);
        void launch(sf::RenderWindow & windowJeu);
        void combatPlanete(sf::RenderWindow & windowJeu,Planete&);

        void map_space(sf::RenderWindow & windowJeu);


    protected:

    private:
        Univers univers;
        Vaisseau vaisseau;

        PersonnageBoss persoBoss;
        Personnage heroTest;

};

#endif // GESTION_H
