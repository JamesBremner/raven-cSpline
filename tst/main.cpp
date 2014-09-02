#include <iostream>
#include <math.h>

#include "../cSpline.h"

using namespace std;

int main()
{
    std::vector< double > x;
    std::vector< double > y;
    for(int i = 0; i < 11; ++i)
    {
        x.push_back(i );
        y.push_back( sin(i) );
    }
    raven::cSpline spline(x,y);
    if( spline.IsError() )
    {
        cout << "Spline reports errors # " <<  spline.IsError() << endl;
        return 1;
    }

    if( fabs( spline.getY( 2.5 ) - sin( 2.5 ) ) > 0.01 )
    {
        cout << "Error at 2.5 " << spline.getY( 2.5 ) << " " << sin(2.5 ) << endl;
        return 1;
    }

    cout << "Tests OK" << endl;
    return 0;
}
