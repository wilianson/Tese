

/*
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv/cxcore.h"

#include <time.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
  // OpenCV Capture object to grab frames
  CvCapture *capture = cvCaptureFromCAM(1);

  // start and end times
  time_t start, end;

  // fps calculated using number of frames / seconds
  double fps;

  // frame counter
  int counter = 0;

  // floating point seconds elapsed since start
  double sec;

  // start the clock
  time(&start);

  while(cvGrabFrame(capture))
    {
      // grab a frame
      IplImage *frame = cvRetrieveFrame(capture);

      // see how much time has elapsed
      time(&end);

      // calculate current FPS
      ++counter;
      sec = difftime (end, start);

      fps = counter / sec;

      // will print out Inf until sec is greater than 0
      printf("FPS = %.2f\n", fps);
    }

  cvReleaseCapture(&capture);
  return 0;
}*/
