# [Choice] Debian / Ubuntu version: debian-11, debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# Install CMake 3.21.1
RUN wget -qO- "https://cmake.org/files/v3.21/cmake-3.21.1-linux-x86_64.tar.gz" | tar --strip-components=1 -xz -C /usr/local
