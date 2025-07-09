import sys
import  os
import cv2

folder="BBox-Label-Tool-master/Images/hyun"


imgPath=folder+"/"

count=0000
#list=os.listdir(txtPath)
imglist=os.listdir(imgPath)

context=""

#쓰기용 파일 생성
w = open(folder+".txt", 'w')

def img_rotate(output_path="BBox-Label-Tool-master/Images/hyun/",degree=0):
    if not os.path.isdir(output_path):
        os.mkdir(output_path)

    for img_name in imglist:
        img_dir=os.path.join(imgPath,img_name)
        original_img=cv2.imread(img_dir)
        height,width,channel=original_img.shape
        matrix=cv2.getRotationMatrix2D((width/2,height/2),degree,1)
        rotated_img=cv2.warpAffine(original_img,matrix,(width,height))

        saved_img_path=output_path+"angle_"+str(degree)+"_"+img_name
        cv2.imwrite(saved_img_path,rotated_img)
        print(f"{saved_img_path} were created successfully.")

def img_brighten(output_path="img/fluid2/brighten/",brighteness=-100):
    if not os.path.isdir(output_path):
        os.mkdir(output_path)

    for img_name in imglist:

        img_dir=os.path.join(imgPath,img_name)
        original_img=cv2.imread(img_dir)
        original_img=cv2.cvtColor(original_img,cv2.COLOR_BGR2GRAY)
        height,width=original_img.shape


        brighteness_img=cv2.add(original_img,brighteness)

        saved_img_path=output_path+"brighten_"+str(brighteness)+"_"+img_name
        cv2.imwrite(saved_img_path,brighteness_img)
        print(f"{saved_img_path} were created successfully.")



#함수사용

img_rotate("BBox-Label-Tool-master/Images/hyun/",45) # img_rotate("이미지저장위치","회전각도")
img_brighten("BBox-Label-Tool-master/Images/hyun/",90)#img_rotate("이미지저장위치","밝기")