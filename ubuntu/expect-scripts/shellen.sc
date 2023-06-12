#!/usr/bin/expect

set mode [lindex $argv 0];
set arch [lindex $argv 1];

spawn "shellen"
expect "> "
send "$mode\n"
expect "> "
send "setarch $arch\n"
interact
