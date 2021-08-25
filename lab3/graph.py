import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def Average(lst):
    return sum(lst) / len(lst)
i=0
FCFS_AWT = []
FCFS_ATT = []
FCFS_ART = []
SJF_AWT = []
SJF_ATT = []
SJF_ART = []
SJF_P_AWT = []
SJF_P_ATT = []
SJF_P_ART = []
RR_AWT = []
RR_ATT = []
RR_ART = []
PB_AWT = []
PB_ATT = []
PB_ART = []
with open("output.txt") as infile:
    for line in infile:
        words = line.split(",")
        if i==0:
            FCFS_AWT.append(float(words[7]))
            FCFS_ATT.append(float(words[8]))
            FCFS_ART.append(float(words[9]))
            i=i+1
            continue
        if i==1:
            SJF_AWT.append(float(words[7]))
            SJF_ATT.append(float(words[8]))
            SJF_ART.append(float(words[9]))
            i=i+1
            continue
        if i==2:
            SJF_P_AWT.append(float(words[7]))
            SJF_P_ATT.append(float(words[8]))
            SJF_P_ART.append(float(words[9]))
            i=i+1
            continue
        if i==3:
            RR_AWT.append(float(words[7]))
            RR_ATT.append(float(words[8]))
            RR_ART.append(float(words[9]))
            i=i+1
            continue
        if i==4:
            PB_AWT.append(float(words[7]))
            PB_ATT.append(float(words[8]))
            PB_ART.append(float(words[9]))
            i=0
            continue

FCFS_AWT_10 = []
FCFS_ATT_10 = []
FCFS_ART_10 = []
SJF_AWT_10 = []
SJF_ATT_10 = []
SJF_ART_10 = []
SJF_P_AWT_10 = []
SJF_P_ATT_10 = []
SJF_P_ART_10 = []
RR_AWT_10 = []
RR_ATT_10 = []
RR_ART_10 = []
PB_AWT_10 = []
PB_ATT_10 = []
PB_ART_10 = []

FCFS_AWT_20 = []
FCFS_ATT_20 = []
FCFS_ART_20 = []
SJF_AWT_20 = []
SJF_ATT_20 = []
SJF_ART_20 = []
SJF_P_AWT_20 = []
SJF_P_ATT_20 = []
SJF_P_ART_20 = []
RR_AWT_20 = []
RR_ATT_20 = []
RR_ART_20 = []
PB_AWT_20 = []
PB_ATT_20 = []
PB_ART_20 = []

FCFS_AWT_30 = []
FCFS_ATT_30 = []
FCFS_ART_30 = []
SJF_AWT_30 = []
SJF_ATT_30 = []
SJF_ART_30 = []
SJF_P_AWT_30 = []
SJF_P_ATT_30 = []
SJF_P_ART_30 = []
RR_AWT_30 = []
RR_ATT_30 = []
RR_ART_30 = []
PB_AWT_30 = []
PB_ATT_30 = []
PB_ART_30 = []

FCFS_AWT_40 = []
FCFS_ATT_40 = []
FCFS_ART_40 = []
SJF_AWT_40 = []
SJF_ATT_40 = []
SJF_ART_40 = []
SJF_P_AWT_40 = []
SJF_P_ATT_40 = []
SJF_P_ART_40 = []
RR_AWT_40 = []
RR_ATT_40 = []
RR_ART_40 = []
PB_AWT_40 = []
PB_ATT_40 = []
PB_ART_40 = []

