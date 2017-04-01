#!/bin/sh

FILE="`readlink -f $0`"
ROOT="`dirname $FILE`"

export LD_LIBRARY_PATH="$ROOT/Libraries/Qt/lib"
export QT_PLUGIN_PATH="$ROOT/Libraries/Qt/plugins"

cd $ROOT ; ./ImageViewer $*

