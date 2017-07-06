<html>
<head>
	<title>Hello Goorm</title>
</head>
<body>
	<?php
		echo "2 ";
		for($i=3 ; $i<=100 ; $i+=2)
		{
			for($j=2 ; $j<$i ; $j++)
			{
				if($i%$j==0){ break; }
			}
			if($j==$i){ echo $i; }
			echo " ";
		}
	?>
</body>
</html>
