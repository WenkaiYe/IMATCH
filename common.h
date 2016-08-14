#ifndef COMMON_
#define COMMON_
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

#include <string>

//omp
#ifdef _OPENMP
#include <omp.h>
#endif

//opencv
#include "opencv2/opencv.hpp"

#define MAX_LENGTH_OF_FILEPATH 100

typedef struct{
    cv::Point2f p1;
    cv::Point2f p2;
    double corr;
    int wsize;
    double dx;
    double dy;
} Correspondence;

#endif
