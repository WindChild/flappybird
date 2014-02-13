#include "GroundLayer.h"

using namespace cocos2d;

bool GroundLayer::init()
{

  if ( !CCLayer::init() )
  {
      return false;
  }
  CCSize winSize = CCDirector::sharedDirector()->getWinSize();

  m_pGround1 = CCSprite::create("ground.png");
  m_pGround1->setAnchorPoint(ccp(0,0));
  CCSize groundSize = m_pGround1->getContentSize();
  m_pGround1->setPosition(ccp(0,0));
  addChild(m_pGround1);
  
  m_pGround2 = CCSprite::create("ground.png");
  m_pGround2->setAnchorPoint(ccp(0,0));
  m_pGround2->setPosition(ccp(groundSize.width,0));
  addChild(m_pGround2);

  scheduleUpdate();
  return true;
}

void GroundLayer::update(float delte)
{
  CCSize groundSize = m_pGround1->getContentSize();
  int posX1 = m_pGround1->getPositionX();
  int posX2 = m_pGround2->getPositionX();

  int speed = 3;

  posX1 -= speed;
  posX2 -= speed;

  if(posX1 <= -groundSize.width){
    posX1 = groundSize.width;
  }


  if(posX2 <= -groundSize.width){
    posX2 = groundSize.width;
  }

  m_pGround1->setPositionX(posX1);
  m_pGround2->setPositionX(posX2);

}

