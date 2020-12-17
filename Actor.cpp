#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp


Actor::Actor (int ImageID, double startX, double startY, Direction startDirection, int depth, StudentWorld* sWorld)
: GraphObject(ImageID, startX, startY, startDirection, depth)
{
    m_alive = 1;
    m_studentWorld = sWorld;
}
Actor::~Actor()
{
    
}
bool Actor::isAlive()
{
    return m_alive;
}
void Actor::doSomething()
{
    
}

StudentWorld* Actor::getWorld ()
{
    return m_studentWorld;
}

Dirt::Dirt (double startX, double startY, StudentWorld* sWorld)
: Actor(IID_DIRT, startX, startY, 0, 1, sWorld)
{
}

void Dirt::doSomething()
{
}

Socrates::Socrates(StudentWorld* sWorld)
: Actor(IID_PLAYER, 0, 128, 0, 0, sWorld)
{
    
}
void Socrates::doSomething()
{
    if (!isAlive())
        return;
    else
    {
        int ch;
        if (getWorld()->getKey(ch)) {
            double newX, newY;
            switch (ch) {
                case KEY_PRESS_LEFT: //ask razma
                {
                    newX = (128 + 128 * cos((getDirection() - 180 + 5) * 0.0174533));
                    newY = (128 + 128 * sin(((getDirection() - 180 + 5)) * 0.0174533));
                    moveTo(newX, newY);
                    setDirection(getDirection()+5);
                    
                    break;
                }
                case KEY_PRESS_RIGHT: //ask razma
                {
                    newX = (128 + 128 * cos((getDirection() - 180 - 5) * 0.0174533));
                    newY = (128 + 128 * sin(((getDirection() - 180 - 5)) * 0.0174533));
                    moveTo(newX, newY);
                    setDirection(getDirection()-5);
                    break;
                }
                default:
                    break;
                    
                    
            }
        }
    }
}
