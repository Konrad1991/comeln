#include <R.h>
#include <Rinternals.h>
#include "_cgo_export.h"

// make go string
GoString mgs(char* p, int size) {
  GoString gs;
  gs.p = p;
  gs.n = size;
  return gs;
}

char* fill_char(SEXP size, SEXP string, SEXP source) {
  int* size_p = INTEGER(size);
  int size_ = size_p[0];
  char* p = (char*)malloc(sizeof(char) * size_);

  const char* p_sexp = CHAR(STRING_ELT(source, 0));
  for(int i = 0; i < size; i++) {
    p[i] = p_sexp[i];
  }

  return p;
}

SEXP godownload(SEXP token, SEXP urlinp, SEXP filename, SEXP path,
                SEXP token_size, SEXP urlinp_size, SEXP filename_size, SEXP path_size) {
  
  int* token_size_p = INTEGER(token_size);
  int* urlinp_size_p = INTEGER(urlinp_size);
  int* filename_size_p = INTEGER(filename_size);
  int* path_size_p = INTEGER(path_size);
  int token_size_int = token_size_p[0];
  int urlinp_size_int = urlinp_size_p[0];
  int filename_size_int = filename_size_p[0];
  int path_size_int = path_size_p[0];
  char* token_char = (char*)malloc(sizeof(char) * token_size_int);
  char* urlinp_char = (char*)malloc(sizeof(char) * urlinp_size_int);
  char* filename_char = (char*)malloc(sizeof(char) * filename_size_int);
  char* path_char = (char*)malloc(sizeof(char) * path_size_int);


  fill_char(token_char, token_size_int, token);
  fill_char(urlinp_char, urlinp_size_int, urlinp);
  fill_char(filename_char, filename_size_int, filename);
  fill_char(path_char, path_size_int, path);

  GoString token_ = mgs(token_char, token_size_int);
  GoString urlinp_ = mgs(urlinp_char, urlinp_size_int);
  GoString filename_ = mgs(filename_char, filename_size_int);
  GoString path_ = mgs(path_char, path_size_int);

  int ret = DownloadIt( token_, urlinp_, filename_, path_);

  free(token_char);
  free(urlinp_char);
  free(filename_char);
  free(path_char);
  
  return Rf_ScalarInteger( ret );
}

/*
SEXP goupload_to_eln(SEXP token, SEXP urlinp, SEXP filename, SEXP id, SEXP type_ ,
                     SEXP token_size, SEXP urlinp_size, SEXP filename_size, SEXP id_size, SEXP type_size) {
  int* token_size_p = INTEGER(token_size);
  int* urlinp_size_p = INTEGER(urlinp_size);
  int* filename_size_p = INTEGER(filename_size);
  int* id_size_p = INTEGER(id_size);
  int* type_size_p = INTEGER(type_size);

  int token_size_int = token_size_p[0];
  int urlinp_size_int = urlinp_size_p[0];
  int filename_size_int = filename_size_p[0];
  int path_size_int = path_size_p[0];

  char* token_char = (char*)malloc(sizeof(char) * token_size_int);
  char* urlinp_char = (char*)malloc(sizeof(char) * urlinp_size_int);
  char* filename_char = (char*)malloc(sizeof(char) * filename_size_int);
  char* path_char = (char*)malloc(sizeof(char) * path_size_int);
  fill_char(token_char, token_size_int, token);
  fill_char(urlinp_char, urlinp_size_int, urlinp);
  fill_char(filename_char, filename_size_int, filename);
  fill_char(path_char, path_size_int, path);

  GoString token_ = mgs(token_char, token_size_int);
  GoString urlinp_ = mgs(urlinp_char, urlinp_size_int);
  GoString filename_ = mgs(filename_char, filename_size_int);
  GoString path_ = mgs(path_char, path_size_int);

  int ret = DownloadIt( token_, urlinp_, filename_, path_);

  free(token_char);
  free(urlinp_char);
  free(filename_char);
  free(path_char);
  
  return Rf_ScalarInteger( ret );

}
*/
