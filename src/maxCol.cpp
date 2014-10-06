#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP maxCol( SEXP m ) {

  Rcpp::NumericMatrix mm(m); 
  int nrow = mm.nrow();
  int ncol = mm.ncol();

  Rcpp::IntegerVector yy(nrow);
  
  for(int i = 0; i < nrow; i++) {
    int index = 0;
    bool dup = false;
    double current = mm(i,0);
    double max_value = current;
    for(int j = 1; j < ncol; j++) {
      current = mm(i,j);
      if(current == max_value) {
        dup = true;
      }
      if(current > max_value) {
        max_value = current;
        index = j;
        dup = false;
      }
    }
    index++; // convert to R index
    if(dup) {
      index = 0;
    }
    yy[i] = index;
  }
  
  return wrap(yy);
}
