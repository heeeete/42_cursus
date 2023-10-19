#!/bin/bash

printf "#Architecture : $(uname -a)\n"

printf "#CPU physical : $(nproc --all)\n"

printf "#vCPU : $(cat /proc/cpuinfo | grep processor | sort -u |wc -l)\n"

tmem=$(free -m | grep "Mem" | awk '{printf $2}')
umem=$(free -m | grep "Mem" | awk '{printf $3}')
pmem=$(free -m | grep "Mem" | awk '{printf "%.2f", $3/$2*100}')
printf "#Memory Usage : ${umem}/${tmem}MB (${pmem}%%)\n"

tdisk=$(df -BM | grep -v Filesystem | awk '{sum += $2} END {printf sum}')
udisk=$(df -BM | grep -v Filesystem | awk '{sum += $3} END {printf sum}')
echo $udisk $tdisk | awk '{printf "#Disk Usage : %d/%0.0fGB (%d%%)\n", $1, $2/1024, $1/$2*100}'

printf "#CPU load : $(mpstat | grep all | awk '{printf 100 - $13}')%%\n"

printf "#Last boot : $(who -b | awk '{printf $3" "$4}')\n"

lvm_n=$(lsblk | grep "lvm" | wc -l)
if [ $lvm_n -gt 0 ];
then
	lvm_u="yes";
else
	lvm_u="no";
fi
printf "#LVM use : $lvm_u\n"

tcp_n=$(ss -t | grep ESTAB | wc -l)
printf "#Connexions TCP : $tcp_n ESTABLISHED\n"

printf "#User log : $(who | wc -l)\n"

ip=$(hostname -I)
mac=$(ip link | grep ether | awk '{printf $2}')
printf "#Network : IP $ip($mac)\n"

sudo=$(cat /var/log/sudo/seq)
printf "#Sudo : "
echo "ibase=32;$sudo" | bc | tr -d '\n'
printf " cmd\n"
