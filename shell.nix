{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    # nativeBuildInputs is usually what you want -- tools you need to run
    nativeBuildInputs = [ pkgs.nodePackages.node-gyp ];
    CFLAGS_CC="-I${pkgs.texlive.bin.core}/include";
    CXXFLAGS="-I${pkgs.texlive.bin.core}/include";
  }
 

