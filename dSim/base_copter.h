//
//  base_copter.h
//  dSim
//
//  Created by Hao Xu on 15/3/18.
//  Copyright (c) 2015年 xuhao. All rights reserved.
//

#ifndef __dSim__base_copter__
#define __dSim__base_copter__

#include <stdio.h>
#include "motor.h"
#include <vector>
#include "phys_model.h"
#include "PhysEngine.h"


///\brief the base class of copters

class base_copter:public xmodel
{
protected:
    ///> motors of the copter
    std::vector<motor> motors;
    
    ///> mass of the copter
    double mass;
    ///> Ixx of the copter
    double Ixx ;
    ///> Iyy of the copter
    double Iyy ;
    ///> Izz of the copter
    double Izz ;
    
    ///> force now
    vector3f force,
    ///> torque now
    torque;
public:
    
    ///\brief build a copter with default values
    base_copter(PhysEngine* pe):
        motors(4),xmodel(pe->mPhysics,pe->mScene,1.2)
    {
        actor->setRigidBodyFlag(PxRigidBodyFlag::eENABLE_CCD, true);
        init_default_quad();
        pe->add(this);
    }
    
    
    ///\brief set up with default values
    void init_default_quad();
    
    ///\brief calcute and set into physics model
    void calc();
    
    ///\brief test throttle
    void set_servo();
    
    ///\brief run
    //@overload
    virtual void run(float dt) override;
    
    //yaw con rate
    double set_yaw_con = 0;
    
    //roll con rate
    double set_roll_con = 0;
    
    //pitch con rate
    double set_pitch_con = 0;
    
    
    virtual void control();
    
};

#endif /* defined(__dSim__base_copter__) */
