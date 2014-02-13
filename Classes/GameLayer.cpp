#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "GroundLayer.h"

using namespace CocosDenshion;

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
  if ( !CCLayer::init() )
  {
      return false;
  }
  m_bFirstTouch = true;
  CCSize winSize = CCDirector::sharedDirector()->getWinSize();
  
  CCSprite *pBg = CCSprite::create("bg.png");
  pBg->setPosition(ccp(winSize.width/2,winSize.height/2));
  addChild(pBg);
  
  GroundLayer *pGroundLayer = GroundLayer::create();
  addChild(pGroundLayer);
  
  CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
  
  cache->addSpriteFramesWithFile("flappy_packer.plist", "flappy_packer.png");
  
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
  
  CCSprite *pBird = CCSprite::createWithSpriteFrameName("bird1.png");
  pBird->setPosition(ccp(winSize.width/2,winSize.height/2));
  addChild(pBird);
  
  
  pBird->runAction(CCRepeatForever::create(CCSpawn::create(animate,(CCActionInterval*)action,NULL)));
  
  CCMenu * pMenu = CCMenu::create();
  pMenu->setPosition(ccp(0,0));
  pMenu->setAnchorPoint(ccp(0,0));
  addChild(pMenu);
    
  CCSprite * pNormal = CCSprite::createWithSpriteFrameName("start.png");
  CCMenuItemSprite * pItem = CCMenuItemSprite::create(pNormal, NULL, NULL, this, menu_selector(GameLayer::menuStartCallback));
  pItem->setVisible(false);
  pItem->setPosition(winSize.width/2, 350);
  pMenu->addChild(pItem);

  m_pHint = CCSprite::createWithSpriteFrameName("click.png");
  m_pHint->setPosition(ccp(winSize.width/2,winSize.height/2));
  addChild(m_pHint);

  setTouchEnabled(true);
  return true;

}

void GameLayer::menuStartCallback(CCObject* pSender)
{

}

void GameLayer::registerWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 100, true);
}

bool GameLayer::ccTouchBegan(CCTouch * pTouch,CCEvent * pEvent)
{
  if(m_bFirstTouch)
    onGameStart();
  else{
    
  }
  return true;
}

void GameLayer::onGameStart()
{
  m_bFirstTouch = false;
  m_pHint->setVisible(false);
  
}

