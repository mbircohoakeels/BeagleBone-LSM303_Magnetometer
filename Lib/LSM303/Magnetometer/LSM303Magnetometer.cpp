//
// Created by Michael Brookes on 05/05/2016.
//

#include "LSM303Magnetometer.h"

LSM303Magnetometer::LSM303Magnetometer( unsigned char _DeviceAddress, int _BusId ) {
    this->SetDeviceAddress( _DeviceAddress );
    this->SetBusId( _BusId );
    this->InitI2C( );
    this->LoadRecommendedFlightSettings( );
    this->InitMagnetometer( );
}

double LSM303Magnetometer::Heading( ) {
    double x2 = 0, y2 = 0;

    double t_roll = this->X * this->X + this->Z * this->Z;
    float rollRadians = ( float )atan2( ( double )this->Y, sqrt( t_roll ) );

    double t_pitch = this->Y * this->Y + this->Z * this->Z;
    float pitchRadians = ( float )atan2( ( double )this->X, sqrt( t_pitch ) );

    float cosRoll = ( float ) cos( rollRadians );
    float sinRoll = ( float ) sin( rollRadians );

    float cosPitch = ( float ) cos( -1 * pitchRadians );
    float sinPitch = ( float ) sin( -1 * pitchRadians );

    x2 = ( this->X ) * cosPitch + ( this->Z ) * sinPitch;
    y2 = ( this->X ) * sinRoll * sinPitch + ( this->Y ) * cosRoll - ( this->Z ) * sinRoll * cosPitch;

    return ( atan2 ( x2, y2 ) * 180 ) / M_PI;
}