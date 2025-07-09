<!doctype html>

<html lang="ko">

<head>

<meta charset="utf-8">



<style>
 table {

        width: 100%;
      }

 th, td {
        padding: 10px;
        border-bottom: 3px solid #dadada;
        text-align: right;
      }
  div.table {
	width:600px;
	height: 950px;
	overflow:scroll;
        float: right;
                }
 </style>
</head>
<body>



<div class='table'>



<table>
      <thead>
        <tr>
	<th>id</th>
          <th>Name</th>
          <th>Location</th>
          <th>DateTime</th>
          <th>concentration</th>
        </tr>
      </thead>
      <tbody>
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











   echo '<tr><td>'.$row['id'].'</td><td>'.$row['Name'].'</td><td>'.$row['Location'].'</td><td>'.$row['DateTime'].'</td><td>'.$row['concentration'].'</td><td>'.'</td></tr>';



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


   echo '<span style="background: #F9F7F6;font-size:25px;font-weight:bold; border-left: 0.5em solid #688FF4; padding: 0.5em;">'.'confirmed cases'.'</span>';



   echo '<p><span style="border-bottom: 12px solid #dcf1fb;font-size:20px; font-weight:bold;  padding: 0 0 0 0.2em;">'.'total: '.$totalNum.'</span>'.'</p>';

























?>



 </tbody>







    </table>



</div>


</body>







</html>
