#ifndef __PLAYINFO_H__
#define __PALYINFO_H__


class PlayInfo{
public:
    static PlayInfo *getInstance();
    void setKeletonDataFile(std::string& str ){mSkeletonDataFile = str;}
    void setAtlasFile( std::string &str) { mAtlasFile = str;}
    void setKeletonDataFile(const char* str ){mSkeletonDataFile = str;}
    void setAtlasFile( const char* str) { mAtlasFile = str;}
    std::string& getAtlasFile(){ return mAtlasFile;}
    std::string& getSkeletonDataFile(){ return mSkeletonDataFile;}
private:
    static PlayInfo *m_sInit;
    PlayInfo(){};
    bool Init();
    
    std::string mSkeletonDataFile;
    std::string mAtlasFile;
    
};


#endif

