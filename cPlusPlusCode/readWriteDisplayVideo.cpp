#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Create a VideoCapture object and open input video
    VideoCapture videoCapture("../assets/input_video.mp4");
    
    //Check if input video exists
    if(!videoCapture.isOpened()){
        cout<<"Error opening video stream or file"<<endl;
        return -1;
    }

    //Create a window to show input video
    namedWindow("input video", WINDOW_NORMAL);

    //Keep playing video until video is completed
    while(1){
        Mat frame;

        //Capture frame by frame
        videoCapture >> frame;

        //If frame is empty then break the loop
        if(frame.empty()){
            break;
        }   

        //Show the current frame
        imshow("input video", frame);

        //Press esc in keyboard to exit playing input video
        char c= (char)waitKey(25);
        if(c == 27){
            break;
        }
    }

    //Close window after input video is completed
    videoCapture.release();

    //Destroy all the opened windows
    destroyAllWindows();

    //Create VideoCapture object to read camera frame
    VideoCapture cameraCapture(0);

    //Check if camera is opened
    if(!cameraCapture.isOpened()){
        cout<<"Error opening camera"<<endl;
        return -1;
    }

    //Default resolutions of the frame are obtained. The default resolutions are system dependent.
    int frame_width = cameraCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = cameraCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

    //Define the codec and create VideoWritter object. The output is stored in 'camera_video.avi'
    VideoWriter video("camera_video.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));

    //Create a window to show camera frames.
    namedWindow("camera video", WINDOW_NORMAL);

    while(1){
        Mat frame;
        
        //capture frame by frame
        cameraCapture >> frame;

        //if frame is empty break the loop
        if(frame.empty()){
            break;
        }

        //write the current frame into file "camera_video.avi"
        video.write(frame);

        //show the current frame
        imshow("camera video", frame);

        //Press esc on keyboard to exit
        char c= (char)waitKey(1);
        if(c == 27){
            break;
        }
    }

    //When video recording is done, release the VideoCapture and VideoWritter objects 
    cameraCapture.release();
    video.release();

    //Close all the opened windows
    destroyAllWindows();

    return 0;
}