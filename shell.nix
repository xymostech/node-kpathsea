{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    # nativeBuildInputs is usually what you want -- tools you need to run
    # nativeBuildInputs = [ pkgs.texlive.bin ];
    CFLAGS_CC="-I${pkgs.texlive.bin.core}/include";
  }
 

