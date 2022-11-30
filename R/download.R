#' @useDynLib COMELN
#' @export
download <- function(a, b, c, d) {
  a_size <- nchar(a)
  b_size <- nchar(b)
  c_size <- nchar(c)
  d_size <- nchar(d)
  .Call("godownload",
        a, b, c, d,
        a_size, b_size, c_size, d_size,
        PACKAGE = "COMELN")
}