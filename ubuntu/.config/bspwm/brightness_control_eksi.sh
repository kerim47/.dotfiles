#!/bin/bash
pkexec xfpm-power-backlight-helper --set-brightness $(($(pkexec xfpm-power-backlight-helper --get-brightness) - 12000))
