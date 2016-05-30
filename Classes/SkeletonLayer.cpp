#include "SkeletonLayer.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "PlayInfo.h"
#include "json/document.h"

USING_NS_CC;
using namespace spine;



// on "init" you need to initialize your instance

SkeletonLayer::SkeletonLayer(){
    mbUpdatepos = false;
}


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
    
    skeletonNode->setEndListener([this](int trackIndex){
        int nHandle = 0;
        nHandle++;
        skeletonNode->stopAllActions();
        Director::getInstance()->delLayer(this);
        
    });
    
    skeletonNode->setCompleteListener([this](int trackInex, int loopCount){
        int nHandle = trackInex;
        nHandle++;
//        if( loopCount == 5 ){
//            skeletonNode->stopAllActions();
//            Director::getInstance()->pushDelLayer(this);
//        }
    });
    
	skeletonNode->setEventListener([](int trackIndex, spEvent* event) {
		log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
	});

	skeletonNode->setMix("walk", "jump", 0.2f);
	skeletonNode->setMix("jump", "run", 0.2f);
	skeletonNode->setAnimation(0, "animation", true );
	//skeletonNode->addAnimation(0, "jump", false, 3);
	//skeletonNode->addAnimation(0, "run", false);

    PlayInfo *pInfo = PlayInfo::getInstance();
	skeletonNode->setPosition(0, 0);

	addChild(skeletonNode, 2);
	scheduleUpdate();
    
    
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

//#define psln(x) std::cout << #x " = " << (x) << std::endl

void SkeletonLayer::InitSkeleton(const std::string& name) {

	using std::string;
	using std::ifstream;

	Data data = FileUtils::getInstance()->getDataFromFile(
				FileUtils::getInstance()->fullPathForFilename(name));

	using rapidjson::Document;
	Document doc;
	doc.Parse((char* )data.getBytes());
    //doc.Parse(json);
    if (doc.HasParseError()) {
        rapidjson::ParseErrorCode code = doc.GetParseError();
        log("%d", code );
        return;
    }
    using rapidjson::Value;
    Value & v = doc["ID"];
    if (v.IsString()) {
        log("%s", v.GetString());
    }
    Value &contents = doc["Skeleton"];
    if( contents.IsArray()){
        for( size_t i = 0; i < contents.Size(); ++i ){
            Value &v = contents[i];
            if( v.HasMember("file") && v["file"].IsString()){
                log("%s", v["file"].GetString());
            }
            if (v.HasMember("scale") && v["scale"].IsDouble()) {
                log("%f", v["scale"].GetDouble());
            }
            if(v.HasMember("posx") && v["posx"].IsInt()){
                log( "%d", v["posx"].GetInt());
            }
            if( v.HasMember("posy") && v["posy"].IsInt()){
                log("%d", v["posy"].GetInt());
            }
            //if()
            
        }
    }
    
    
    return;


//
//	// use values in parse result.
//	using rapidjson::Value;
//	Value & v = doc["dictVersion"];
//	if (v.IsInt()) {
//		psln(v.GetInt());
//	}
//
//	Value & contents = doc["content"];
//	if (contents.IsArray()) {
//		for (size_t i = 0; i < contents.Size(); ++i) {
//			Value & v = contents[i];
//			assert(v.IsObject());
//			if (v.HasMember("key") && v["key"].IsString()) {
//				psln(v["key"].GetString());
//			}
//			if (v.HasMember("value") && v["value"].IsString()) {
//				psln(v["value"].GetString());
//			}
//		}
//	}

}

void SkeletonLayer::update(float delta){
    Layer::update(delta);
    //log("delta: %f", delta );
    if( mbUpdatepos){
        static float posx = -200;
        posx += delta * 100;
        if( posx > 200 )
            posx = -200;
        skeletonNode->setPosition( posx, 0);
    }

}

void SkeletonLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
