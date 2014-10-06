library(testthat)
library(HighSpeedStats)

context("fisherExactTest")

test_that("'fisherExactTest' returns the same as the stripped R implementation", {

    f = 3
    m = 12
    ## sample the parameter space
    ## m: maximum size that limit the parameter space to [0,m]
    ## n1, n2: size
    ## x1, x2: successes
    ## y1, y2: failures
    grid = expand.grid(x1 = 0:m, x2 = 0:m, y1 = 0:m, y2 = 0:m)

    t_old = system.time(p_old <- feTestR(grid$x1, grid$y1, grid$x2, grid$y2))
    t_new = system.time(p_new <- fisherExactTest(grid$x1, grid$y1, grid$x2, grid$y2))
    
    expect_equal(p_new, p_old)

    expect_less_than(t_new[3] * f, t_old[3]) ## at least 'f' times faster
})


test_that("'ultrafastfet' returns the same as the stripped R implementation", {

    f = 10
    m = 12
    ## sample the parameter space
    ## m: maximum size that limit the parameter space to [0,m]
    ## n1, n2: size
    ## x1, x2: successes
    ## y1, y2: failures
    grid = expand.grid(x1 = 0:m, x2 = 0:m, y1 = 0:m, y2 = 0:m)

    t_old = system.time(p_old <- feTestR(grid$x1, grid$y1, grid$x2, grid$y2))
    t_new = system.time(p_new <- ultrafastfet(grid$x1, grid$y1, grid$x2, grid$y2))
    
    expect_equal(p_new, p_old)

    expect_less_than(t_new[3] * f, t_old[3]) ## at least 'f' times faster
})


context("fisherExactTest bugs")

test_that("'ultrafastfet' does not change the input arguments", {

    grid = data.frame(a = 2, b = 6, c = 8, d = 10)
    a = grid$a
    b = grid$b
    c = grid$c
    d = grid$d
    
    p <- ultrafastfet(a, b, c, d)

    expect_equal(grid$a, a)
    expect_equal(grid$b, b)
    expect_equal(grid$c, c)
    expect_equal(grid$d, d)

})
