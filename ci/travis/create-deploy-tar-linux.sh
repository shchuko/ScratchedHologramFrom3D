#!/bin/env bash

if [[ ! -d build ]]; then
  mkdir "build" || exit 1;
else
  rm -rf build/* || exit 1;
fi

CLI_BUILD_TARGET="ScratchedHologramFrom3DCLI";
BUILD_NAME="$CLI_BUILD_TARGET"-"$TRAVIS_TAG"-"$TRAVIS_OS_NAME";

cd "build" &&
cmake .. &&
cmake --build ./ --target "$CLI_BUILD_TARGET" &&
mkdir "$BUILD_NAME" &&
cp -r ./bin ./"$BUILD_NAME"/ &&
cp -r ./lib ./"$BUILD_NAME"/ &&
mkdir "out" &&
tar -czvf ./out/"$BUILD_NAME".tar.gz "$BUILD_NAME"/
