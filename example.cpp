/*
Copyright (C) 2016 Michael Brookes

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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