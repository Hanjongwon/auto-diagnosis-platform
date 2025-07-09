import sys
import  os


folder="cvt/leaving"

txtPath=folder+"/txt/"
imgPath=folder+"/img/"

count=0000
list=os.listdir(txtPath)
imglist=os.listdir(imgPath)

context=""

#쓰기용 파일 생성
w = open(folder+".txt", 'w')


def fileConvert():
    avg_width=0
    avg_height=0
    count=0

    #텍스트 읽어들임.
    for file in list:
        print(file)

        #파일명추출
        filename=file.split('.')
        print(filename[0]+'.jpeg')

        #파일오픈
        f = open(txtPath+file)

        #내용 읽어들임.
        st=f.readline()

        #st==0이면 라벨한 object가 0이라는 뜻이므로 pass
        if(int(st)==0):

            #파일 닫고 필요없는 텍스트 제거
            f.close()
            os.remove(txtPath+file)
            continue

        #st가 0이아닐때
        w.write(imgPath+filename[0]+'.jpeg ')
        # w.write(str(int(st)))
        #object 수를 작성
        w.write(str(int(st)))

        #object의 수에 따라 반복
        for i in range(int(st)):
            br = f.readline()
            ls = br.split()
            w.write(" ")

            #라벨링 위치를 읽어들임, (0,1,2,3) --> (x,y,x',y')
            #라벨툴 포맷에서 opencv가 요구하는 포맷으로 변경하는 과정.
            w.write(str(int(ls[0]))+" ")
            w.write(str(int(ls[1]))+" ")
            w.write(str(int(ls[2])-int(ls[0]))+" ")
            w.write(str(int(ls[3])-int(ls[1]))+" ")
            count+=1
            avg_width+=int(ls[2])-int(ls[0])
            avg_height+=int(ls[3])-int(ls[1])
        w.write("\n")

    #모든 파일에 대해 반복하고 종료되어 최종적으로 하나의 텍스트파일로 작성.
    f.close()
    w.close()
    print(avg_width/count,avg_height/count)

def make_text():

    #이미지 파일을 이미지 디렉토리에서 읽음.
    for imgfile in imglist:

        #이미지 파일의 이름을 분리 (예 filled_1.jpg > [filled_1 , jpg]
        filename=imgfile.split('.')[0]

        #텍스트문서로 만들기 위해 새로 파일을 만듬.
        f = open(txtPath+filename+".txt",'w')
        # 라벨툴이 요구하는 포맷으로 변경.
        f.write("1\n")

        # 내용작성
        f.write("122 104 137 138")

        # 저장
        f.close()



def fileConvert2():
    for file in list:
        txt=open(file,"w")
        print(file)
        filename=file.split('.')
        print(filename[0]+'.jpeg')
        f = open(txtPath+file)

        st=f.readline()
        if(int(st)==0):
            f.close()
            os.remove(txtPath+file)
            continue


        # w.write(str(int(st)))
        txt.write(str(int(st)))
        txt.write("\n")



        for i in range(int(st)):
            br = f.readline()
            ls = br.split()

            txt.write(str(int(ls[0])-100)+" ")
            txt.write(str(int(ls[1])-100)+" ")
            txt.write(str(int(ls[2])-100)+" ")
            txt.write(str(int(ls[3])-100)+" ")

            # txt.write(str(int(ls[0]))+" ")
            # txt.write(str(int(ls[1]))+" ")
            # txt.write(str(int(ls[2]))+" ")
            # txt.write(str(int(ls[3]))+" ")
    w.close()
    txt.close()



#텍스트파일의 object가 0인경우 (st==0) 해당 텍스트와 매치되는 이미지는 필요없으므로 제거하는 코드.
def file_remove():
    imglist=os.listdir(imgPath)
    txtlist=os.listdir(txtPath)

    # for txtfile in txtlist:
    #     filename=txtfile.split('.')[0]
    #     try:
    #         imgf=open("filled/"+filename+".jpeg")
    #     except Exception as e:
    #         print(e)
    #         os.remove(txtPath+txtfile)
    for imgfile in imglist:
        filename=imgfile.split('.')[0]

        try:
            # print("txt/"+filename+".txt")
            txtf=open("txt/"+filename+".txt")
            if int(txtf.readline())==0:
                # print(imgPath+imgfile +"deleted")
                os.remove(imgPath+imgfile)
            txtf.close()


        except Exception as e:
            # print(imgPath + imgfile + " deleted")
            print(e)
            os.remove(imgPath+imgfile)

            # txtf.close()


    # txtf.close()
    w.close()
def removeblank():
    imglist = os.listdir(imgPath)
    txtlist = os.listdir(txtPath)

    for imgfile in imglist:
        filename = imgfile.split(' ')[0]
        try:
            extends=imgfile.split(' ')[1]
            os.rename(imgPath+imgfile,imgPath+filename+extends)
            print(extends)
        except Exception as e:
            continue

    for txtfile in txtlist:
        filename = txtfile.split(' ')[0]
        try:
                extends = txtfile.split(' ')[1]
                os.rename(txtPath + txtfile, txtPath + filename + extends)
                print(extends)
        except Exception as e:
                continue

        # if imgfile.split(' ')[1]:
        #     os.replace(imgfile,filename[0]+filename[1])



    # txtf.close()



# removeblank()
fileConvert()
file_remove()
# make_text()



#
# import cv2
# count=0
# list=os.listdir("img/insuff")
#
# count =1000
# for file in list :
#     img=cv2.imread("img/insuff/"+file)
#     filename=file.split('.')
#     cv2.imwrite("img/insuff/insuff_"+str(count)+".jpeg",img)
#     os.remove("img/insuff/"+file)
#     count+=1
#     # os.remove("Image/"+file)


