#ifndef __BIRD_H__
#define __BIRD_H__

#include "cocos2d.h"

using namespace cocos2d;
class Bird : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(Bird);
    void flyAnimation();
private:
  CCSprite *m_pBird;
  void fallAnimation();
};

#endif // __BIRD_H__
