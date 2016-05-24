#ifndef __NONOSCENE_H__
#define __NONOSCENE_H__

#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"

class NovoScene : public cocos2d::Scene
{
private:
    NovoScene();
    virtual bool init();
    
public:
    static cocos2d::Scene* createScene();
    
    // implement the "static create()" method manually
    CREATE_FUNC(NovoScene);
};

#endif // __HELLOWORLD_SCENE_H__
