#!/bin/bash

#这个脚本的作用是更新TTMS中的数据文件

#2019-6-30号完成

PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin

LANG=C

#cd /TTMS_2.0  #脚本放在此文件夹make不通过

#学到的东西 
# 1 如何使重定向中的选项变成变量
# 2 数字的运算
# 3 注意文件路径 尤其是相对路径第一个不加\
# 4 shell中不能cp
# 5 cmp文件不能为空


#make

./TTMS

flag=0

date_tmp=$(date +%Y%m%d)

#"cmp Ticket.dat /DATA/Ticket_tmp.dat | wc"
#echo $
#echo "xiamain\n";
#if [ "$tt" -eq "1" ];then
#echo "hellod\nsdsadasdasdasdasdasdasdasdasd"
#fi

cmp Ticket.dat DATA/Ticket_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    #rm -f /DATA/Ticket_tmp.dat
    cat Ticket.dat > DATA/Ticket_tmp.dat         #将数据存入日志文件中
    echo "${date_tmp}  ==>  Ticket.dat\n" >> journal_file    #将数据进行拷贝
    echo "Ticket.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Account.dat DATA/Account_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Account.dat > DATA/Account_tmp.dat    
    echo "${date_tmp}  ==>  Account.dat\n" >> journal_file  
    echo "Account,dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp EntityKey.dat DATA/EntityKey_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat EntityKey.dat > DATA/EntityKey_tmp.dat    
    echo "${date_tmp}  ==>  EntityKey.dat\n" >> journal_file  
    echo "EntityKey.dat数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Play.dat DATA/Play_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Play.dat > DATA/Play_tmp.dat    
    echo "${date_tmp}  ==>  Play.dat\n" >> journal_file  
    echo "Play.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Sale.dat DATA/Sale_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Sale.dat > DATA/Sale_tmp.dat    
    echo "${date_tmp}  ==>  Sale.dat\n" >> journal_file  
    echo "Sale.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Schedule.dat DATA/Schedule_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Schedule.dat > DATA/Schedule_tmp.dat  
    echo "${date_tmp}  ==>  Schedule.dat\n" >> journal_file  
    echo "Schedule.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Seat.dat DATA/Seat_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Seat.dat > DATA/Seat_tmp.dat  
    echo "${date_tmp}  ==>  Seat.dat\n" >> journal_file  
    echo "Seat.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

cmp Studio.dat DATA/Studio_tmp.dat > /dev/null 2>&1
if [ "$?" -eq "1" ]; then
    cat Studio.dat > DATA/Studio_tmp.dat
    echo "${date_tmp}  ==>  Studio.dat\n" >> journal_file
    echo "Studio.dat 数据已更新！\n"
    flag=$((${flag}+1))
fi

if [ "${flag}" -eq "0" ];then
    echo "${date_tmp}  未改动文件！\n" >> journal_file
    temp=1
    flag=$((${flag}+1))
fi

#temp=${temp:-0}
#在文件运行结束后展示修改的数据文件
#if [ "${temp}" -eq "1" ];then
#    tail -n $flag journal_file
#fi
















