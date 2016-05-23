#include "NovoScene.h"
#include "SimpleAudioEngine.h"
#include "VisibleRect.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "des_lib.h"
#include "aes.h"
#include "PlayInfo.h"

USING_NS_CC;
using namespace spine;

Scene* NovoLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NovoLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NovoLayer::init()
{
    //////////////////////////////
 
	if (!Layer::init()){
		return false;
	}
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    auto label = Label::createWithTTF("spine test", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    PlayInfo *pInfo = PlayInfo::getInstance();

	InitSkeleton(pInfo->getSkeletonDataFile(), pInfo->getAtlasFile(), 1.0f);
    //TestAES();
    //TestCryption();
	//InitShapSkeleton();
	//TestParticle();

	//initSprite3D();

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);

    return true;
}

void NovoLayer::TestCryption(){
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename("spine/bei-des");
    //std::string decryPath = FileUtils::getInstance()->fullPathForFilename("spine/test.test");
//    std::string decryPath ="/Users/mac/Library/Developer/CoreSimulator/Devices/947A04EA-C7E5-454B-97CD-262848B70D87/data/Containers/Bundle/Application/D0C71562-6F40-4F8A-861F-9D2D81BBDDFC/novo_spine-mobile.app/spine/test.test";
    
    //DecryptionFile( fullpath.c_str(), "novo", decryPath.c_str() );
    
    FILE *file;
    file = fopen(fullpath.c_str(), "rb");
    fseek( file, 0, SEEK_END);
    uint32_t ilen = ftell(file);
    rewind( file);
    CSimpleBuffer inbuffer;
    CSimpleBuffer outbuffer;
    inbuffer.Extend(ilen);
    char temp[1000] = {0};
    fread( temp, ilen, 1, file);
    inbuffer.Write(temp, ilen);
    inbuffer.SetDatalen( ilen );
    //inbuffer.IncWriteOffset(ilen);
    fclose(file);
    CSimpleBuffer enBuffer;
    //Encryption( &inbuffer, "novo", &enBuffer);
    
    Decryption( &inbuffer, "novo", &outbuffer );
    
    
    
    return;

}

void NovoLayer::TestAES(){
    
    char temp[] = "test";
    char out1[20] = {0};
    char out2[20] ={0};
    char key[] = "novo";
    AES_KEY aes;
    if(AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)
    {
        return;
    }
    
    AES_encrypt((unsigned char*)temp, (unsigned char*)out1, &aes);
    
    AES_decrypt( (unsigned char*)out1, (unsigned char*)out2, &aes );
    return;
    
}

void NovoLayer::InitSkeleton(const std::string& skeletonDataFile, const std::string& atlasFile, float scale)
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
	spTrackEntry* jumpEntry = skeletonNode->addAnimation(0, "jump", false, 3);
	skeletonNode->addAnimation(0, "run", true);

	Size windowSize = Director::getInstance()->getWinSize();
	skeletonNode->setPosition(Vec2(windowSize.width / 2, 200));

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