FCFS_AWT_50 = []
FCFS_ATT_50 = []
FCFS_ART_50 = []
SJF_AWT_50 = []
SJF_ATT_50 = []
SJF_ART_50 = []
SJF_P_AWT_50 = []
SJF_P_ATT_50 = []
SJF_P_ART_50 = []
RR_AWT_50 = []
RR_ATT_50 = []
RR_ART_50 = []
PB_AWT_50 = []
PB_ATT_50 = []
PB_ART_50 = []
i=0
for j in range(50):
    if i==0:
        FCFS_AWT_10.append(FCFS_AWT[j])
        FCFS_ATT_10.append(FCFS_ATT[j])
        FCFS_ART_10.append(FCFS_ART[j])
        SJF_AWT_10.append(SJF_AWT[j])
        SJF_ATT_10.append(SJF_ATT[j])
        SJF_ART_10.append(SJF_ART[j])
        SJF_P_AWT_10.append(SJF_P_AWT[j])
        SJF_P_ATT_10.append(SJF_P_ATT[j])
        SJF_P_ART_10.append(SJF_P_ART[j])
        RR_AWT_10.append(RR_AWT[j])
        RR_ATT_10.append(RR_ATT[j])
        RR_ART_10.append(RR_ART[j])
        PB_AWT_10.append(PB_AWT[j])
        PB_ATT_10.append(PB_ATT[j])
        PB_ART_10.append(PB_ART[j])
        i=i+1
        continue
    if i==1:
        FCFS_AWT_20.append(FCFS_AWT[j])
        FCFS_ATT_20.append(FCFS_ATT[j])
        FCFS_ART_20.append(FCFS_ART[j])
        SJF_AWT_20.append(SJF_AWT[j])
        SJF_ATT_20.append(SJF_ATT[j])
        SJF_ART_20.append(SJF_ART[j])
        SJF_P_AWT_20.append(SJF_P_AWT[j])
        SJF_P_ATT_20.append(SJF_P_ATT[j])
        SJF_P_ART_20.append(SJF_P_ART[j])
        RR_AWT_20.append(RR_AWT[j])
        RR_ATT_20.append(RR_ATT[j])
        RR_ART_20.append(RR_ART[j])
        PB_AWT_20.append(PB_AWT[j])
        PB_ATT_20.append(PB_ATT[j])
        PB_ART_20.append(PB_ART[j])
        i=i+1
        continue
    if i==2:
        FCFS_AWT_30.append(FCFS_AWT[j])
        FCFS_ATT_30.append(FCFS_ATT[j])
        FCFS_ART_30.append(FCFS_ART[j])
        SJF_AWT_30.append(SJF_AWT[j])
        SJF_ATT_30.append(SJF_ATT[j])
        SJF_ART_30.append(SJF_ART[j])
        SJF_P_AWT_30.append(SJF_P_AWT[j])
        SJF_P_ATT_30.append(SJF_P_ATT[j])
        SJF_P_ART_30.append(SJF_P_ART[j])
        RR_AWT_30.append(RR_AWT[j])
        RR_ATT_30.append(RR_ATT[j])
        RR_ART_30.append(RR_ART[j])
        PB_AWT_30.append(PB_AWT[j])
        PB_ATT_30.append(PB_ATT[j])
        PB_ART_30.append(PB_ART[j])
        i=i+1
        continue
    if i==3:
        FCFS_AWT_40.append(FCFS_AWT[j])
        FCFS_ATT_40.append(FCFS_ATT[j])
        FCFS_ART_40.append(FCFS_ART[j])
        SJF_AWT_40.append(SJF_AWT[j])
        SJF_ATT_40.append(SJF_ATT[j])
        SJF_ART_40.append(SJF_ART[j])
        SJF_P_AWT_40.append(SJF_P_AWT[j])
        SJF_P_ATT_40.append(SJF_P_ATT[j])
        SJF_P_ART_40.append(SJF_P_ART[j])
        RR_AWT_40.append(RR_AWT[j])
        RR_ATT_40.append(RR_ATT[j])
        RR_ART_40.append(RR_ART[j])
        PB_AWT_40.append(PB_AWT[j])
        PB_ATT_40.append(PB_ATT[j])
        PB_ART_40.append(PB_ART[j])
        i=i+1
        continue
    if i==4:
        FCFS_AWT_50.append(FCFS_AWT[j])
        FCFS_ATT_50.append(FCFS_ATT[j])
        FCFS_ART_50.append(FCFS_ART[j])
        SJF_AWT_50.append(SJF_AWT[j])
        SJF_ATT_50.append(SJF_ATT[j])
        SJF_ART_50.append(SJF_ART[j])
        SJF_P_AWT_50.append(SJF_P_AWT[j])
        SJF_P_ATT_50.append(SJF_P_ATT[j])
        SJF_P_ART_50.append(SJF_P_ART[j])
        RR_AWT_50.append(RR_AWT[j])
        RR_ATT_50.append(RR_ATT[j])
        RR_ART_50.append(RR_ART[j])
        PB_AWT_50.append(PB_AWT[j])
        PB_ATT_50.append(PB_ATT[j])
        PB_ART_50.append(PB_ART[j])
        i=i+1
        continue

