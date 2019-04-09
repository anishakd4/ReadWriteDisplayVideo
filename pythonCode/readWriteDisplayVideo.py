import cv2
import sys
import numpy as np

#Create a videocapture object and read from input video
videoCapture = cv2.VideoCapture("../assets/input_video.mp4")

#check if input file exists
if(videoCapture.isOpened() == False):
    print("error opening input video")
    sys.exit()

#create window for showing input video
cv2.namedWindow("input video", cv2.WINDOW_NORMAL)

#Read until video is completed
while(videoCapture.isOpened()):
    #capture frame by frame
    ret, frame = videoCapture.read()
    if ret == True:

        #display the frame
        cv2.imshow("input video", frame)
        
        #press esc on keyboard to exit
        if cv2.waitKey(25) & 0xFF == 27:
            break
    else:
        break

#When video is done playing release the video capture object
videoCapture.release()

#close all the opened windows
cv2.destroyAllWindows()

#create a VideoCapture object to read camera feed
cameraCapture = cv2.VideoCapture(0)

#check if camera is opened
if(cameraCapture.isOpened() == False):
    print("error opening camera")
    sys.exit()

#Default resolutions of the frame are obtained. The default resolutions are system dependent.
#Convert resolutions from float to integer
frame_width = int(cameraCapture.get(3))
frame_height = int(cameraCapture.get(4))

#Define the codec and create VideoWritter object. The output is stored in "camera_video.avi" file
videoWritter = cv2.VideoWriter('camera_video.avi', cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'), 10, (frame_width, frame_height))

#create window for showing input video
cv2.namedWindow("camera video", cv2.WINDOW_NORMAL)
#keep the camera feed playing until user closed it
while(True):
    ret, frame = cameraCapture.read()

    if ret == True:
        #Write the frame into the file 'output.avi'
        videoWritter.write(frame)

        #display the resulting frame
        cv2.imshow('camera video', frame)

        #press esc on keyboard to exit recordin
        if cv2.waitKey(1) & 0xFF == 27:
            break
    else:
        break

#When recording done, release VideoCapture and VideoWritter objects
cameraCapture.release()
videoWritter.release()


#close all the windows opened
cv2.destroyAllWindows()