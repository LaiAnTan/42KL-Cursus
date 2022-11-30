test cpu load - for i in 1 2 3 4; do while : ; do : ; done & done | bash monitoring.sh

#!/bin/bash
arc=$(uname -a)
pproc=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
vproc=$(nproc --all)
mem=$(free -m | awk '$1 == "Mem:" {print $3 "/" $2 "Mb"}')
mempercent=$(free -m | awk '$1 == "Mem:" {printf("(%.2f%%)", $3/$2*100)}')
disk=$(df -Bm | grep '^/dev/' | grep -v '^/boot$' | awk '{total += $2} {used += $3} END {printf("%d/%dGb", used, total/1024)}')
diskpercent=$(df -Bm | grep '^/dev/' | grep -v '^/boot$' | awk '{total += $2} {used += $3} END {printf("(%.1f%%)", total/used)}')
cpuload=$(top -bn1 | grep '^%Cpu' | awk '$1 == "%Cpu(s):" {printf("%.1f%%", $2+$4)}')
rbt=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvm=$(lsblk | grep "lvm" | wc -l)
ac=$(netstat -ant | grep "ESTABLISHED" | wc -l)
users=$(users | wc -w)
ivp4=$(hostname -I)
mac=$(cat /sys/class/net/*/address | head -1)
sudo=$(sudo grep sudo /var/log/auth.log | wc -l)

wall            "
                #Architechture: $arc
                #CPU Physical: $pproc
                #vCPU: $vproc
                #Memory Usage: $mem $mempercent
                #Disk Usage: $disk $diskpercent
                #CPU load: $cpuload
                #Last boot: $rbt
                #LVM use: `if [ $lvm -ge 1 ]
                then
                        echo "Yes"
                else
                        echo "No"
                fi`
                #Connections tcp: $ac ESTABLISHED
                #User log: $users
                #Network: IP $ivp4 ($mac)
                #Sudo: $sudo cmd
                "