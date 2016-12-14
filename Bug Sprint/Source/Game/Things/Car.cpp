//
//  Car.cpp
//  Bug Sprint
//
//  Created by Rafal Grodzinski on 13/12/2016.
//  Copyright © 2016 UnalignedByte. All rights reserved.
//

#include "Car.h"

#include <iostream>

using namespace std;


static GLfloat kAcceleration = 0.05;
static GLfloat kMaxSpeed = 1.0;
static GLfloat kSlowdownSpeed = 0.05;
static GLfloat kWheelsTurnSpeed = 0.5;
static GLfloat kMaxWheelsTurn = 5.0;


Car::Car()
{
    body = make_shared<Drawable>("Game/Things/car_body.obj");
    addChild(body);
}


void Car::update(float timeInterval)
{
    if(isAccelerating) {
        speed += kAcceleration;

        if(speed > kMaxSpeed)
            speed = kMaxSpeed;
    } else {
        if(speed > 0.0) {
            speed -= kSlowdownSpeed;

            if(speed < 0.0)
                speed = 0.0;
        } else if(speed < 0.0) {
            speed += kSlowdownSpeed;

            if(speed > 0.0)
                speed = 0.0;
        }
    }

    if(isTurningLeft) {
        wheelsTurn -= kWheelsTurnSpeed;
        if(wheelsTurn < -kMaxWheelsTurn)
            wheelsTurn = -kMaxWheelsTurn;
    } else if(isTurningRight) {
        wheelsTurn += kWheelsTurnSpeed;
        if(wheelsTurn > kMaxWheelsTurn)
            wheelsTurn = kMaxWheelsTurn;
    } else {
        if(wheelsTurn > 0.0) {
            wheelsTurn -= kWheelsTurnSpeed;
            if(wheelsTurn < 0.0)
                wheelsTurn = 0.0;
        } else if(wheelsTurn < 0.0) {
            wheelsTurn += kWheelsTurnSpeed;
            if(wheelsTurn > 0.0)
                wheelsTurn = 0.0;
        }
    }

    if(speed > 0.0) {
        rotation[1] += wheelsTurn;
    }

    GLfloat angleInRadians = (M_PI * rotation[1])/180.0;
    position[0] += speed * sin(angleInRadians);
    position[2] += speed * cos(angleInRadians);

    cout << "Speed: " << speed << endl << "Wheel Turn: " << wheelsTurn << endl;

    Instance3D::update(timeInterval);
}
