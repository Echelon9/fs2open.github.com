//
//  ITriggeredAnimation.h
//  FS2_Open
//
//  Created by Echelon9 on 25/09/12.
//
//

#ifndef FS2_Open_ITriggeredAnimation_h
#define FS2_Open_ITriggeredAnimation_h

#include "ship/ship.h"
#include "model/model.h"
#include "model/modelanim.h"
#include "io/timer.h"

/**
 * @page triggered_animation Component Triggered Animation
 *
 * This page gives a high-level description of ITriggeredAnimation.
 *
 * @section design Rough design notes
 *
 * Design notes to go here
 * - Further detail one 
 * - Further detail two
 */

/*
 * Implementation details:
 *
 * The current implementation has lots of nested virtual function calls,
 * to maximise flexibility. If this turns out to be too inefficient,
 * it'll need to be rewritten somehow with less virtuals (probably using
 * templates instead). (This is a more generic design than will be needed
 * in practice.)
 */

/**
 * Triggered animation interface.
 */
class ITriggeredAnimation
{
public:
    virtual ~ITriggeredAnimation();
    
    // Review each of these
    virtual void Start() = 0;
    virtual void SetToInitial() = 0;
    virtual void SetToFinal() = 0;
    
    virtual size_t GetTimeToFinal() const = 0;
    
    virtual void ApplyTriggerAngles(angles *submodel_angles) = 0;
    
protected:
    vec3d   m_current_vel;
    vec3d   m_current_accel;
    
    // Review each of these
    vec3d   m_snd_pnt;
    int     m_start_sound;
    int     m_loop_sound;
    int     m_end_sound;
    int     m_current_snd;
    int     m_current_snd_index;
    float   m_snd_rad;
    
    int     m_obj_num;
    
    int     m_instance;		// which animation this is (for reversals)
    bool    m_has_started;	// animation has started playing
    int     m_start_time;	// the time the current animation started
    int     m_end_time;		// time that we should stop
};

#endif
