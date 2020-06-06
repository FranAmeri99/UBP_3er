#ifndef SIR_H
#define SIR_H

#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>

#include "admindb.h"
class sir
{
public:    
    const double b = 0.1;
    const double g = 0.05;
    int qw = 0;
    typedef boost::array< double , 3 > state_type;
    sir( AdminDB* OadminDB = nullptr );
    void write_sirrrr(const state_type &x , const double t );

    void sirrrr( const state_type &x , state_type &dxdt , double t );

};

#endif // SIR_H
