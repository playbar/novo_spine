#ifndef __PLAYINFO_H__
#define __PALYINFO_H__

#include "set"
#include "string"

struct SkeletonNode{
    std::string mSkeletonDataFile;
    std::string mAtlasFile;
    
    float mposx;
    float mposy;
    std::set<std::string, bool> mAnimation;
    std::set<std::string, std::string>mMix;
    
};

class PlayInfo{
public:
    static PlayInfo *getInstance();
    void setKeletonDataFile(std::string& str ){mSkeletonDataFile = str;}
    void setAtlasFile( std::string &str) { mAtlasFile = str;}
    void setKeletonDataFile(const char* str ){mSkeletonDataFile = str;}
    void setAtlasFile( const char* str) { mAtlasFile = str;}
    void setposx(float x){ mposx = x;}
    void setposy(float y){ mposy = y;}
    
    std::string& getAtlasFile(){ return mAtlasFile;}
    std::string& getSkeletonDataFile(){ return mSkeletonDataFile;}
    float getposx(){ return mposx;};
    float getposy(){return mposy;}
    
private:
    static PlayInfo *m_sInit;
    PlayInfo(){};
    bool Init();
    
    //std::vector<SkeletonNode> mSkeletonNode;
    
    std::string mSkeletonDataFile;
    std::string mAtlasFile;
    
    float mposx;
    float mposy;
    
    
};


#endif

