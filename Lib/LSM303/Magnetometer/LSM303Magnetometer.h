//
// Created by Michael Brookes on 05/05/2016.
//

#ifndef LSM303_ACCELEROMETER_LSM303Magnetometer_H
#define LSM303_ACCELEROMETER_LSM303Magnetometer_H


#include "../LSM303DLHC.h"
#include <bitset>
#include <math.h>

using namespace std;

class LSM303Magnetometer : public LSM303DLHC {

public:

    LSM303Magnetometer( unsigned char _DeviceAddress = MAG_ADDRESS, int _BusId = 1 );

    double Heading( );

private:

};

#endif //LSM303_ACCELEROMETER_LSM303Magnetometer_H
