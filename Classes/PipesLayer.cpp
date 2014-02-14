#include "PipesLayer.h"
#define Pipe_Distance 360.0f
bool PipesLayer::init()
{
  if ( !CCLayer::init() )
  {
      return false;
  }
  CCSize winSize = CCDirector::sharedDirector()->getWinSize();

  float posX = winSize.width;
  for(int i=0;i<4;++i){
    
    float posY = CCRANDOM_0_1()*700 + 320;

    CCSprite *pPipeDown = CCSprite::createWithSpriteFrameName("holdback1.png");
    if(pPipeDown)

    pPipeDown->setAnchorPoint(ccp(0,1));
    
    pPipeDown->setPosition(ccp(posX,posY));

    addChild(pPipeDown);

    CCSprite *pPipeUp = CCSprite::createWithSpriteFrameName("holdback2.png");
    pPipeUp->setAnchorPoint(ccp(0,0));
    pPipeUp->setPosition(ccp(posX,posY+250));
    addChild(pPipeUp);

    posX += Pipe_Distance;
  }
  
  return true;

}

void PipesLayer::update(float delte)
{
  CCObject *pObject = NULL;
  CCArray * pArray = getChildren();
  for(int i=0;i<pArray->count();++i){
    CCSprite *pPipe = (CCSprite*)pArray->objectAtIndex(i);
    float pipeWidth = pPipe->getContentSize().width;
    float posX = pPipe->getPositionX();
    float posY = pPipe->getPositionY();
    if(posX<=-pipeWidth){
      posX = (Pipe_Distance-pipeWidth)*4 + pipeWidth*3;
      if(i==0 || i==2 || i==4 || i==6){
        m_posY = CCRANDOM_0_1()*700 + 320;
        posY = m_posY;
      }
      else
        posY = m_posY + 250;
    }
    float speed = 3.0f;

    posX -= speed;

    pPipe->setPosition(ccp(posX,posY));
  }


}

void PipesLayer::onGameStart()
{
  this->scheduleUpdate();
}
