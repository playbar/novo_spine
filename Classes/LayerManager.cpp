

#include "LayerManager.h"
#include "SkeletonLayer.h"
#include "ParticleLayer.h"
#include "Sprite3DLayer.h"

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
	auto layer = null;
	if( LAYER_TYPE_SKELETON == type ){
	    layer= SkeletonLayer::create();
	    layer->InitSkeleton("spine/fatfish.json", "spine/fatfish.atlas", 1.0f);
	}else if( LAYER_TYPE_PARTICLE == type ){
		  layer = ParticleLayer::create();
	}else if( LAYER_TYPE_SPRITE3D == tpye ){
		layer = Sprite3DLayer::create();
	}
	if( null != layer ){
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

