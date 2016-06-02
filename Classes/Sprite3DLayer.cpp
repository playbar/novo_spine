#include "Sprite3DLayer.h"
#include "spine/spine.h"
#include "base/ccMacros.h"
#include "VisibleRect.h"

USING_NS_CC;
using namespace spine;



// on "init" you need to initialize your instance
bool Sprite3DLayer::init()
{
    //////////////////////////////
 
	if (!Layer::init()){
		return false;
	}
    
	//initSprite3D();

    return true;
}


void Sprite3DLayer::addTortoise()
{
    auto s = Director::getInstance()->getWinSize();
    auto sprite1 = Sprite3D::create("Sprite3DTest/boss1.obj");
    sprite1->setScale(4.f);
    sprite1->setTexture("Sprite3DTest/boss.png");
    sprite1->setPosition(Vec2(s.width/2, s.height/2));
    addChild(sprite1);
    
    sprite1->runAction(RepeatForever::create(RotateBy::create(3, 360)));
    
    

}

//
//void Sprite3DLayer::addTortoise()
//{
//    std::string fileName = "Sprite3DTest/tortoise.c3b";
//    auto sprite = Sprite3D::create(fileName);
//    sprite->setScale(0.1f);
//    auto s = Director::getInstance()->getWinSize();
//    sprite->setPosition(Vec2(s.width * 4.f / 5.f, s.height / 2.f));
//    addChild(sprite);
//    _sprite = sprite;
//    auto animation = Animation3D::create(fileName);
//    if (animation)
//    {
//        auto animate = Animate3D::create(animation, 0.f, 1.933f);
//        //animate->setSpeed(10.0f);
//        _swim = RepeatForever::create(animate);
//        sprite->runAction(_swim);
//        
//        _swim->retain();
//        _hurt = Animate3D::create(animation, 1.933f, 2.8f);
//        _hurt->retain();
//    }
//    
//    _moveAction = MoveBy::create(4.f, Vec2( - s.width * 3.0f /5, 0));
//    
//    _moveAction->retain();
//    auto seq = Sequence::create(_moveAction, CallFunc::create(CC_CALLBACK_0(Sprite3DLayer::reachEndCallBack, this)), nullptr);
//    seq->setTag(100);
//    sprite->runAction(seq);
//}

void Sprite3DLayer::reachEndCallBack()
{
    _sprite->stopActionByTag(100);
    auto inverse = _moveAction->reverse();
    _moveAction->release();
    _moveAction = inverse;
    _moveAction->retain();
    
    auto rot = RotateBy::create(1.f, Vec3(0.f, 180.f, 0.f));
    auto seq = Sequence::create(rot, _moveAction, CallFunc::create(CC_CALLBACK_0(Sprite3DLayer::reachEndCallBack, this)), nullptr);
    seq->setTag(100);
    _sprite->runAction(seq);
}


void Sprite3DLayer::initSprite3D()
{
	auto s = Director::getInstance()->getWinSize();
	addNewSpriteWithCoords(Vec2(s.width / 2, 200));
    

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesEnded = CC_CALLBACK_2(Sprite3DLayer::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	TTFConfig ttfConfig("fonts/arial.ttf", 20);
	auto label1 = Label::createWithTTF(ttfConfig, "Hair");
	auto item1 = MenuItemLabel::create(label1, CC_CALLBACK_1(Sprite3DLayer::menuCallback_reSkin, this));
	auto label2 = Label::createWithTTF(ttfConfig, "Glasses");
	auto item2 = MenuItemLabel::create(label2, CC_CALLBACK_1(Sprite3DLayer::menuCallback_reSkin, this));
	auto label3 = Label::createWithTTF(ttfConfig, "Coat");
	auto item3 = MenuItemLabel::create(label3, CC_CALLBACK_1(Sprite3DLayer::menuCallback_reSkin, this));
	auto label4 = Label::createWithTTF(ttfConfig, "Pants");
	auto item4 = MenuItemLabel::create(label4, CC_CALLBACK_1(Sprite3DLayer::menuCallback_reSkin, this));
	auto label5 = Label::createWithTTF(ttfConfig, "Shoes");
	auto item5 = MenuItemLabel::create(label5, CC_CALLBACK_1(Sprite3DLayer::menuCallback_reSkin, this));
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
    
    //scheduleUpdate();
    return;
}

void Sprite3DLayer::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{

}

void Sprite3DLayer::addNewSpriteWithCoords(cocos2d::Vec2 p)
{
	std::string fileName = "Sprite3DTest/ReskinGirl.c3b";
    //std::string fileName = "Orangutan/Orangutan_FBX.c3b";
	auto sprite = Sprite3D::create(fileName);
	sprite->setScale(6);
	sprite->setRotation3D(Vec3(0, 0, 0));
	addChild(sprite, 1);
    //return;
	sprite->setPosition(Vec2(p.x, p.y - 100));
	auto animation = Animation3D::create(fileName);
	if (animation)
	{
		auto animate = Animate3D::create(animation);
		sprite->runAction(RepeatForever::create(animate));
        //sprite->runAction(shaky3D);
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

void Sprite3DLayer::menuCallback_reSkin(cocos2d::Ref* sender)
{
	long index = (long)(((MenuItemLabel*)sender)->getUserData());
	if (index < (int)SkinType::MAX_TYPE)
	{
		_curSkin[index] = (_curSkin[index] + 1) % _skins[index].size();
		applyCurSkin();
	}
}

void Sprite3DLayer::applyCurSkin()
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

void Sprite3DLayer::update(float delta)
{
    Layer::update(delta);
    //log("Sprite3DLayer::update");
}


void Sprite3DLayer::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



