#ifndef __LAYERMANAGER_H__
#define __LAYERMANAGER_H__

#include "set"
#include "string"
#include "cocos2d.h"

class LayerManager{

	enum EnLayerType{
		LAYER_TYPE_SKELETON = 1,
		LAYER_TYPE_PARTICLE = 2,
		LAYER_TYPE_SPRITE3D =3
	};
public:
	static int mzOrder;

public:
	LayerManager();

	bool addLayer(std::string strName, EnLayerType type );

	bool delLayer(std::string strName);

};


#endif

