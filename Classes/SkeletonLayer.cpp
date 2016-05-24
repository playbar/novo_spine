#include "SkeletonLayer.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "PlayInfo.h"

USING_NS_CC;
using namespace spine;



// on "init" you need to initialize your instance
bool SkeletonLayer::init()
{
    //////////////////////////////
 
	if (!Layer::init()){
		return false;
	}
    
    return true;
}


void SkeletonLayer::InitSkeleton(const std::string& skeletonDataFile, const std::string& atlasFile, float scale)
{
	//skeletonNode = SkeletonAnimation::createWithFile("spine/ship.json", "spine/ship.atlas", 1.0f);
	skeletonNode = SkeletonAnimation::createWithFile(skeletonDataFile, atlasFile, scale);
	skeletonNode->setScale(0.5f);

	skeletonNode->setStartListener([this](int trackIndex) {
		spTrackEntry* entry = spAnimationState_getCurrent(skeletonNode->getState(), trackIndex);
		const char* animationName = (entry && entry->animation) ? entry->animation->name : 0;
		log("%d start: %s", trackIndex, animationName);
	});
	skeletonNode->setEndListener([](int trackIndex) {
		log("%d end", trackIndex);
	});
	skeletonNode->setCompleteListener([](int trackIndex, int loopCount) {
		log("%d complete: %d", trackIndex, loopCount);
	});
	skeletonNode->setEventListener([](int trackIndex, spEvent* event) {
		log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
	});

	skeletonNode->setMix("walk", "jump", 0.2f);
	skeletonNode->setMix("jump", "run", 0.2f);
	skeletonNode->setAnimation(0, "animation", true);
	skeletonNode->addAnimation(0, "jump", false, 3);
	skeletonNode->addAnimation(0, "run", false);

    PlayInfo *pInfo = PlayInfo::getInstance();
	skeletonNode->setPosition(0, 0);

	addChild(skeletonNode, 2);
	scheduleUpdate();
    

    skeletonNode->setEndListener([this](int trackIndex){
        int nHandle = 0;
        nHandle++;
        //Director::getInstance()->end();
        //unscheduleUpdate();
        skeletonNode->stopAllActions();
        //skeletonNode->removeAllChildren();
        
    });
    
    skeletonNode->setCompleteListener([this](int trackInex, int loopCount){
        int nHandle = trackInex;
        nHandle++;
    });
    
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* touch, Event* event) -> bool {
		if (!skeletonNode->getDebugBonesEnabled())
			skeletonNode->setDebugBonesEnabled(true);
		else if (skeletonNode->getTimeScale() == 1)
			skeletonNode->setTimeScale(0.3f);
		else
		{
			skeletonNode->setTimeScale(1);
			skeletonNode->setDebugBonesEnabled(false);
		}

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

//
//void NovoLayer::InitShapSkeleton()
//{
//	skeletonShip = SkeletonAnimation::createWithFile("spine/powerup.json", "spine/powerup.atlas", 0.6f);
//	//skeletonShip = SkeletonAnimation::createWithFile("D:/test/spine/ship.json", "D:/test/spine/ship.atlas", 0.6f);
//	skeletonShip->setScale(1);
//
//	skeletonShip->setStartListener([this](int trackIndex) {
//		spTrackEntry* entry = spAnimationState_getCurrent(skeletonShip->getState(), trackIndex);
//		const char* animationName = (entry && entry->animation) ? entry->animation->name : 0;
//		log("%d start: %s", trackIndex, animationName);
//	});
//	skeletonShip->setEndListener([](int trackIndex) {
//		log("%d end", trackIndex);
//	});
//	skeletonShip->setCompleteListener([](int trackIndex, int loopCount) {
//		log("%d complete: %d", trackIndex, loopCount);
//	});
//	skeletonShip->setEventListener([](int trackIndex, spEvent* event) {
//		log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
//	});
//
//	skeletonShip->setMix("walk", "jump", 0.2f);
//	skeletonShip->setMix("jump", "run", 0.2f);
//	skeletonShip->setAnimation(0, "animation", true);
//	spTrackEntry* jumpEntry = skeletonShip->addAnimation(0, "jump", false, 3);
//	skeletonShip->addAnimation(0, "run", true);
//
//	Size windowSize = Director::getInstance()->getWinSize();
//	skeletonShip->setPosition(Vec2(windowSize.width / 2, 40));
//
//	addChild(skeletonShip, 2);
//	scheduleUpdate();
//
//	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = [this](Touch* touch, Event* event) -> bool {
//		if (!skeletonShip->getDebugBonesEnabled())
//			skeletonShip->setDebugBonesEnabled(true);
//		else if (skeletonShip->getTimeScale() == 1)
//			skeletonShip->setTimeScale(0.3f);
//		else
//		{
//			skeletonShip->setTimeScale(1);
//			skeletonShip->setDebugBonesEnabled(false);
//		}
//
//		return true;
//	};
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//
//}

void SkeletonLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
