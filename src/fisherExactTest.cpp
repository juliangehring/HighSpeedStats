#include <boost/math/distributions/hypergeometric.hpp>
#include <algorithm> // for min and max
#include <Rcpp.h>

using namespace Rcpp;
using namespace boost::math;
using namespace std;

double fisher_exact_test(double a, double b, double c, double d) {
  double N = a + b + c + d;
  double r = a + c;
  double n = c + d;
  double max_for_k = min(r, n); 
  double min_for_k = (double)max(0.0, double(r + n - N));
  hypergeometric_distribution<> hgd(r, n, N); 
  double cutoff = pdf(hgd, c);
  double tmp_p = 0.0;
  for(int k = min_for_k; k < max_for_k+1; k++) {
    double p = pdf(hgd, k);
    if(p <= cutoff) {
      tmp_p += p;
    }
  }
  return tmp_p;
}

// [[Rcpp::export]]
SEXP fisherExactTest(SEXP a, SEXP b, SEXP c, SEXP d) {
  
  Rcpp::IntegerVector a_(a), b_(b), c_(c), d_(d);
  Rcpp::NumericVector pval(a);
  int n = a_.size();
  
  for(int i = 0; i < n; i++) {
    pval(i) = fisher_exact_test(a_(i), b_(i), c_(i), d_(i));
  }
  
  return wrap(pval);
}
