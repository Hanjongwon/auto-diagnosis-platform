<!doctype html>


<html lang="ko">

<head>



 <link rel="stylesheet" href="assets/css/korea-map-font-v1.css">
 <script src="https://code.jquery.com/jquery-3.5.0.js"></script>
<meta charset="utf-8">
 <title>COVID19 Diagnosis system Map</title>

<h1>COVID19 Diagnosis system Map</h1>

<style>
	.korea-map-font-v1 {
	width: 100%;
         font-size: 1000px;
         color: #6E6E6E;
 	Z-index:1; 
	text-align:left;
	position:relative;
	left: 0px;
                          }

status-box {

        width: 80px;

        height: 80px;

        z-index:2;

        border-radius: 50%;

	background-color: white;

	position:absolute;

	opacity: 0.7;

        border: solid;

        text-align:center;
}
.seoul {

        top: 360px;

        left: 400px;

        }

	.incheon{

	top: 340px;

	left:260px;

	}

	.gyeonggi{

	top: 260px;

	left: 370px;

	}

	.jeju{

	top: 830px;

	left: 630px;

	}

	

	.busan{

	top: 700px;

	left: 600px;

	}



	.gangwon{

	top: 280px;

	left: 550px;

	}



	.daegu{

	top: 590px;

	left: 560px;

	}	



	.gwangju{

	top: 730px;

	left: 400px;

	}



	.daejeon{

	top: 500px;

	left: 470px;

	}

	

	.ulsan{

	top: 620px;

	left: 660px;

	}

	

	.chungcheongnam{

	top: 520px;

	left:310px;

	}



	.chungcheongbuk{

	top: 400px;

	left: 520px;

	}

	.jeollanam{

	top:770px;

	left:290px;

	}



	.jeollabuk{

	top: 620px;

	left:379px;

	}



	.gyeongsangnam{

	top: 680px;

	left:500px;

	}

	

	.gyeongsangbuk{

	top: 480px;

	left: 650px;

	}

	.sejong{

	top: 470px;

	left: 380px;

	}

 

	box {width:50px;padding:5px;}



        .color1 { background-color: #AAEBAA;}   

        .color2 { background-color: #FAEB78;} 

        .color3 { background-color: #FF5050;} 	

 </style>
</head>

<body>


<?php
$totalNum = 0;



$SejongNum = 654;



$SeoulNum = 59040;



$IncheonNum = 7984;



$JejuNum = 1496;



$BusanNum = 7171;



$GangwonNum = 3989;



$DaeguNum = 11067;



$GwangjuNum = 3180;



$DaejeonNum = 3389;



$UlsanNum = 3038;



$GyeonggiNum = 51077;



$ChungcheongnamNum = 4463;



$ChungcheongbukNum = 3530;



$JeollanamNum = 1822;



$JeollabukNum = 2538;



$GyeongsangnamNum = 6148;



$GyeongsangbukNum = 5179;

$SejongNum1 = 0;



$SeoulNum1 = 0;



$IncheonNum1 = 0;



$JejuNum1 = 0;



$BusanNum1 = 0;



$GangwonNum1 = 0;



$DaeguNum1 = 0;



$GwangjuNum1 = 0;



$DaejeonNum1 = 0;



$UlsanNum1 = 0;



$GyeonggiNum1 = 0;



$ChungcheongnamNum1 = 0;



$ChungcheongbukNum1 = 0;



$JeollanamNum1 = 0;



$JeollabukNum1 = 0;



$GyeongsangnamNum1 = 0;



$GyeongsangbukNum1 = 0;

 $conn = mysqli_connect( '192.168.200.150', 'KWIX', 'raspberry', 'userDB' );



      $sql = "SELECT * FROM userInfo WHERE result = '1' ";

      $result = mysqli_query( $conn, $sql );

         while( $row = mysqli_fetch_array( $result ) ) {   
	$location = $row[ 'Location' ];

  	 $totalNum = $totalNum + 1;
	
	switch($location){















        case "Seoul":







         $SeoulNum++;

	$SeoulNum1++;

	





         break;







        case "jeju-do":







         $JejuNum++;

	 $JejuNum1++;





         break;







        case "Gangwon-do":







         $GangwonNum++;

	$GangwonNum1++;







         break;



   



   case "Incheon":







         $IncheonNum++;

	$IncheonNum1++;







         break;



   



   case "Busan":







         $BusanNum++;

	$BusanNum1++;









         break;





   case "Sejong":







         $SejongNum++;

	 $SejongNum1++;







         break;





   case "Daegu":







         $DaeguNum++;

	$DaeguNum1++;







         break;







   case "Gwangju":







         $GwangjuNum++;

	 $GwangjuNum1++;







         break;







   case "Daejeon":







         $DaejeonNum++;

	$DaejeonNum1++;







         break;







   case "Ulsan":







         $UlsanNum++;

	 $UlsanNum1++;







         break;







   case "Gyeonggi-do":







         $GyeonggiNum++;

	$GyeonggiNum1++;







         break;







   case "Chungcheongnam-do":







         $ChungcheongnamNum++;

	$ChungcheongnamNum1++;



	



         break;







   case "Chungcheongbuk-do":







         $ChungcheongbukNum++;

	$ChungcheongbukNum1++;







         break;



   



   case "Jeollanam-do":







         $JeollanamNum++;

	$JeollanamNum1++;







         break;







   case "Jeollabuk-do":







         $JeollabukNum++;

	$JeollabukNum1++;







         break;







   case "Gyeongsangnam-do":







         $GyeongsangnamNum++;

	$GyeongsangnamNum1++;



	



         break;







   case "Gyeongsangbuk-do":







         $GyeongsangbukNum++;

	$GyeongsangbukNum1++;



	

         break;


      }


}
?>
<box class="color1">~10</box>

	 <box class="color2">~50</box>

	 <box class="color3">50++</box>

	<br>

	<br>

	(일일 확진자수 기준)

	

	<status-box class="seoul">

	서울<br>

	<b style="font-size:20px;">(+<?php echo $SeoulNum1;?>)</b><br>

	<?php echo $SeoulNum;?>  

	</status-box class="seoul">

</status-box>	



	<status-box class="incheon">

        인천<br>

       	<b style="font-size:20px;">(+<?php echo $IncheonNum1;?>)</b><br>

        <?php echo $IncheonNum;?> 

        </status-box class="incheon">



	<status-box class="gyeonggi">

        경기<br>

	<b style="font-size:20px;">(+<?php echo $GyeonggiNum1;?>)</b><br>

        <?php echo $GyeonggiNum;?>  

        </status-box class="gyeonggi">



	<status-box class="jeju">

        제주<br>

	<b style="font-size:20px;">(+<?php echo $JejuNum1;?>)</b><br>

        <?php echo $JejuNum;?>  

        </status-box class="jeju">



	<status-box class="busan">

        부산<br>

	<b style="font-size:20px;">(+<?php echo $BusanNum1;?>)</b><br>

        <?php echo $BusanNum;?>  

        </status-box class="busan">



	<status-box class="gangwon">

        강원<br>

	<b style="font-size:20px;">(+<?php echo $GangwonNum1;?>)</b><br>

        <?php echo $GangwonNum;?>  

        </status-box class="gangwon">





	<status-box class="daegu">

        대구<br>

	<b style="font-size:20px;">(+<?php echo $DaeguNum1;?>)</b><br>

        <?php echo $DaeguNum;?>  

        </status-box class="daegu">



	<status-box class="gwangju">

       	광주<br>

	<b style="font-size:20px;">(+<?php echo $GwangjuNum1;?>)</b><br>

        <?php echo $GwangjuNum;?>  

        </status-box class="gwangju">



	<status-box class="daejeon">

        대전<br>

	<b style="font-size:20px;">(+<?php echo $DaejeonNum1;?>)</b><br>

        <?php echo $DaejeonNum;?>  

        </status-box class="daejeon">



	<status-box class="ulsan">

        울산<br>

	<b style="font-size:20px;">(+<?php echo $UlsanNum1;?>)</b><br>

        <?php echo $UlsanNum;?>  

        </status-box class="ulsan">



	<status-box class="chungcheongnam">

        충남<br>

	<b style="font-size:20px;">(+<?php echo $ChungcheongnamNum1;?>)</b><br>

        <?php echo $ChungcheongnamNum;?>  

        </status-box class="chungcheongnam">



	<status-box class="chungcheongbuk">

        충북<br>

	<b style="font-size:20px;">(+<?php echo $ChungcheongbukNum1;?>)</b><br>

        <?php echo $ChungcheongbukNum;?>  

        </status-box class="chungcheongbuk">



	<status-box class="jeollanam">

        전남<br>

	<b style="font-size:20px;">(+<?php echo $JeollanamNum1;?>)</b><br>

        <?php echo $JeollanamNum;?>  

        </status-box class="jeollanam">



	<status-box class="jeollabuk">

        전북<br>

	<b style="font-size:20px;">(+<?php echo $JeollabukNum1;?>)</b><br>

        <?php echo $JeollabukNum;?>  

        </status-box class="jeollabuk">



	<status-box class="gyeongsangnam">

        경남<br>

	<b style="font-size:20px;">(+<?php echo $GyeongsangnamNum1;?>)</b><br>

        <?php echo $GyeongsangnamNum;?>  

        </status-box class="gyeongsangnam">



	<status-box class="gyeongsangbuk">

        경북<br>

	<b style="font-size:20px;">(+<?php echo $GyeongsangbukNum1;?>)</b><br>

        <?php echo $GyeongsangbukNum;?>  

        </status-box class="gyeongsangbuk">



	<status-box class="sejong">

        세종<br>

	<b style="font-size:20px;">(+<?php echo $SejongNum1;?>)</b><br>

        <?php echo $SejongNum;?>  

        </status-box class="sejong">

<ul class= "korea-map-font-v1">











  <li class="강원">a</li>







  <li class="경기">b</li>







  <li class="경남">c</li>







  <li class="경북">d</li>







  <li class="광주">e</li>







  <li class="대구">f</li>







  <li class="대전">g</li>







<li class="부산">h</li>







  <li class="서울">i</li>







  <li class="세종">j</li>







  <li class="울산">k</li>







  <li class="인천">l</li>







  <li class="전남">m</li>







  <li class="전북">n</li>







  <li class="제주">o</li>







  <li class="충남">p</li>







<li class="충북">q</li>



<script>

	  

           $(function(){

	var seoulnum2 = <?php echo $SeoulNum1; ?>;

		var seoulnum = parseInt(seoulnum2 / 10)

		switch(seoulnum){

		case 0 :

                $('.서울').css('color' , '#AAEBAA');

                break



		case 1 :

		case 2 :		

		case 3 :

		case 4 :

                $('.서울').css('color' , '#FAEB78');

                break

		

		default :

		$('.서울').css('color' , '#FF5050');

		break	

		}



		});







	 $(function(){

                var jejunum2 = <?php echo $JejuNum1; ?>;

		var jejunum = parseInt(jejunum2 / 10)

		switch(jejunum){



		case 0 :

                $('.제주').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.제주').css('color' , '#FAEB78');

                break

                

                default :

                $('.제주').css('color' , '#FF5050');

                break   

                }



                });





	 $(function(){

                var incheonnum2 = <?php echo $IncheonNum1; ?>;

		var incheonnum = parseInt(incheonnum2 / 10)

		switch(incheonnum){

		case 0 :

                $('.인천').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.인천').css('color' , '#FAEB78');

                break

                

                default :

                $('.인천').css('color' , '#FF5050');

                break   

                }



                });





	 $(function(){

                var busannum2 = <?php echo $BusanNum1; ?>;

		var busannum = parseInt(busannum2 / 10)

		switch(busannum){

		case 0 :

                $('.부산').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.부산').css('color' , '#FAEB78');

                break

                

                default :

                $('.부산').css('color' , '#FF5050');

                break   

                }



                });







	 $(function(){

                var gangwonnum2 = <?php echo $GangwonNum1; ?>;

		var gangwonnum = parseInt(gangwonnum2 / 10)

		switch(gangwonnum){

		case 0 :

                $('.강원').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.강원').css('color' , '#FAEB78');

                break

                

                default :

                $('.강원').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var daegunum2 = <?php echo $DaeguNum1; ?>;

		var daegunum = parseInt(daegunum2 / 10)

		switch(daegunum){

		case 0 :

                $('.대구').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.대구').css('color' , '#FAEB78');

                break

                

                default :

                $('.대구').css('color' , '#FF5050');

                break   

                }



                });

		





	 $(function(){

                var gwangjunum2 = <?php echo $GwangjuNum1; ?>;

		var gwangjunum = parseInt(gwangjunum2 / 10)

		switch(gwangjunum){



		case 0 :

                $('.광주').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.광주').css('color' , '#FAEB78');

                break

                

                default :

                $('.광주').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var daejeonnum2 = <?php echo $DaejeonNum1; ?>;

		var daejeonnum = parseInt(daejeonnum2 / 10)

		switch(daejeonnum){

		case 0 :

                $('.대전').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.대전').css('color' , '#FAEB78');

                break

                

                default :

                $('.대전').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var ulsannum2 = <?php echo $UlsanNum1; ?>;

		var ulsannum = parseInt(ulsannum2 / 10)

		switch(ulsannum){



		case 0 :

                $('.울산').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.울산').css('color' , '#FAEB78');

                break

                

                default :

                $('.울산').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var gyeongginum2 = <?php echo $GyeonggiNum1; ?>;

		var gyeongginum = parseInt(gyeongginum2 / 10)

		switch(gyeongginum){

		case 0 :

                $('.경기').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.경기').css('color' , '#FAEB78');

                break

                

                default :

                $('.경기').css('color' , '#FF5050');

                break   

                }



                });





	 $(function(){

                var chungcheongnamnum2 = <?php echo $ChungcheongnamNum1; ?>;

		var chungcheongnamnum = parseInt(chungcheongnamnum2 / 10)

		switch(chungcheongnamnum){



		case 0 :

                $('.충남').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.충남').css('color' , '#FAEB78');

                break

                

                default :

                $('.충남').css('color' , '#FF5050');

                break   

                }



                });





	 $(function(){

                var chungcheongbuknum2 = <?php echo $ChungcheongbukNum1; ?>;

		var chungcheongbuknum = parseInt(chungcheongbuknum2 / 10)

		switch(chungcheongbuknum){

		case 0 :

                $('.충북').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.충북').css('color' , '#FAEB78');

                break

                

                default :

                $('.충북').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var jeollanamnum2 = <?php echo $JeollanamNum1; ?>;

		var jeollanamnum = parseInt(jeollanamnum2 / 10)

		switch(jeollanamnum){

		case 0 :

                $('.전남').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.전남').css('color' , '#FAEB78');

                break

                

                default :

                $('.전남').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var jeollabuknum2 = <?php echo $JeollabukNum1; ?>;

		var jeollabuknum = parseInt(jeollabuknum2 / 10)

		switch(jeollabuknum){

		case 0 :

                $('.전북').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.전북').css('color' , '#FAEB78');

                break

                

                default :

                $('.전북').css('color' , '#FF5050');

                break   

                }



                });





	 $(function(){

                var gyeongsangnamnum2 = <?php echo $GyeongsangnamNum1; ?>;

		var gyeongsangnamnum = parseInt(gyeongsangnamnum2 / 10)

		switch(gyeongsangnamnum){

		case 0 :

                $('.경남').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.경남').css('color' , '#FAEB78');

                break

                

                default :

                $('.경남').css('color' , '#FF5050');

                break   

                }



                });







	 $(function(){

                var gyeongsangbuknum2 = <?php echo $GyeongsangbukNum1; ?>;

		var gyeongsangbuknum = parseInt(gyeongsangbuknum2 /10)

		switch(gyeongsangbuknum){

		case 0 :

                $('.경북').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.경북').css('color' , '#FAEB78');

                break

                

                default :

                $('.경북').css('color' , '#FF5050');

                break   

                }



                });



	 $(function(){

                var sejongnum2 = <?php echo $SejongNum1; ?>;

		var sejongnum = parseInt(sejongnum2 / 10)

		switch(sejongnum){

		case 0 :

                $('.세종').css('color' , '#AAEBAA');

                break



                case 1 :

                case 2 :

                case 3 :

                case 4 :

                $('.세종').css('color' , '#FAEB78');

                break

                

                default :

                $('.세종').css('color' , '#FF5050');

                break   

                }



                });





</script>





</ul>







</body>







</html>


