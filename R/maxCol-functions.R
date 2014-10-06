maxCol <- function(m) {
    .Call('HighSpeedStats_maxCol', PACKAGE = 'HighSpeedStats', m)
}


## maxCol reference implementation ##
maxColR <- function(m) {
    d1f = max.col(m, "first")
    d1l = max.col(m, "last")
    d1 = ifelse(d1f == d1l, d1f, 0L)
    return(d1)
}
