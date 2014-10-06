\name{maxCol}
    
\alias{maxCol}
\alias{maxColR}

\title{Find Maximum Position in Matrix}

\description{

  Get the index of the maximun value in each row.
  
}

\usage{

maxCol(m)

maxColR(m)

}

\arguments{

  \item{m}{Numeric or integer matrix}

}

\details{

  'maxCol' is optimized and written in C++.

  'maxColR' is the reference implementation in R and way slower.

}

\value{

  A vector of length 'nrow(m)', where each element indicates the
  position of the maximum in the row.  In the case of a tie, 0 is
  returned for this row.

}

\seealso{

  'max.col'

  deepSNV::consensusSequence for a use case

}

\examples{

m = matrix(1:15, 5, byrow = TRUE)

idx = maxCol(m)

idx2 = maxColR(m)

}
