#include <iostream>
#include <vector>
#include <cmath>
#include "cSpline.h"

using namespace std;

int main()
{
    float results[] =
    {

        100, 87.0446, 74.5714, 63.0625, 53, 44.8661, 39.1429, 36.3125, 36.8571, 41.2589,
 50, 23.3804, 0.971429, -17.8375, -33.6571, -47.0982, -58.7714, -69.2875, -79.2571, -89.2911,
  -100, -81.8661, -64.8571, -48.8125, -33.5714, -18.9732, -4.85714, 8.9375, 22.5714, 36.2054,
  50, 64.0839, 78.4571, 93.0875, 107.943, 122.991, 138.2, 153.538, 168.971, 184.47,
   200

    };

    vector< double > x { 0, 1, 2, 3, 4 };
    vector< double > y {  100, 50, -100, 50, 200 };

    raven::cSpline spline( x, y );

    for ( int i = 0; i < 41; i++ )
    {
//        cout << spline.getY( i / 10.0 ) << ", ";
//        cout << i / 10.0 <<" " << spline.getY( i / 10.0 ) << "\n ";
        if ( fabs( results[ i ] - spline.getY( i / 10.0 ) ) > 1.0 )
            cout << "failure " << i / 10.0 <<" " << results[i] <<" "<< spline.getY( i / 10.0 ) << endl;
    }

    return 0;
}
