//
//  CTriggeredRotation.cpp
//  FS2_Open
//
//  Created by Echelon9 on 25/09/12.
//
//

#include "CTriggeredRotation.h"

CTriggeredRotation::CTriggeredRotation()
{
    m_current_ang = vmd_zero_vector;
    m_current_vel = vmd_zero_vector;
    m_rot_accel   = vmd_zero_vector;
    m_rot_vel     = vmd_zero_vector;
    m_slow_angle  = vmd_zero_vector;
    m_start_angle = vmd_zero_vector;
    m_end_angle   = vmd_zero_vector;
    m_direction   = vmd_zero_vector;
}

CTriggeredRotation::~CTriggeredRotation()
{
    // TODO
}

void CTriggeredRotation::Start()
{
    // TODO
}

void CTriggeredRotation::SetToInitial()
{
    m_current_ang = m_start_angle;
}

void CTriggeredRotation::SetToFinal()
{
    m_current_ang = m_end_angle;
}

/**
 * @brief Finds the actual amount of time that motion of an animation type will take to stop,
 * not for gameplay purposes but for stuff that is involved in coordinating the animation itself.
 *
 * @details The time it takes to speed up or slow down is v/a in this time the animation covers
 * an angle = to (v^2)/(2a) (for both directions so v^2/a) so we need the time it takes for the
 * angle moving at a constant velosity to cover theda - v^2/a
 * v*t = theda - (v^2)/(2*a) => t = -(v^2 - 2*a*theda)/(2*a*v)
 * so finally v/a * 2 - (v^2 - 2*a*theda)/(2*a*v) => (3*v^2 + 2*a*theda)/(2*a*v)
 * time = (3*v^2 + 2*a*theda)/(2*a*v)
 */
size_t CTriggeredRotation::GetTimeToFinal()
{
    size_t ret = 0;
	size_t temp = 0;
    
	for (int axis = 0; axis < 3; axis++) {
		temp = fl2i( ((3.0f * m_current_vel.a1d[axis] * m_current_vel.a1d[axis]) + (2.0f * m_current_accel.a1d[axis] * fabs(m_current_ang.a1d[axis])))
                    / (2.0f * m_current_accel.a1d[axis] * m_current_vel.a1d[axis]) * 1000.0f )
        + m_start_time; // Not sure about this last m_start_time...
        
		if (temp > ret)
			ret = temp;
	}
    
	return ret;
}

void CTriggeredRotation::ApplyTriggerAngles(angles *submodel_angles)
{
    // TODO
}

