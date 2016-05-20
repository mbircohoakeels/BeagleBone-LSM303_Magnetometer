//
// Created by Michael Brookes on 05/05/2016.
//

#ifndef LSM303_ACCELEROMETER_LSM303Magnetometer_H
#define LSM303_ACCELEROMETER_LSM303Magnetometer_H


#include "../LSM303DLHC.h"
#include <bitset>
#include <math.h>

using namespace std;

#define MAX_DATASTORE 15

class LSM303Magnetometer : public LSM303DLHC {

public:

    LSM303Magnetometer( unsigned char _DeviceAddress = MAG_ADDRESS, int _BusId = 1 );

    void SetHeadingAverages( int iterations = 50 );

    double Heading( );

    double avgHeading;

    double HeadingDataStoredValues[MAX_DATASTORE];

private:

    void StartRecordingHeading( );

    void AddToHeadingDataStore( );

    static void* GetMagnetometerValues(  void *_ACCEL  );

    pthread_t LSM303UpdateValuesThread;

};

#endif //LSM303_ACCELEROMETER_LSM303Magnetometer_H
