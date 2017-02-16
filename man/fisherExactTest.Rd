\name{fisherExactTest}

\alias{fisherExactTest}      
\alias{ultrafastfet}
\alias{feTestR}

\title{Fast Fisher's Exact Test}

\description{

  Fast implementations of the two-sided Fisher's Exact Test (FET) which
  return the p-values.  Different versions offer a efficient computation
  for large data sets.

}

\usage{

fisherExactTest(a, b, c, d)

ultrafastfet(a, b, c, d)

feTestR(a, b, c, d, relErr = 1 + 1e-07)

}

\arguments{

  \item{a, b, c, d}{Counts of contingency matrix}

  \item{relErr}{Relative error term, as found in the base R implementation}

}

\details{
  
  A set of different implementations for computing two-sided p-values
  with Fisher's Exact Test:

  The 'fisherExactTest' will return the same p-values as the
  'fisher.test' function that comes with R.  This version relies on the
  'boost' library, and becomes highly *in*efficient for sample sizes >
  170.

  The 'ultrafastfet' implementation offers a time and memory efficient
  computation of the p-values.

  Note that minor deviations in the p-values between the implementations
  due to rounding errors and methodological differences may occur.  They
  should not be of practical relevance.

  In comparison, 'ultrafastfet' can be more 20 times faster for large
  data sets than 'fisherExactTest' while having a smaller memory
  footprint.

  The 'feTestR' is the excerpt from the 'fisher.test' function that
  returns only the two-sided p-values (taken from the 'VariantTools'
  package).

  Please note that these implementations focus on computing two-sided
  p-values; in contrast, one-sided p-values can be efficiently obtained
  with 'phyper' in the 'stats' package.
}

\seealso{

  fisher.test

  VariantTools:::fisher_p

  stats::phyper for one-sided p-values

}

\value{

  Numeric vector with p-values

}

\references{
  
  feTestR: 

  fisherExactTest: 

  ultrafastfet: \url{http://genome.sph.umich.edu/wiki/Biostatistics_615/815_Fall_2011}
 
}

\examples{

m = 2
g = expand.grid(a = 0:m, b = 0:m, c = 0:m, d = 0:m)

p0 = with(g, feTestR(a, b, c, d))

p1 = with(g, fisherExactTest(a, b, c, d))

p2 = with(g, ultrafastfet(a, b, c, d))

all.equal(p0, p1)

all.equal(p0, p2)

}
