#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp; //how far you are from center, how hard to steer
    this->Ki = Ki; //wheel alignment
    this->Kd = Kd; //trying not to oscillate so hard
    p_error = i_error = d_error = 0;
    
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error; //p_error is prev_cte at this point
    p_error = cte;
    i_error += cte;
    
    
}

double PID::TotalError() {
    return Kp*p_error + Ki*i_error + Kd*d_error;
}

