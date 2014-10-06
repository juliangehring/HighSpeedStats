#include <Rcpp.h>

using namespace Rcpp;

// maxCol
SEXP maxCol(SEXP m);
RcppExport SEXP HighSpeedStats_maxCol(SEXP mSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type m(mSEXP );
        SEXP __result = maxCol(m);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}


// fisherExactTest
SEXP fisherExactTest(SEXP a, SEXP b, SEXP c, SEXP d);
RcppExport SEXP HighSpeedStats_fisherExactTest(SEXP aSEXP, SEXP bSEXP, SEXP cSEXP, SEXP dSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type a(aSEXP );
        Rcpp::traits::input_parameter< SEXP >::type b(bSEXP );
        Rcpp::traits::input_parameter< SEXP >::type c(cSEXP );
        Rcpp::traits::input_parameter< SEXP >::type d(dSEXP );
        SEXP __result = fisherExactTest(a, b, c, d);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}


// fastfet
SEXP fastfet(SEXP a, SEXP b, SEXP c, SEXP d);
RcppExport SEXP HighSpeedStats_fastfet(SEXP aSEXP, SEXP bSEXP, SEXP cSEXP, SEXP dSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type a(aSEXP );
        Rcpp::traits::input_parameter< SEXP >::type b(bSEXP );
        Rcpp::traits::input_parameter< SEXP >::type c(cSEXP );
        Rcpp::traits::input_parameter< SEXP >::type d(dSEXP );
        SEXP __result = fastfet(a, b, c, d);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}


// ultrafastfet
SEXP ultrafastfet(SEXP a, SEXP b, SEXP c, SEXP d);
RcppExport SEXP HighSpeedStats_ultrafastfet(SEXP aSEXP, SEXP bSEXP, SEXP cSEXP, SEXP dSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type a(aSEXP );
        Rcpp::traits::input_parameter< SEXP >::type b(bSEXP );
        Rcpp::traits::input_parameter< SEXP >::type c(cSEXP );
        Rcpp::traits::input_parameter< SEXP >::type d(dSEXP );
        SEXP __result = ultrafastfet(a, b, c, d);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}


// jltrafastfet
SEXP jltrafastfet(SEXP a, SEXP b, SEXP c, SEXP d);
RcppExport SEXP HighSpeedStats_jltrafastfet(SEXP aSEXP, SEXP bSEXP, SEXP cSEXP, SEXP dSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type a(aSEXP );
        Rcpp::traits::input_parameter< SEXP >::type b(bSEXP );
        Rcpp::traits::input_parameter< SEXP >::type c(cSEXP );
        Rcpp::traits::input_parameter< SEXP >::type d(dSEXP );
        SEXP __result = jltrafastfet(a, b, c, d);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
