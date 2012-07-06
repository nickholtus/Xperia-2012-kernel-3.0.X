#!/system/bin/sh

MAC_FILE=/data/etc/wlan_macaddr
COMMAND="/system/bin/insmod /lib/modules/2.6.35.7+/kernel/net/compat-wireless/drivers/staging/cw1200/cw1200_core.ko"
COMMAND2="insmod /lib/modules/2.6.35.7+/kernel/net/compat-wireless/drivers/staging/cw1200/cw1200_wlan.ko"
ARG="macaddr="

if ( /system/bin/ls $MAC_FILE > /dev/null ); then
     ADDR=`/system/bin/cat $MAC_FILE`
     echo $COMMAND $ARG$ADDR
     $COMMAND $ARG$ADDR
     $COMMAND2

else
     echo $COMMAND
     $COMMAND
     $COMMAND2
fi

