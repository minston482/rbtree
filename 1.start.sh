#! /bin/bash
sudo rmmod rbtree
sudo insmod rbtree.ko
dmesg
