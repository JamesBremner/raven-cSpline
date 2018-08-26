#include <iostream>
#include <vector>
#include <cmath>
#include "cSpline.h"

using namespace std;

int main()
{
    float results[] =
    {

        100, 99.7732, 99.2571, 98.1625, 96.2, 93.0804, 88.5143, 82.2125, 73.8857, 63.2446,
        50, 34.0518, 16.0571, -3.1375, -22.6857, -41.7411, -59.4571, -74.9875, -87.4857,
        -96.1054, -100, -98.5804, -92.2857, -81.8125, -67.8571, -51.1161, -32.2857,
        -12.0625, 8.85714, 29.7768, 50, 68.9696, 86.6857, 103.287, 118.914, 133.705, 147.8,
        161.338, 174.457, 187.298, 200

    };

    vector< double > x { 0, 1, 2, 3, 4 };
    vector< double > y {  100, 50, -100, 50, 200 };

    raven::cSpline spline( x, y );

    for ( int i = 0; i < 41; i++ )
    {
        //cout << spline.getY( i / 10.0 ) << ", ";
        //cout << i / 10.0 <<" " << spline.getY( i / 10.0 ) << "\n ";
        if ( fabs( results[ i ] - spline.getY( i / 10.0 ) ) > 1.0 )
        {
            cout << "failure " << i / 10.0 <<" " << results[i] <<" "<< spline.getY( i / 10.0 ) << endl;
            return 1;
        }
    }

    vector< double > x2 { 0, 1, 3, 3, 4 };
    vector< double > y2 {  100, 50, -100, 50, 200 };
    raven::cSpline spline2( x2, y2 );
    if( raven::cSpline::not_single_valued != spline2.IsError()  )
    {
        cout << "failure: single valued test\n";
        return 2;
    }

    cout << "all unit tests passed\n";

    return 0;
}
