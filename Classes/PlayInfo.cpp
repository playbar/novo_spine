

#include "PlayInfo.h"

PlayInfo *PlayInfo::m_sInit = nullptr;

PlayInfo *PlayInfo::getInstance()
{
    if (m_sInit == nullptr) {
        m_sInit = new PlayInfo();
        if(!m_sInit->Init())
        {
            delete m_sInit;
            m_sInit = nullptr;
        }
    }
    return m_sInit;
}

bool PlayInfo::Init(){
    return true;
}


