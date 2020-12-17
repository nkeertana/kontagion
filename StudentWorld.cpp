#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <list>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_level = 1;
}

StudentWorld::~StudentWorld()
{
    cleanUp();
}


int StudentWorld::init()
{
    m_socrates = new Socrates(this);
    m_level = getLevel();
    m_numDirts = max(180-20*m_level, 20);
    for (int i = 0; i < m_numDirts; i++) {
        double actorX, actorY;
        //make rand int for radius from 0 -120
        //make rand int for the angle
        //and then convert from angle to cartesian with rcos(theta)/rsin(theta)
        double angle, radius;
        angle = randInt(0, 360);
        radius = randInt(0, 120);
        actorX = (VIEW_HEIGHT/2) + (radius * cos(angle));
        actorY = (VIEW_WIDTH/2) + (radius * sin(angle));
        m_actor.push_back(new Dirt (actorX, actorY, this));
        
    }
    
    return GWSTATUS_CONTINUE_GAME;
}


int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
    if (m_socrates->isAlive() == false)
        return GWSTATUS_PLAYER_DIED;
    m_socrates->doSomething();
    list<Actor*>::iterator it;
    it = m_actor.begin();
    while (it != m_actor.end()) {
        (*it)->doSomething();
        it++;
    }
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    list<Actor*>::iterator it;
    it = m_actor.begin();
    while (it != m_actor.end()) {
        m_actor.erase(it);
        it++;
    }
    delete m_socrates;
}
