#ifndef __PIPES_LAYER_H__
#define __PIPES_LAYER_H__

#include "cocos2d.h"

using namespace cocos2d;
class PipesLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(PipesLayer);
    virtual void update(float delte);
    void onGameStart();
private:
    float m_posY;
};

#endif // __PIPES_LAYER_H__