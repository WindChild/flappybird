#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GroundLayer.h"
#include "GameLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
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
    CCMenuItemSprite * pItem = CCMenuItemSprite::create(pNormal, NULL, NULL, this, menu_selector(HelloWorld::menuStartCallback));
    pItem->setPosition(winSize.width/2, 350);
    pMenu->addChild(pItem);

    cache->removeSpriteFrames();
    return true;

}

void HelloWorld::menuStartCallback(CCObject* pSender)
{
   CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
   removeAllChildrenWithCleanup(true);
}

