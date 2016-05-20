#include "Lib/LSM303/Magnetometer/LSM303Magnetometer.h"

using namespace std;

int main( ) {
    using namespace abI2C;

    LSM303Magnetometer *Magnetometer;

    Magnetometer = new LSM303Magnetometer( );

    Magnetometer->SetHeadingAverages( 50 );

    cout << "Averages : " << endl <<
    "    Heading = " << Magnetometer->avgHeading << endl;

    while( 1 ) {
        cout << "X = " << Magnetometer->X << " | Y = " << Magnetometer->Y << " | Z = " << Magnetometer->Z << endl;
        cout << "Heading = " << Magnetometer->Heading( ) << endl;
        usleep( Magnetometer->DataTimer );
    }
}