package main

import "C"

import "interaction_with_ELN"

import "fmt"

var p = fmt.Println;

//export DownloadIt
func DownloadIt(token string, urlinp string, filename string, path string) int {
  err := interaction_with_ELN.Download(token, urlinp, filename, path)
  if(err != nil) {
    return 1
  }
  return 0
}


/*
//export UploadIt
func UploadIt(token string, urlinp string, filename string, id string, type_ string) int {

  err := interaction_with_ELN.upload_to_eln(token, urlinp, filename, id, type_);
  if(err != nil) {
    return 1
  }
  return 0
}
*/

func main() {}
