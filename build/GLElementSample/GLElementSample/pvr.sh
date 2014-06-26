#!/bin/sh

#  pvr.sh
#  GLElementSample
#
#  Created by zhang hailong on 14-6-26.
#  Copyright (c) 2014年 hailong.org. All rights reserved.

BIN=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin

for infile in ./*.png
do

echo ${BIN}/texturetool -m -f PVR -e PVRTC -o ${infile:0:${#infile}-4}.pvr $infile

${BIN}/texturetool -m -f PVR -e PVRTC -o ${infile:0:${#infile}-4}.pvr $infile

done
