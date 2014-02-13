#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

using namespace cocos2d;
class GameLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    

    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);
    void registerWithTouchDispatcher(void);
    
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
private:
  CCSprite *m_pHint;
  bool m_bFirstTouch;
  
  void menuStartCallback(CCObject* pSender);
  void onGameStart();
};

#endif // __GAME_LAYER_H__
