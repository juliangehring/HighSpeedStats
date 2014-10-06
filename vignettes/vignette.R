library(HighSpeedStats)

packageVersion("HighSpeedStats")

grid = read.delim("~/grid.tsv", header = FALSE)
names(grid) = c("a", "b", "c", "d")

grid[8000, ]

p1 = with(grid, feTestR(a, b, c, d))
p2 = with(grid, ultrafastfet(a, b, c, d))

median(p1)

median(p2)

pf = read.delim("~/pf.tsv", header = FALSE)$V1

median(pf)

dev.new(); plot(pf, p1, log = "xy", pch = ".", main = "j-pf vs. feTestR")
dev.new(); plot(pf, p2, log = "xy", pch = ".", main = "j-pf vs. ultrafastfet")

all.equal(p1, p2)
