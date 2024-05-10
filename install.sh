# Build hex with make ergodox_ez:wentam
# Run me as root with sh install.sh [layout.hex]
sleep 5 # Push reset button on keyboard now
teensy-loader-cli -v -mmcu=atmega32u4 $@