x = [10,20,30,40,50]
FCFS_MIN_AWT = []
FCFS_MAX_AWT = []
FCFS_AVG_AWT = []

FCFS_MIN_AWT.append(min(FCFS_AWT_10))
FCFS_MIN_AWT.append(min(FCFS_AWT_20))
FCFS_MIN_AWT.append(min(FCFS_AWT_30))
FCFS_MIN_AWT.append(min(FCFS_AWT_40))
FCFS_MIN_AWT.append(min(FCFS_AWT_50))

FCFS_MAX_AWT.append(max(FCFS_AWT_10))
FCFS_MAX_AWT.append(max(FCFS_AWT_20))
FCFS_MAX_AWT.append(max(FCFS_AWT_30))
FCFS_MAX_AWT.append(max(FCFS_AWT_40))
FCFS_MAX_AWT.append(max(FCFS_AWT_50))

FCFS_AVG_AWT.append(Average(FCFS_AWT_10))
FCFS_AVG_AWT.append(Average(FCFS_AWT_20))
FCFS_AVG_AWT.append(Average(FCFS_AWT_30))
FCFS_AVG_AWT.append(Average(FCFS_AWT_40))
FCFS_MAX_AWT.append(Average(FCFS_AWT_50))

FCFS_MIN_ATT = []
FCFS_MAX_ATT = []
FCFS_AVG_ATT = []

FCFS_MIN_ATT.append(min(FCFS_ATT_10))
FCFS_MIN_ATT.append(min(FCFS_ATT_20))
FCFS_MIN_ATT.append(min(FCFS_ATT_30))
FCFS_MIN_ATT.append(min(FCFS_ATT_40))
FCFS_MIN_ATT.append(min(FCFS_ATT_50))

FCFS_MAX_ATT.append(max(FCFS_ATT_10))
FCFS_MAX_ATT.append(max(FCFS_ATT_20))
FCFS_MAX_ATT.append(max(FCFS_ATT_30))
FCFS_MAX_ATT.append(max(FCFS_ATT_40))
FCFS_MAX_ATT.append(max(FCFS_ATT_50))

FCFS_AVG_ATT.append(Average(FCFS_ATT_10))
FCFS_AVG_ATT.append(Average(FCFS_ATT_20))
FCFS_AVG_ATT.append(Average(FCFS_ATT_30))
FCFS_AVG_ATT.append(Average(FCFS_ATT_40))
FCFS_MAX_ATT.append(Average(FCFS_ATT_50))

FCFS_MIN_ART = []
FCFS_MAX_ART = []
FCFS_AVG_ART = []

FCFS_MIN_ART.append(min(FCFS_ART_10))
FCFS_MIN_ART.append(min(FCFS_ART_20))
FCFS_MIN_ART.append(min(FCFS_ART_30))
FCFS_MIN_ART.append(min(FCFS_ART_40))
FCFS_MIN_ART.append(min(FCFS_ART_50))

FCFS_MAX_ART.append(max(FCFS_ART_10))
FCFS_MAX_ART.append(max(FCFS_ART_20))
FCFS_MAX_ART.append(max(FCFS_ART_30))
FCFS_MAX_ART.append(max(FCFS_ART_40))
FCFS_MAX_ART.append(max(FCFS_ART_50))

FCFS_AVG_ART.append(Average(FCFS_ART_10))
FCFS_AVG_ART.append(Average(FCFS_ART_20))
FCFS_AVG_ART.append(Average(FCFS_ART_30))
FCFS_AVG_ART.append(Average(FCFS_ART_40))
FCFS_MAX_ART.append(Average(FCFS_ART_50))

# SJF

SJF_MIN_AWT = []
SJF_MAX_AWT = []
SJF_AVG_AWT = []

SJF_MIN_AWT.append(min(SJF_AWT_10))
SJF_MIN_AWT.append(min(SJF_AWT_20))
SJF_MIN_AWT.append(min(SJF_AWT_30))
SJF_MIN_AWT.append(min(SJF_AWT_40))
SJF_MIN_AWT.append(min(SJF_AWT_50))

