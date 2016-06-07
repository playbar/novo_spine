#include "ParticleLayer.h"
#include "spine/spine.h"
#include "base/ccMacros.h"

USING_NS_CC;
using namespace spine;



// on "init" you need to initialize your instance
bool ParticleLayer::init()
{
    //////////////////////////////
 
	if (!Layer::init()){
		return false;
	}

    
    //scheduleUpdate();

    return true;
}




void ParticleLayer::TestParticle()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    _emitter = ParticleSystemQuad::create("Particles/Flower.plist");
    _emitter->setPosition(400, 200);
    //_emitter->setScale( 0.5);
    _emitter->retain();
    addChild(_emitter, 10);
}

void ParticleLayer::TestParticle1()
{
    auto _emitter = ParticleSystemQuad::createWithTotalParticles(50);
    addChild(_emitter, 10);
    _emitter->setTexture(Director::getInstance()->getTextureCache()->addImage("CloseNormal.png"));
    _emitter->setAnchorPoint(Point(0, 0));
    
    // duration
    _emitter->setDuration(ParticleSystem::DURATION_INFINITY);
    
    // radius mode
    _emitter->setEmitterMode(ParticleSystem::Mode::RADIUS);
    
    // radius mode: start and end radius in pixels
    _emitter->setStartRadius(4);
    _emitter->setStartRadiusVar(1);
    _emitter->setEndRadius(ParticleSystem::START_RADIUS_EQUAL_TO_END_RADIUS);
    _emitter->setEndRadiusVar(0);
    
    // radius mode: degrees per second
    _emitter->setRotatePerSecond(100);
    _emitter->setRotatePerSecondVar(0);
    
    // angle
    _emitter->setAngle(90);
    _emitter->setAngleVar(0);
    
    // emitter position
    auto size = Director::getInstance()->getWinSize();
    _emitter->setPosVar(Point::ZERO);
    
    // lift of particles
    _emitter->setLife(0.5);
    _emitter->setLifeVar(0);
    
    // spin of particles
    _emitter->setStartSpin(0);
    _emitter->setStartSpinVar(0);
    _emitter->setEndSpin(0);
    _emitter->setEndSpinVar(0);
    
    // color of particles
    Color4F startColor(0.0f, 0.8f, 0.9f, 1.0f);
    _emitter->setStartColor(startColor);
    
    Color4F startColorVar(0, 0, 0, 1.0f);
    _emitter->setStartColorVar(startColorVar);
    
    
    Color4F endColor(1.0f, 1.0f, 1.0f, 0.1f);
    _emitter->setEndColor(endColor);
    
    Color4F endColorVar(0, 0, 0, 0.1f);
    _emitter->setEndColorVar(endColorVar);
    
    
    // size, in pixels
    _emitter->setStartSize(20);
    _emitter->setStartSizeVar(1);
    _emitter->setEndSize(0);
    
    // emits per second
    _emitter->setEmissionRate(_emitter->getTotalParticles() / _emitter->getLife());
    
    // additive
    _emitter->setBlendAdditive(false);
    
    //addChild
    _emitter->setPosition(Point(200, 200));
    
    
    
    return;
    
}

void ParticleLayer::update(float delta){
    Layer::update(delta);
    //log("ParticleLayer::update");
    
}


