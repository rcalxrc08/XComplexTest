//
// Created by nico on 1/26/17.
//
#include "../Include/dcomplex.h"
//TODO Rifai le interazioni con gli adouble e acomplex
////Mixed Operators FRIEND

dcomplex operator+(Real c,const dcomplex& in)
{
    return in+c;
}
dcomplex operator-(Real c,const dcomplex& in)
{
    return -1.*(in-c);
}
dcomplex operator*(Real c,const dcomplex& in)
{
    return in*c;
}
dcomplex operator/(Real c,const dcomplex& in)
{
    dcomplex tmp=dcomplex(c);
    return tmp/in;
}

acomplex operator+(const AReal& c,const dcomplex& in)
{
    return in+c;
}
acomplex operator-(const AReal& c,const dcomplex& in)
{
    return -1.*(in-c);
}
acomplex operator*(const AReal& c,const dcomplex& in)
{
    return in*c;
}
acomplex operator/(const AReal& c,const dcomplex& in)
{
    acomplex tmp=acomplex(c,0.0);

    return tmp/in;
}
////Acomplex

acomplex dcomplex::operator+(const acomplex& cpx)
const{
    AReal r= (*this).getReal()+ cpx.getReal();
    AReal i= (*this).getImm()+ cpx.getImm();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator-(const acomplex& cpx)
const{
    AReal r= (*this).getReal()- cpx.getReal();
    AReal i= (*this).getImm()- cpx.getImm();
    acomplex outCpc=acomplex(r,i);

    return outCpc;
}
acomplex dcomplex::operator*(const acomplex& cpx)
const{
    AReal r= (*this).getReal()* cpx.getReal()- (*this).getImm()* cpx.getImm();
    AReal i= (*this).getImm()* cpx.getReal()+ (*this).getReal()* cpx.getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const acomplex& cpx)
const{
    AReal r= (*this).getReal()* cpx.getReal()+ (*this).getImm()* cpx.getImm();
    AReal i= (*this).getImm()* cpx.getReal()- (*this).getReal()* cpx.getImm();
    AReal Rho=cpx.getNormSqr();
    acomplex outCpx=acomplex(r/Rho,i/Rho);

    return outCpx;
}
////Adouble
acomplex dcomplex::operator+(const AReal& c)
const{
    AReal r= (*this).getReal()+c;
    AReal i= (*this).getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator-(const AReal& c)
const{
    AReal r= (*this).getReal()-c;
    AReal i= (*this).getImm();
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator*(const AReal& c)
const{
    AReal r= (*this).getReal()*c;
    AReal i= (*this).getImm()*c;
    acomplex outCpx=acomplex(r,i);

    return outCpx;
}
acomplex dcomplex::operator/(const AReal& c)
const{
    AReal tm=1./c;
    acomplex outCpx=(*this)*tm;
    return outCpx;
}

Real adtan2(Real y, Real x)
{
    Real out=(Real) 0.0;
    if(x<0.0&&y==0.0)
        out=(Real)M_PI;
    else if(x==0.0&&y==0.0)
        throw new std::runtime_error("atan2 is not defined in the origin") ;
    else if(x!=0.0&&y!=0.0)
    {
        out=2*atan(y/(sqrt(x*x+y*y)+x));
    }
    return out;
}