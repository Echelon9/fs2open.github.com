//
//  ITriggeredAnimation.cpp
//  FS2_Open
//
//  Created by Echelon9 on 25/09/12.
//
//

#include "ITriggeredAnimation.h"

ITriggeredAnimation::~ITriggeredAnimation()
{
    m_snd_pnt = vmd_zero_vector;
    
    m_instance = -1;
    m_has_started = false;
    m_start_time = 0;
    m_end_time = 0;
}
