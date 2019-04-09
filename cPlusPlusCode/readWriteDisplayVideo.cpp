#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Create a VideoCapture object and open input video
    VideoCapture videoCapture("../assets/input_video.mp4");
    
    //Check for camera opened or video filed opened successfully
    if(!videoCapture.isOpened()){
        cout<<"Error opening video stream or file"<<endl;
        return -1;
    }

    namedWindow("input video", WINDOW_NORMAL);

    while(1){
        Mat frame;

        videoCapture >> frame;

        if(frame.empty()){
            break;
        }   

        imshow("input video", frame);

        char c= (char)waitKey(25);
        if(c == 27){
            break;
        }
    }

    videoCapture.release();

    destroyAllWindows();

    return 0;
}