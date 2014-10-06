fisherExactTest <- function(a, b, c, d) {
    .Call('HighSpeedStats_fisherExactTest', PACKAGE = 'HighSpeedStats', a, b, c, d)
}


.fastfet <- function(a, b, c, d) {
    .Call('HighSpeedStats_fastfet', PACKAGE = 'HighSpeedStats', a, b, c, d)
}


ultrafastfet <- function(a, b, c, d) {
    .Call('HighSpeedStats_ultrafastfet', PACKAGE = 'HighSpeedStats', a, b, c, d)
}


.jltrafastfet <- function(a, b, c, d) {
    .Call('HighSpeedStats_jltrafastfet', PACKAGE = 'HighSpeedStats', a, b, c, d)
}


feTestR <- function (a, b, c, d, relErr = 1 + 1e-07)  {

    pval = mapply(function(x1, x2, n1, n2) {
        k = x1 + x2
        lo = max(0, k - n2)
        hi = min(k, n1)
        support = lo:hi
        d = dhyper(support, n1, n2, k, log = TRUE)
        d = exp(d - max(d))
        d = d/sum(d)
        sum(d[d <= d[x1 - lo + 1] * relErr])
    }, a, b, a + c, b + d)

    return(pval)
}
