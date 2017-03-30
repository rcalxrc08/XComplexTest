//
// Created by nico on 1/18/17.
//

#ifndef TESI_AATAN2_H
#define TESI_AATAN2_H

#include <math.h>
#include <stdexcept>
#include "../../Adept/adept.h"

typedef double Real;
typedef adept::adouble AReal;

double adtan2(double y, double x);
adept::adouble adtan2(adept::adouble y, adept::adouble x);
#endif //TESI_AATAN2_H
