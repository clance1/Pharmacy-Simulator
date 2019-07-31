#!/bin/sh
make all
echo ' '
echo '***************Running testDateStr...******************'
./testDateStr > testDateStr.out
echo 'Writing to testDateStr.out...'
echo ' '
echo '***************Running testDataCla...******************'
./testDateCla > testDateCla.out
echo 'Writing to testDateCla.out'
echo ' '
echo '***************Running testBottleStr...******************'
./testBottleStr testBottle.txt > testBottleStr.out
echo 'Writing to testBottleStr.out...'
echo ' '
echo '***************Running testBottleCla...******************'
./testBottleStr testBottle.txt > testBottleStr.out
echo 'Writing to testBottleCla.out...'
echo ' '
echo '***************Running testQueueStr...******************'
./testQueueStr testRowDS.txt > testQueueStr.out
echo 'Writing to testBottleStr.out...'
echo ' '
echo '***************Running testQueueCla...******************'
./testQueueCla testRowDS.txt > testQueueCla.out
echo 'Writing to testBottleStr.out...'
echo ' '
