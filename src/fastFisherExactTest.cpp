#include <iostream>
#include <cmath>
#include <cstdlib>

#include <Rcpp.h>
using namespace Rcpp;


double logHypergeometricProb(double* logFacs , int a, int b, int c, int d) {
  return logFacs[a+b] + logFacs[c+d] + logFacs[a+c] + logFacs[b+d]
    - logFacs[a] - logFacs[b] - logFacs[c] - logFacs[d] - logFacs[a+b+c+d];
}


void initLogFacs(double* logFacs , int n) {
  logFacs[0] = 0;
  for(int i=1; i < n+1; ++i) {
    logFacs[i] = logFacs[i-1] + log((double)i); // only n times of log() calls
  }
}


double fet(int a, int b, int c, int d) {
  int n = a + b + c + d;
  double* logFacs = new double[n+1]; // *** dynamically allocate memory logFacs[0..n] ***
  initLogFacs(logFacs , n);
  // *** initialize logFacs array ***
  double logpCutoff = logHypergeometricProb(logFacs ,a,b,c,d); // *** logFacs added
  double pFraction = 0;
  for(int x=0; x <= n; ++x) {
    if ( a+b-x >= 0 && a+c-x >= 0 && d-a+x >=0 ) {
      double l = logHypergeometricProb(logFacs , x, a+b-x, a+c-x, d-a+x);
      if ( l <= logpCutoff ) pFraction += exp(l - logpCutoff); 
    }
  }
  double logpValue = logpCutoff + log(pFraction); // normalization: p_i = p_i / sum_i(p_i)
  delete [] logFacs;
  double pval = exp(logpValue);

  return pval;
}


// [[Rcpp::export]]
SEXP fastfet(SEXP a, SEXP b, SEXP c, SEXP d) {

  Rcpp::IntegerVector a_(a), b_(b), c_(c), d_(d);
  Rcpp::NumericVector pval(a);
  int n = a_.size();
 
  for(int i = 0; i < n; i++) {
    pval(i) = fet(a_(i), b_(i), c_(i), d_(i));
  }
  
  return wrap(pval);
}
