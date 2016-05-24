#include "NovoScene.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "PlayInfo.h"
#include "SkeletonLayer.h"
#include "ParticleLayer.h"
#include "Sprite3DLayer.h"

USING_NS_CC;
using namespace spine;

Scene* NovoScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = NovoScene::create();
    
    // 'layer' is an autorelease object
    auto layerfish = SkeletonLayer::create();
    layerfish->InitSkeleton("spine/fish.json", "spine/fish.atlas", 1.0f);
    
    auto layerIsland = SkeletonLayer::create();
    layerIsland->InitSkeleton("spine/island.json", "spine/island.atlas", 1.0f);

    
    //auto parLayer = ParticleLayer::create();
    //auto sprintLayer = Sprite3DLayer::create();
    // add layer as a child to scene
    scene->addChild(layerfish);
    scene->addChild(layerIsland);
    layerIsland->setPosition(400, 300);
    layerfish->setPosition(400, 200);
    //scene->addChild(parLayer);
    //scene->addChild(sprintLayer);
    
    
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