SJF_MAX_AWT.append(max(SJF_AWT_10))
SJF_MAX_AWT.append(max(SJF_AWT_20))
SJF_MAX_AWT.append(max(SJF_AWT_30))
SJF_MAX_AWT.append(max(SJF_AWT_40))
SJF_MAX_AWT.append(max(SJF_AWT_50))

SJF_AVG_AWT.append(Average(SJF_AWT_10))
SJF_AVG_AWT.append(Average(SJF_AWT_20))
SJF_AVG_AWT.append(Average(SJF_AWT_30))
SJF_AVG_AWT.append(Average(SJF_AWT_40))
SJF_MAX_AWT.append(Average(SJF_AWT_50))

SJF_MIN_ATT = []
SJF_MAX_ATT = []
SJF_AVG_ATT = []

SJF_MIN_ATT.append(min(SJF_ATT_10))
SJF_MIN_ATT.append(min(SJF_ATT_20))
SJF_MIN_ATT.append(min(SJF_ATT_30))
SJF_MIN_ATT.append(min(SJF_ATT_40))
SJF_MIN_ATT.append(min(SJF_ATT_50))

SJF_MAX_ATT.append(max(SJF_ATT_10))
SJF_MAX_ATT.append(max(SJF_ATT_20))
SJF_MAX_ATT.append(max(SJF_ATT_30))
SJF_MAX_ATT.append(max(SJF_ATT_40))
SJF_MAX_ATT.append(max(SJF_ATT_50))

SJF_AVG_ATT.append(Average(SJF_ATT_10))
SJF_AVG_ATT.append(Average(SJF_ATT_20))
SJF_AVG_ATT.append(Average(SJF_ATT_30))
SJF_AVG_ATT.append(Average(SJF_ATT_40))
SJF_MAX_ATT.append(Average(SJF_ATT_50))

SJF_MIN_ART = []
SJF_MAX_ART = []
SJF_AVG_ART = []

SJF_MIN_ART.append(min(SJF_ART_10))
SJF_MIN_ART.append(min(SJF_ART_20))
SJF_MIN_ART.append(min(SJF_ART_30))
SJF_MIN_ART.append(min(SJF_ART_40))
SJF_MIN_ART.append(min(SJF_ART_50))

SJF_MAX_ART.append(max(SJF_ART_10))
SJF_MAX_ART.append(max(SJF_ART_20))
SJF_MAX_ART.append(max(SJF_ART_30))
SJF_MAX_ART.append(max(SJF_ART_40))
SJF_MAX_ART.append(max(SJF_ART_50))

SJF_AVG_ART.append(Average(SJF_ART_10))
SJF_AVG_ART.append(Average(SJF_ART_20))
SJF_AVG_ART.append(Average(SJF_ART_30))
SJF_AVG_ART.append(Average(SJF_ART_40))
SJF_MAX_ART.append(Average(FCFS_ART_50))

#SJF_P

SJF_P_MIN_AWT = []
SJF_P_MAX_AWT = []
SJF_P_AVG_AWT = []

SJF_P_MIN_AWT.append(min(SJF_P_AWT_10))
SJF_P_MIN_AWT.append(min(SJF_P_AWT_20))
SJF_P_MIN_AWT.append(min(SJF_P_AWT_30))
SJF_P_MIN_AWT.append(min(SJF_P_AWT_40))
SJF_P_MIN_AWT.append(min(SJF_P_AWT_50))

SJF_P_MAX_AWT.append(max(SJF_P_AWT_10))
SJF_P_MAX_AWT.append(max(SJF_P_AWT_20))
SJF_P_MAX_AWT.append(max(SJF_P_AWT_30))
SJF_P_MAX_AWT.append(max(SJF_P_AWT_40))
SJF_P_MAX_AWT.append(max(SJF_P_AWT_50))

SJF_P_AVG_AWT.append(Average(SJF_P_AWT_10))
SJF_P_AVG_AWT.append(Average(SJF_P_AWT_20))
SJF_P_AVG_AWT.append(Average(SJF_P_AWT_30))
SJF_P_AVG_AWT.append(Average(SJF_P_AWT_40))
SJF_P_MAX_AWT.append(Average(SJF_P_AWT_50))

SJF_P_MIN_ATT = []
SJF_P_MAX_ATT = []
SJF_P_AVG_ATT = []

