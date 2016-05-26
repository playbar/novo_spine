#include "LayerManager.h"
#include "SkeletonLayer.h"
#include "ParticleLayer.h"
#include "Sprite3DLayer.h"

USING_NS_CC;

static LayerManager *g_LayerManager = nullptr;

int LayerManager::mzOrder = 0;

LayerManager::LayerManager(){

}

LayerManager *LayerManager::getInstance(){
	if( nullptr == g_LayerManager ){
		g_LayerManager = new (std::nothrow) LayerManager();
		g_LayerManager->init();
	}
	return g_LayerManager;
}

bool LayerManager::addLayer(std::string strName, EnLayerType type )
{
	Layer *layer = nullptr;
	if( LAYER_TYPE_SKELETON == type ){
	    auto layerSk= SkeletonLayer::create();
	    layerSk->InitSkeleton("spine/fatfish.json", "spine/fatfish.atlas", 1.0f);
	    layer = layerSk;
	}else if( LAYER_TYPE_PARTICLE == type ){
		  layer = ParticleLayer::create();
	}else if( LAYER_TYPE_SPRITE3D == type ){
		layer = Sprite3DLayer::create();
	}
	if( nullptr != layer ){
		++mzOrder;
		 Director::getInstance()->addLayer( layer, mzOrder, strName);
		 return true;
	}
	else{
		return false;
	}
}

bool LayerManager::delLayer(std::string strName)
{
	Director::getInstance()->delLayer( strName );
	--mzOrder;
	return false;
}

