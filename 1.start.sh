#! /bin/bash
sudo rmmod test_rbtree
sudo insmod test_rbtree.ko
dmesg
