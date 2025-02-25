#include "CharacterBoss.h"
#include "Planet.h"
#include "Character.h"

/*
    This is the constructor
    As you can see, we call categoryBoss()', because a boss is initialized here with his own statistics
*/
CharacterBoss::CharacterBoss(const string name, const int ptsAttack, const int ptsLife, const int badge,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge, const int x, const int y, const string picture, const int regeneration, const Origin origin)
:Character(name,ptsAttack,ptsLife,badge,ptsSpecialAttack,shield,criticalHit,dodge, x, y, picture, regeneration), origin(origin)
{
   categoryBoss();
   setBadge(2);
}

/*
    This is the second constructor
*/
CharacterBoss::CharacterBoss(const string name, const Origin origin)
:Character(name),origin(origin)
{

    categoryBoss();
    setBadge(2);
}

/*
    This is the destructor
*/
CharacterBoss::~CharacterBoss()
{

}

/*
    This is the copy constructor
*/
CharacterBoss::CharacterBoss(const CharacterBoss& cB):Character(cB), origin(cB.origin)
{
    categoryBoss();
}

/*
    This is operator='s function
*/
CharacterBoss& CharacterBoss::operator=(const CharacterBoss& cB)
{
    if (this != &cB)
    {
        Character::operator=(cB);
        origin = cB.origin;
    }
    return *this;
}

/*
    This is the str() of a boss
*/
string CharacterBoss::str() const
{
    std::stringstream ss;
    ss << Character::str();
        return ss.str();
}

/*
    This the clone function of a boss
*/
CharacterBoss* CharacterBoss::clone()const
{
    return new CharacterBoss(*this);
}

/*
    This the most important function of a boss.
    It's where all statistics of a boss are initialized.
    e.g : the blue boss can have 100 life points ant the green one can have 250 life points. All bosses are unique
*/
void CharacterBoss::categoryBoss() {
    switch(origin) {
    case BLUE:
        setPtsLife(450);
        setPtsAttack(5);
        setCriticalHit(35.0);
        setPtsSpecialAttack(15);
        setShield(50);
        setX(1580);
        setY(550);
        setPicture("Images/Avatars/Bleue_Boss.png");
        break;

    case ORANGE:
        setPtsLife(150);
        setPtsAttack(15);
        setCriticalHit(20.0);
        setPtsSpecialAttack(25);
        setDodge(20.0);
        setShield(250);
        setX(1390);
        setY(600);
        setPicture("Images/Avatars/Orange_Boss.png");
        break;

    case GREEN:
        setPtsLife(200);
        setPtsAttack(15);
        setCriticalHit(25.0);
        setPtsSpecialAttack(25);
        setDodge(10.0);
        setShield(50);
        setX(1370);
        setY(610);
        setPicture("Images/Avatars/Verte_Boss.png");
        break;

    case RING_BLUE:
        setPtsLife(100);
        setPtsAttack(15);
        setCriticalHit(33.0);
        setPtsSpecialAttack(75);
        setDodge(40.0);
        setShield(25);
        setX(1200);
        setY(625);
        setPicture("Images/Avatars/Anneau_Bleu_Boss.png");
        break;

    case RING_RED:
        setPtsLife(300);
        setPtsAttack(20);
        setCriticalHit(35.0);
        setPtsSpecialAttack(35);
        setDodge(20.0);
        setShield(100);
        setX(1590);
        setY(595);
        setPicture("Images/Avatars/Anneau_Rouge_Boss.png");
        break;

    case PURPLE_DESTROYED:
        setPtsLife(50);
        setPtsAttack(15);
        setCriticalHit(20.0);
        setPtsSpecialAttack(30);
        setDodge(15.0);
        setShield(200);
        setX(1340);
        setY(605);
        setPicture("Images/Avatars/Mauve_Detruite_Boss.png");
        break;
    default:
        break;
    }
}

/*
    This is the getter of the origin
*/
Origin CharacterBoss::getOrigin()const
{
    return origin;
}

/*
    This is where a boss can resurrect from hell !
    As you can see, some of their points are augmented.
*/
void CharacterBoss::resurrection()
{
        setPtsLife(getPtsLife()+50);
        setPtsAttack(getPtsAttack()+10);
        setPtsSpecialAttack(getPtsSpecialAttack()+10);
        setShield(getShield()+10);
}
