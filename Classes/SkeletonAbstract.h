#ifndef __SKELETONABSTRACT_H__
#define __SKELETONABSTRACT_H__


#include "SkeletonInterface.h"

class SkeletonAbstract
{
public:
    SkeletonInterface *getSkeleton();
    void setSkeleton(SkeletonInterface *skeleton) {mInterface = skeleton;}
private:
    SkeletonInterface *mInterface;
    
};

#endif


