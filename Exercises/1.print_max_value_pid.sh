#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "valeur maximale du PID : $pid_max"
