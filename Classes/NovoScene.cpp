#include "NovoScene.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "PlayInfo.h"
#include "NovoLayer.h"
#include "ParticleLayer.h"
#include "Sprite3DLayer.h"

USING_NS_CC;
using namespace spine;

Scene* NovoScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = NovoScene::create();
    
    // 'layer' is an autorelease object
    auto layer = NovoLayer::create();
    
    auto parLayer = ParticleLayer::create();
    auto sprintLayer = Sprite3DLayer::create();
    // add layer as a child to scene
    scene->addChild(layer);
    scene->addChild(parLayer);
    scene->addChild(sprintLayer);
    
    
    // return the scene
    return scene;
}

NovoScene::NovoScene(){
    
}

bool NovoScene::init()
{
    if( !Scene::init()){
        return false;
    }
    return true;
}
