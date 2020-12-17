#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameWorld.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
    Actor (int ImageID, double startX, double startY, int startDirection, int depth, StudentWorld* sWorld);
    virtual ~Actor();
    bool isAlive();
    virtual void doSomething();
    
    StudentWorld* getWorld ();
private:
    bool m_alive;
    StudentWorld* m_studentWorld;
    
    //every actor has coordinates
    //can perform an action like move, damage another actor, etc.
    //can potentially be attacked
    //can die after an attack
    //certain objects activate after coming into contact with the proper target
    //flames activate when they overlap with bacteria, goodie, fungus or dirt pile
};

class Dirt : public Actor

{
public:
    Dirt (double startX, double startY, StudentWorld* sWorld);
    virtual void doSomething();
};

class Socrates : public Actor

{
public:
    Socrates (StudentWorld* sWorld);
    virtual void doSomething();
    
    //need not implement firing, spraying, etc.
};




#endif // ACTOR_H_
