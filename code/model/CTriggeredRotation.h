//
//  CTriggeredRotation.h
//  FS2_Open
//
//  Created by Echelon9 on 25/09/12.
//
//

#ifndef FS2_Open_CTriggeredRotation_h
#define FS2_Open_CTriggeredRotation_h

#include "ITriggeredAnimation.h"

class CTriggeredRotation : public ITriggeredAnimation
{
public:
    CTriggeredRotation();
    virtual ~CTriggeredRotation();
    
    // Review each of these
    virtual void Start();
    virtual void SetToInitial();
    virtual void SetToFinal();
    
    virtual size_t GetTimeToFinal();
    
    virtual void ApplyTriggerAngles(angles *submodel_angles);
    
protected:
    
private:
    vec3d m_current_ang;
    
    vec3d m_rot_accel;	// rotational acceleration, 0 means instant
    vec3d m_rot_vel;		// radians per second, hold this speed when rot_accel has pushed it to this
    vec3d m_slow_angle;	// angle that we should start to slow down
    vec3d m_start_angle;	// lock it in
    vec3d m_end_angle;	// lock it in
    vec3d m_direction;
};

#endif