SJF_P_MIN_ATT.append(min(SJF_P_ATT_10))
SJF_P_MIN_ATT.append(min(SJF_P_ATT_20))
SJF_P_MIN_ATT.append(min(SJF_P_ATT_30))
SJF_P_MIN_ATT.append(min(SJF_P_ATT_40))
SJF_P_MIN_ATT.append(min(SJF_P_ATT_50))

SJF_P_MAX_ATT.append(max(SJF_P_ATT_10))
SJF_P_MAX_ATT.append(max(SJF_P_ATT_20))
SJF_P_MAX_ATT.append(max(SJF_P_ATT_30))
SJF_P_MAX_ATT.append(max(SJF_P_ATT_40))
SJF_P_MAX_ATT.append(max(SJF_P_ATT_50))

SJF_P_AVG_ATT.append(Average(SJF_P_ATT_10))
SJF_P_AVG_ATT.append(Average(SJF_P_ATT_20))
SJF_P_AVG_ATT.append(Average(SJF_P_ATT_30))
SJF_P_AVG_ATT.append(Average(SJF_P_ATT_40))
SJF_P_MAX_ATT.append(Average(SJF_P_ATT_50))

SJF_P_MIN_ART = []
SJF_P_MAX_ART = []
SJF_P_AVG_ART = []

SJF_P_MIN_ART.append(min(SJF_P_ART_10))
SJF_P_MIN_ART.append(min(SJF_P_ART_20))
SJF_P_MIN_ART.append(min(SJF_P_ART_30))
SJF_P_MIN_ART.append(min(SJF_P_ART_40))
SJF_P_MIN_ART.append(min(SJF_P_ART_50))

SJF_P_MAX_ART.append(max(SJF_P_ART_10))
SJF_P_MAX_ART.append(max(SJF_P_ART_20))
SJF_P_MAX_ART.append(max(SJF_P_ART_30))
SJF_P_MAX_ART.append(max(SJF_P_ART_40))
SJF_P_MAX_ART.append(max(SJF_P_ART_50))

SJF_P_AVG_ART.append(Average(SJF_P_ART_10))
SJF_P_AVG_ART.append(Average(SJF_P_ART_20))
SJF_P_AVG_ART.append(Average(SJF_P_ART_30))
SJF_P_AVG_ART.append(Average(SJF_P_ART_40))
SJF_P_MAX_ART.append(Average(FCFS_ART_50))

#RR

RR_MIN_AWT = []
RR_MAX_AWT = []
RR_AVG_AWT = []

RR_MIN_AWT.append(min(RR_AWT_10))
RR_MIN_AWT.append(min(RR_AWT_20))
RR_MIN_AWT.append(min(RR_AWT_30))
RR_MIN_AWT.append(min(RR_AWT_40))
RR_MIN_AWT.append(min(RR_AWT_50))

RR_MAX_AWT.append(max(RR_AWT_10))
RR_MAX_AWT.append(max(RR_AWT_20))
RR_MAX_AWT.append(max(RR_AWT_30))
RR_MAX_AWT.append(max(RR_AWT_40))
RR_MAX_AWT.append(max(RR_AWT_50))

RR_AVG_AWT.append(Average(RR_AWT_10))
RR_AVG_AWT.append(Average(RR_AWT_20))
RR_AVG_AWT.append(Average(RR_AWT_30))
RR_AVG_AWT.append(Average(RR_AWT_40))
RR_MAX_AWT.append(Average(RR_AWT_50))

RR_MIN_ATT = []
RR_MAX_ATT = []
RR_AVG_ATT = []

RR_MIN_ATT.append(min(RR_ATT_10))
RR_MIN_ATT.append(min(RR_ATT_20))
RR_MIN_ATT.append(min(RR_ATT_30))
RR_MIN_ATT.append(min(RR_ATT_40))
RR_MIN_ATT.append(min(RR_ATT_50))

RR_MAX_ATT.append(max(RR_ATT_10))
RR_MAX_ATT.append(max(RR_ATT_20))
RR_MAX_ATT.append(max(RR_ATT_30))
RR_MAX_ATT.append(max(RR_ATT_40))
RR_MAX_ATT.append(max(RR_ATT_50))

