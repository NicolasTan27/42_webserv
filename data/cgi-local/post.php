<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	$wdir = '/mnt/nfs/homes/ntan/Desktop/42_webserv/data/cgi-local/';
	$filename =  $wdir . 'saved_files/' . $BODY['filename'] . '.txt';
	$file = fopen($filename, "w") or die ("Unable to open file");
	fwrite($file, $BODY['content']);
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<title>Form 42 Webserv</title>
</head>

	<body>
		<?php
			$dir = scandir($wdir . '/saved_files');
			
			print_r($dir);
		?>
	</body>

</html>