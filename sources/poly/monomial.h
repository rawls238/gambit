//
// FILE: monomial.h -- Multivariate monomial class
//
// $Id$
//


#include "prepoly.h"


// This file provides the template class
//
//              gMono
//
// whose objects are monomials in several variables
// with coefficients of class T and nonnegative exponents. 
// This role of this class is to support the class gPoly. 


template<class T> class gMono {
private:
    T        coef;
    exp_vect exps;

public:
    // constructors
    gMono(const gSpace*, const T&);
    gMono(const T&, const exp_vect&);
    gMono(const gMono<T>&);
    ~gMono();

    // operators
          gMono<T>& operator =  (const gMono<T>&);

          bool      operator == (const gMono<T>&) const;
          bool      operator != (const gMono<T>&) const;
          gMono<T>  operator *  (const gMono<T>&) const;
          gMono<T>  operator /  (const gMono<T>&) const;
          gMono<T>  operator +  (const gMono<T>&) const; // assert exps ==
          gMono<T>& operator += (const gMono<T>&);       // assert exps ==
          gMono<T>& operator *= (const T&);      
          gMono<T>  operator -  ()                const; 

    // information
    const T &       Coef()                      const;
    int             Dmnsn()                     const;
    int             TotalDegree()               const;
    bool            IsConstant()                const;
    bool            IsMultiaffine()             const;
    const exp_vect& ExpV()                      const;
    T               Evaluate(const gArray<T>&)  const;
    T               Evaluate(const gVector<T>&) const;
};

template <class T> gOutput &operator<<(gOutput &, const gMono<T> &);




















