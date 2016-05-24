#include "NovoScene.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "PlayInfo.h"
#include "NovoLayer.h"

USING_NS_CC;
using namespace spine;

Scene* NovoScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = NovoScene::create();
    
    // 'layer' is an autorelease object
    auto layer = NovoLayer::create();
    

    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool NovoScene::init()
{
    if( !Scene::init()){
        return false;
    }
    return true;
}
