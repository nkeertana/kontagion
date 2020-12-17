#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <list>

class Socrates;
class Actor;
class Dirt;
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    virtual ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    

private:
    std::list<Actor*> m_actor;;
    Socrates* m_socrates;
    int m_numDirts;
    int m_level;
};

#endif // STUDENTWORLD_H_
