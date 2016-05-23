#ifndef __SKELETONINFO_H__
#define __SKELETONINFO_H__

#include "SkeletonInterface.h"
#include "SkeletonAbstract.h"

#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"


class SkeletonInfo : public SkeletonAbstract, public SkeletonInterface {
public:
    SkeletonInfo(cocos2d::Layer *layer);
    virtual void loadSkeletonFile() override;
    
private:
    cocos2d::Layer *mLayer;
    
};


#endif


