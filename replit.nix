{pkgs}: {
  deps = [
    pkgs.xorg.libXi
    pkgs.xorg.libXcursor
    pkgs.xorg.libXrandr
    pkgs.xorg.libX11
    pkgs.mesa
    pkgs.udev
    pkgs.freetype
    pkgs.pkg-config
    pkgs.git
    pkgs.ninja
    pkgs.cmake
  ];
}
