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
    log("NovoScene::createScene");
    
    // 'layer' is an autorelease object
    auto layerfish = SkeletonLayer::create();
    layerfish->InitSkeleton("spine/fatfish.json", "spine/fatfish.atlas", 1.0f);
    //layerfish->InitSkeleton("novo_info.json");
    
    //auto layerIsland = SkeletonLayer::create();
    //layerIsland->InitSkeleton("spine/island.json", "spine/island.atlas", 1.0f);

    auto parLayer = ParticleLayer::create();
    auto sprintLayer = Sprite3DLayer::create();
    // add layer as a child to scene
    scene->addChild(sprintLayer);
    scene->addChild(layerfish, 4);
    layerfish->mbUpdatepos = true;
    layerfish->setPosition(400, 100);
    //scene->addChild(layerIsland, 3);
    //layerIsland->setPosition(400, 0);

    scene->addChild(parLayer);
    
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
