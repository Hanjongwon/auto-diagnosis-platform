



FILENAME="hyun2"     #이미지 저장이름
PATH="videos/hyun/hyun2.mp4" #이미지 추출할 비디오위치
SAVEPATH="img/hyun/2/"  #이미지 저장될 위치
cap=cv2.VideoCapture(PATH) #카메라 읽기
ret,frames=cap.read()
count=1
while ret:
    count+=1
    _, frames = cap.read()

    #동영상 길이가 너무 길면 샘플의 양이 늘어나므로 조절을 위한 제어문
    #연습용이므로 모든 프레임에 대해서 저장을 진행
    if(count%1==0):

    #GRAY 스케일로 저장
        gray=cv2.cvtColor(frames,cv2.COLOR_BGR2GRAY)

    #이미지 부분읽기 [상 : 하 , 좌 : 우]
        #frames=gray[200:450,500:800]

    #이미지 저장
        cv2.imwrite(SAVEPATH+FILENAME+"_%05d.jpeg"%count,frames)
    #동영상 중단을 위한 코드
    if cv2.waitKey(1)&0xFF==27:
        break

cap.release()