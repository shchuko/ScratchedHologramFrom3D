#!/bin/env bash

CMAKE_VERSION=3.16.0
CMAKE_VERSION_DIR=v3.16

CMAKE_OS=Linux-x86_64
CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
CMAKE_DIR=$(pwd)/cmake-$CMAKE_VERSION

wget --quiet $CMAKE_URL
mkdir -p "$CMAKE_DIR"
tar --strip-components=1 -xzf $CMAKE_TAR -C "$CMAKE_DIR"
export PATH=$CMAKE_DIR/bin:$PATH


if [ "$TARGET_CPU" == "x86" ]; then
    sudo dpkg --add-architecture i386
    sudo apt-get -qq update

    sudo apt-get install -y liblua5.2-dev:i386
    sudo apt-get install -y libusb-1.0:i386

    sudo apt-get install -y g++-5-multilib
fi
