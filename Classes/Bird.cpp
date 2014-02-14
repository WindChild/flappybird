#include "Bird.h"

bool Bird::init()
{
  if ( !CCLayer::init() )
  {
      return false;
  }
  CCSize winSize = CCDirector::sharedDirector()->getWinSize();

  CCAnimation * animation = CCAnimation::create();
  for(int i=1;i<=3;++i){
    char fileName[50] = {0};
    sprintf(fileName,"bird%d.png",i);
    CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fileName);
    animation->addSpriteFrame(pFrame);
  }
  animation->setDelayPerUnit(0.5f / 3.0f);
  CCAnimate *animate = CCAnimate::create(animation);
  
  CCActionInterval *moveBy = CCMoveBy::create(0.8f,ccp(0,8));
  CCAction *action = CCSequence::create(moveBy,moveBy->reverse(),NULL);
  
  m_pBird = CCSprite::createWithSpriteFrameName("bird1.png");
  m_pBird->setPosition(ccp(winSize.width/2-80,winSize.height/2));
  addChild(m_pBird);
  
  m_pBird->runAction(CCRepeatForever::create(CCSpawn::create(animate,(CCActionInterval*)action,NULL)));
  
  return true;

}

void Bird::flyAnimation()
{
  m_pBird->stopAllActions();

  m_pBird->setRotation(-50);
  
  CCActionInterval *actionMoveBy = CCMoveBy::create(0.3f,ccp(0,100));
  
  CCActionInterval *easeOut = CCEaseExponentialOut::create(actionMoveBy);
  
  CCAnimation * animation = CCAnimation::create();
  for(int i=1;i<=3;++i){
    char fileName[50] = {0};
    sprintf(fileName,"bird%d.png",i);
    CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fileName);
    animation->addSpriteFrame(pFrame);
  }
  animation->setDelayPerUnit(0.3f / 3.0f);
  CCAnimate *animate = CCAnimate::create(animation);

  m_pBird->runAction(CCSequence::create(CCSpawn::create(easeOut,animate,NULL),
                     CCCallFunc::create(this,callfunc_selector(Bird::fallAnimation)),
                     NULL));
}

void Bird::fallAnimation()
{
  m_pBird->stopAllActions();

  CCActionInterval *actionRotateTo = CCRotateTo::create(0.5,90);

  float speed = 800.0f;
  float distance = m_pBird->getPositionY();
  CCActionInterval *actionMoveTo = CCMoveTo::create(distance/speed,ccp(m_pBird->getPositionX(),0));

  m_pBird->runAction(CCSpawn::create(actionRotateTo,actionMoveTo,NULL));
}