RR_AVG_ATT.append(Average(RR_ATT_10))
RR_AVG_ATT.append(Average(RR_ATT_20))
RR_AVG_ATT.append(Average(RR_ATT_30))
RR_AVG_ATT.append(Average(RR_ATT_40))
RR_MAX_ATT.append(Average(RR_ATT_50))

RR_MIN_ART = []
RR_MAX_ART = []
RR_AVG_ART = []

RR_MIN_ART.append(min(RR_ART_10))
RR_MIN_ART.append(min(RR_ART_20))
RR_MIN_ART.append(min(RR_ART_30))
RR_MIN_ART.append(min(RR_ART_40))
RR_MIN_ART.append(min(RR_ART_50))

RR_MAX_ART.append(max(RR_ART_10))
RR_MAX_ART.append(max(RR_ART_20))
RR_MAX_ART.append(max(RR_ART_30))
RR_MAX_ART.append(max(RR_ART_40))
RR_MAX_ART.append(max(RR_ART_50))

RR_AVG_ART.append(Average(RR_ART_10))
RR_AVG_ART.append(Average(RR_ART_20))
RR_AVG_ART.append(Average(RR_ART_30))
RR_AVG_ART.append(Average(RR_ART_40))
RR_MAX_ART.append(Average(FCFS_ART_50))

#PB

PB_MIN_AWT = []
PB_MAX_AWT = []
PB_AVG_AWT = []

PB_MIN_AWT.append(min(PB_AWT_10))
PB_MIN_AWT.append(min(PB_AWT_20))
PB_MIN_AWT.append(min(PB_AWT_30))
PB_MIN_AWT.append(min(PB_AWT_40))
PB_MIN_AWT.append(min(PB_AWT_50))

PB_MAX_AWT.append(max(PB_AWT_10))
PB_MAX_AWT.append(max(PB_AWT_20))
PB_MAX_AWT.append(max(PB_AWT_30))
PB_MAX_AWT.append(max(PB_AWT_40))
PB_MAX_AWT.append(max(PB_AWT_50))

PB_AVG_AWT.append(Average(PB_AWT_10))
PB_AVG_AWT.append(Average(PB_AWT_20))
PB_AVG_AWT.append(Average(PB_AWT_30))
PB_AVG_AWT.append(Average(PB_AWT_40))
PB_MAX_AWT.append(Average(PB_AWT_50))

PB_MIN_ATT = []
PB_MAX_ATT = []
PB_AVG_ATT = []

PB_MIN_ATT.append(min(PB_ATT_10))
PB_MIN_ATT.append(min(PB_ATT_20))
PB_MIN_ATT.append(min(PB_ATT_30))
PB_MIN_ATT.append(min(PB_ATT_40))
PB_MIN_ATT.append(min(PB_ATT_50))

PB_MAX_ATT.append(max(PB_ATT_10))
PB_MAX_ATT.append(max(PB_ATT_20))
PB_MAX_ATT.append(max(PB_ATT_30))
PB_MAX_ATT.append(max(PB_ATT_40))
PB_MAX_ATT.append(max(PB_ATT_50))

PB_AVG_ATT.append(Average(PB_ATT_10))
PB_AVG_ATT.append(Average(PB_ATT_20))
PB_AVG_ATT.append(Average(PB_ATT_30))
PB_AVG_ATT.append(Average(PB_ATT_40))
PB_MAX_ATT.append(Average(PB_ATT_50))

PB_MIN_ART = []
PB_MAX_ART = []
PB_AVG_ART = []

PB_MIN_ART.append(min(PB_ART_10))
PB_MIN_ART.append(min(PB_ART_20))
PB_MIN_ART.append(min(PB_ART_30))
PB_MIN_ART.append(min(PB_ART_40))
PB_MIN_ART.append(min(PB_ART_50))

PB_MAX_ART.append(max(PB_ART_10))
PB_MAX_ART.append(max(PB_ART_20))
PB_MAX_ART.append(max(PB_ART_30))
PB_MAX_ART.append(max(PB_ART_40))
PB_MAX_ART.append(max(PB_ART_50))

PB_AVG_ART.append(Average(PB_ART_10))
PB_AVG_ART.append(Average(PB_ART_20))
PB_AVG_ART.append(Average(PB_ART_30))
PB_AVG_ART.append(Average(PB_ART_40))
PB_MAX_ART.append(Average(FCFS_ART_50))