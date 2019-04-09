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

    VideoCapture cameraCapture(0);

    if(!cameraCapture.isOpened()){
        cout<<"Error opening camera"<<endl;
        return -1;
    }

    int frame_width = cameraCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = cameraCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

    VideoWriter video("camera_video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));

    namedWindow("camera video", WINDOW_NORMAL);

    while(1){
        Mat frame;

        cameraCapture >> frame;

        if(frame.empty()){
            break;
        }

        video.write(frame);

        imshow("camera video", frame);

        char c= (char)waitKey(1);
        if(c == 27){
            break;
        }
    }

    cameraCapture.release();
    video.release();

    destroyAllWindows();

    return 0;
}