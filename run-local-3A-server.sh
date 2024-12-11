#!/bin/bash

if pgrep -x "rkaiq_3A_server" > /dev/null
then
    sudo killall rkaiq_3A_server
fi

sudo build/rkaiq_3A_server/rkaiq_3A_server