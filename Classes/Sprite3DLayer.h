#ifndef __SPRITE3DLAYER_H__
#define __SPRITE3DLAYER_H__

#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"

class Sprite3DLayer : public cocos2d::Layer
{


private:
	void initSprite3D();
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void addNewSpriteWithCoords(cocos2d::Vec2 p);
	void menuCallback_reSkin(cocos2d::Ref* sender);
	void applyCurSkin();

	enum class SkinType
	{
		UPPER_BODY = 0,
		PANTS,
		SHOES,
		HAIR,
		FACE,
		HAND,
		GLASSES,
		MAX_TYPE,
	};
	std::vector<std::string> _skins[(int)SkinType::MAX_TYPE]; //all skins
	int                      _curSkin[(int)SkinType::MAX_TYPE]; //current skin index
	cocos2d::Sprite3D* _sprite;

public:

    virtual bool init();
    
    virtual void update(float delta)override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Sprite3DLayer);
};

#endif //
