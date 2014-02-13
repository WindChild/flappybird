#ifndef __GROUND_LAYER_H__
#define __GROUND_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class GroundLayer : public cocos2d::CCLayer
{
public:
  virtual bool init();  

  CREATE_FUNC(GroundLayer);
  virtual void update(float delte);
private:
  CCSprite *m_pGround1;
  CCSprite *m_pGround2;
};

#endif
