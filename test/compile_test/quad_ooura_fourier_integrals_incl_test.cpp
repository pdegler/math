//  Copyright Matt Borland 2021.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header
// #includes all the files that it needs to.
//
#include <boost/math/quadrature/ooura_fourier_integrals.hpp>
#ifndef _MSC_VER
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

template <typename Real>
void test() {
    auto f = [](Real x) { return x; };
    boost::math::quadrature::ooura_fourier_sin<Real> sin_integrator;
    boost::math::quadrature::ooura_fourier_cos<Real> cos_integrator;
    check_result<std::pair<Real, Real>>(sin_integrator.integrate(f, 1.0));
    check_result<std::pair<Real, Real>>(cos_integrator.integrate(f, 1.0));
}

void compile_and_link_test()
{
    test<float>();
    #ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
    test<double>();
    #endif
}
#endif
