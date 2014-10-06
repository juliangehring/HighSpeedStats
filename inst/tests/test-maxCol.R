library(testthat)
library(HighSpeedStats)

context("maxCol")

test_that("'maxCol' and 'max.col' return the same without ties", {

    m = matrix(1:24, 6, byrow = TRUE)

    idx_old = max.col(m)
    idx_new = maxCol(m)
    
    expect_identical(idx_old, idx_new)

})


test_that("'maxCol' and 'maxColR' return the same with ties", {

    m = matrix(rbinom(1e6, 50, 0.5), ncol = 10)

    t_new = system.time(idx_new <- maxCol(m))
    t_old = system.time(idx_old <- maxColR(m))

    expect_identical(idx_old, idx_new)

    expect_less_than(t_new[3], t_old[3])

})
