#include <Rcpp.h>
#include <cmath>

using namespace Rcpp;

double ulogHypergeometricProb(double* logFacs, int a, int b, int c, int d) {
  return logFacs[a+b] + logFacs[c+d] + logFacs[a+c] + logFacs[b+d]
    - logFacs[a] - logFacs[b] - logFacs[c] - logFacs[d] - logFacs[a+b+c+d];
}


void uinitLogFacs(double* logFacs, int n) {
  logFacs[0] = 0;
  for(int i=1; i < n+1; ++i) {
    logFacs[i] = logFacs[i-1] + log((double)i);
  }
}


double ufet(int a, int b, int c, int d, int n, double* logFacs) {
  double f = 10000000;
  double logpCutoff = round(ulogHypergeometricProb(logFacs, a, b, c, d) * f) / f;
  double pFraction = 0;
  for(int x=0; x <= n; ++x) {
    if ( a+b-x >= 0 && a+c-x >= 0 && d-a+x >=0 ) {
      double l = round(ulogHypergeometricProb(logFacs, x, a+b-x, a+c-x, d-a+x) * f) / f;
      if ( l <= logpCutoff ) {
        pFraction += exp(l - logpCutoff);
      }
    }
  }
  double logpValue = logpCutoff + log(pFraction); // normalization: p_i = p_i / sum_i(p_i)
  double pval = exp(logpValue);
  pval = fmax(fmin(pval, 1.0), 0.0);

  return pval;
}


// [[Rcpp::export]]
SEXP ultrafastfet(SEXP a, SEXP b, SEXP c, SEXP d) {

  Rcpp::IntegerVector a_(a), b_(b), c_(c), d_(d);
  int n = a_.size();
  Rcpp::NumericVector pval(n);    

  Rcpp::IntegerVector m_ = a_ + b_ + c_ + d_;
  int m = max(m_);

  double* ulogFacs = new double[m+1];
  uinitLogFacs(ulogFacs, m);

  for(int i = 0; i < n; i++) {
    pval(i) = ufet(a_(i), b_(i), c_(i), d_(i), m_(i), ulogFacs);
  }

  delete [] ulogFacs;
  
  return wrap(pval);
}
