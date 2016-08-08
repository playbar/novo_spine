#include "NovoScene.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "SkeletonLayer.h"
#include "ParticleLayer.h"
#include "Sprite3DLayer.h"

USING_NS_CC;
using namespace spine;

void Testmap(){
    std::map<int, bool > datas;
    datas[1] = true;
    datas[2] = false;
    datas[3] = true;
    datas[4] = false;
    
    std::map<int, bool>::iterator iter = datas.begin();
    for (; iter != datas.end();) {
        if( iter->second )
            datas.erase(iter++);
        else{
            ++iter;
        }
    }
    return;
}

Scene* NovoScene::createScene()
{
    //Testmap();
    // 'scene' is an autorelease object
    auto scene = NovoScene::create();
    log("NovoScene::createScene");
    
    // 'layer' is an autorelease object
    auto layerfish = SkeletonLayer::create();
    //layerfish->InitSkeleton("spine/banana.json", "spine/banana.atlas", 1.0f);
    std::string name = "rose";
    layerfish->InitSkeleton(name);
    
    //auto layerIsland = SkeletonLayer::create();
    //layerIsland->InitSkeleton("spine/testMan.json", "spine/testMan.atlas", 1.0f);

    //auto parLayer = ParticleLayer::create();
    //parLayer->TestParticle1();
    //auto spriteLayer = Sprite3DLayer::create();
    //spriteLayer->addNewSpriteWithCoords();
    //spriteLayer->addTortoise();
    // add layer as a child to scene
    //scene->addChild(spriteLayer,1);
    scene->addChild(layerfish, 2, name);
    //scene->addChild(parLayer);

    //layerfish->mbUpdatepos = true;
    //layerfish->setPosition(400, 100);
    //scene->addChild(layerIsland, 3);
    //layerIsland->setPosition(400, 0);

   
    
    
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
    //scheduleUpdate();
    return true;
}

void NovoScene::update(float delta){
    Scene::update(delta);
    
}
