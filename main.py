import cv2
import os
import random
import time
import numpy as np


IMGPATH="img/leave/"
scaleFactor=1.1
minNeighbors=2
CROP_W=20
CROP_H=40
_FRAME_COUNT=100
MODE_IMAGE_PROCESS=1
MODE_VIDEO_PROCESS=2
mode = MODE_VIDEO_PROCESS

def doProcess(mode):


    #FILEPATH=os.listdir("이미지가 저장된 폴더경로")
    # Haar-Feature Model
    CASCADEPATH1="rpi_empty.xml" #circle.xml"

    #모델파일을 이용하여 CascadeClassifier 인스턴스 생성
    cascade1=cv2.CascadeClassifier(CASCADEPATH1)
    minNeighborList=[3]


#################이미지 ######################
    if mode== MODE_IMAGE_PROCESS:
            file="이미지파일이름"
            img=cv2.imread(IMGPATH+"/"+str(file))

            object_info=cascade1.detectMultiScale(img,1.1,1)#350

            for (x,y,w,h) in object_info:
                cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,255),2)

            cv2.imshow("img",img)
            cv2.waitKey()
            cv2.destroyAllWindows()


#################영상 ######################
    if mode == MODE_VIDEO_PROCESS:
        cap=cv2.VideoCapture("videos/juwon2.mp4")


        while 1:
            ret, frame = cap.read()
            frame=np.array(frame)
            #frame=cv2.resize(frame,(int(frame.shape[0]*2),int(frame.shape[1]*2)))
            object_info=cascade1.detectMultiScale(frame,1.5,1)#350



            for(x,y,w,h) in object_info:

                cv2.rectangle(frame, (x ,y), (x + w , y + h), (255, 255, 255), 2)

                cv2.putText(frame, "Fluid empty", (10,100), 2, 2, (255, 255, 255), 2)



            cv2.imshow("cc1",frame)
            # cv2.imshow("cc2", crop_img / saveimg)
            # print(img3)

            if cv2.waitKey(1) & 0xFF == 27:
                break


        cap.release()
        cv2.destroyAllWindows()


doProcess(MODE_VIDEO_PROCESS)