void NovoLayer::InitShapSkeleton()
{
	skeletonShip = SkeletonAnimation::createWithFile("spine/powerup.json", "spine/powerup.atlas", 0.6f);
	//skeletonShip = SkeletonAnimation::createWithFile("D:/test/spine/ship.json", "D:/test/spine/ship.atlas", 0.6f);
	skeletonShip->setScale(1);

	skeletonShip->setStartListener([this](int trackIndex) {
		spTrackEntry* entry = spAnimationState_getCurrent(skeletonShip->getState(), trackIndex);
		const char* animationName = (entry && entry->animation) ? entry->animation->name : 0;
		log("%d start: %s", trackIndex, animationName);
	});
	skeletonShip->setEndListener([](int trackIndex) {
		log("%d end", trackIndex);
	});
	skeletonShip->setCompleteListener([](int trackIndex, int loopCount) {
		log("%d complete: %d", trackIndex, loopCount);
	});
	skeletonShip->setEventListener([](int trackIndex, spEvent* event) {
		log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
	});

	skeletonShip->setMix("walk", "jump", 0.2f);
	skeletonShip->setMix("jump", "run", 0.2f);
	skeletonShip->setAnimation(0, "animation", true);
	spTrackEntry* jumpEntry = skeletonShip->addAnimation(0, "jump", false, 3);
	skeletonShip->addAnimation(0, "run", true);

	Size windowSize = Director::getInstance()->getWinSize();
	skeletonShip->setPosition(Vec2(windowSize.width / 2, 40));

	addChild(skeletonShip, 2);
	scheduleUpdate();

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* touch, Event* event) -> bool {
		if (!skeletonShip->getDebugBonesEnabled())
			skeletonShip->setDebugBonesEnabled(true);
		else if (skeletonShip->getTimeScale() == 1)
			skeletonShip->setTimeScale(0.3f);
		else
		{
			skeletonShip->setTimeScale(1);
			skeletonShip->setDebugBonesEnabled(false);
		}

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void NovoLayer::TestParticle()
{
	_emitter = ParticleSystemQuad::create("Particles/SmallSun.plist");
	_emitter->setPosition(400, 200);
	_emitter->retain();
	addChild(_emitter, 10);
}

void NovoLayer::initSprite3D()
{
	auto s = Director::getInstance()->getWinSize();
	addNewSpriteWithCoords(Vec2(s.width / 2, s.height / 2));

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesEnded = CC_CALLBACK_2(NovoLayer::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	TTFConfig ttfConfig("fonts/arial.ttf", 20);
	auto label1 = Label::createWithTTF(ttfConfig, "Hair");
	auto item1 = MenuItemLabel::create(label1, CC_CALLBACK_1(NovoLayer::menuCallback_reSkin, this));
	auto label2 = Label::createWithTTF(ttfConfig, "Glasses");
	auto item2 = MenuItemLabel::create(label2, CC_CALLBACK_1(NovoLayer::menuCallback_reSkin, this));
	auto label3 = Label::createWithTTF(ttfConfig, "Coat");
	auto item3 = MenuItemLabel::create(label3, CC_CALLBACK_1(NovoLayer::menuCallback_reSkin, this));
	auto label4 = Label::createWithTTF(ttfConfig, "Pants");
	auto item4 = MenuItemLabel::create(label4, CC_CALLBACK_1(NovoLayer::menuCallback_reSkin, this));
	auto label5 = Label::createWithTTF(ttfConfig, "Shoes");
	auto item5 = MenuItemLabel::create(label5, CC_CALLBACK_1(NovoLayer::menuCallback_reSkin, this));
	item1->setPosition(Vec2(VisibleRect::left().x + 50, VisibleRect::bottom().y + item1->getContentSize().height * 4));
	item2->setPosition(Vec2(VisibleRect::left().x + 50, VisibleRect::bottom().y + item1->getContentSize().height * 5));
	item3->setPosition(Vec2(VisibleRect::left().x + 50, VisibleRect::bottom().y + item1->getContentSize().height * 6));
	item4->setPosition(Vec2(VisibleRect::left().x + 50, VisibleRect::bottom().y + item1->getContentSize().height * 7));
	item5->setPosition(Vec2(VisibleRect::left().x + 50, VisibleRect::bottom().y + item1->getContentSize().height * 8));
	item1->setUserData((void*)SkinType::HAIR);
	item2->setUserData((void*)SkinType::GLASSES);
	item3->setUserData((void*)SkinType::UPPER_BODY);
	item4->setUserData((void*)SkinType::PANTS);
	item5->setUserData((void*)SkinType::SHOES);
	auto pMenu1 = Menu::create(item1, item2, item3, item4, item5, nullptr);
	pMenu1->setPosition(Vec2(0, 0));
	this->addChild(pMenu1, 3);
}

void NovoLayer::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{

}

void NovoLayer::addNewSpriteWithCoords(cocos2d::Vec2 p)
{
	std::string fileName = "Sprite3DTest/ReskinGirl.c3b";
	auto sprite = Sprite3D::create(fileName);
	sprite->setScale(6);
	sprite->setRotation3D(Vec3(0, 0, 0));
	addChild(sprite, 1);
	sprite->setPosition(Vec2(p.x, p.y - 100));
	auto animation = Animation3D::create(fileName);
	if (animation)
	{
		auto animate = Animate3D::create(animation);

		sprite->runAction(RepeatForever::create(animate));
	}
	_sprite = sprite;

	auto& body = _skins[(int)SkinType::UPPER_BODY];
	body.push_back("Girl_UpperBody01");
	body.push_back("Girl_UpperBody02");

	auto& pants = _skins[(int)SkinType::PANTS];
	pants.push_back("Girl_LowerBody01");
	pants.push_back("Girl_LowerBody02");

	auto& shoes = _skins[(int)SkinType::SHOES];
	shoes.push_back("Girl_Shoes01");
	shoes.push_back("Girl_Shoes02");

	auto& hair = _skins[(int)SkinType::HAIR];
	hair.push_back("Girl_Hair01");
	hair.push_back("Girl_Hair02");

	auto& face = _skins[(int)SkinType::FACE];
	face.push_back("Girl_Face01");
	face.push_back("Girl_Face02");

	auto& hand = _skins[(int)SkinType::HAND];
	hand.push_back("Girl_Hand01");
	hand.push_back("Girl_Hand02");

	auto& glasses = _skins[(int)SkinType::GLASSES];
	glasses.push_back("");
	glasses.push_back("Girl_Glasses01");

	memset(_curSkin, 0, (int)SkinType::MAX_TYPE * sizeof(int));

	applyCurSkin();
}

void NovoLayer::menuCallback_reSkin(cocos2d::Ref* sender)
{
	long index = (long)(((MenuItemLabel*)sender)->getUserData());
	if (index < (int)SkinType::MAX_TYPE)
	{
		_curSkin[index] = (_curSkin[index] + 1) % _skins[index].size();
		applyCurSkin();
	}
}

void NovoLayer::applyCurSkin()
{
	for (ssize_t i = 0; i < _sprite->getMeshCount(); i++) {
		auto mesh = _sprite->getMeshByIndex(static_cast<int>(i));
		bool isVisible = false;
		for (int j = 0; j < (int)SkinType::MAX_TYPE; j++) {
			if (mesh->getName() == _skins[j].at(_curSkin[j]))
			{
				isVisible = true;
				break;
			}
		}
		_sprite->getMeshByIndex(static_cast<int>(i))->setVisible(isVisible);
	}
}


void NovoLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
