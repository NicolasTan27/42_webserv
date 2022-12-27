#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	print_r($_SERVER);
	$wdir = $_SERVER['PATH_INFO'];
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<title>Form 42 Webserv</title>
</head>

<body>
	<?php
		$dir = scandir($savedir);
		foreach ($dir as $doc)
		{
			if ($doc != '.' && $doc != '..')
			{
				$op = fopen($wdir . $doc, 'r');
				echo '<h1>' . $doc . '</h1>';
				echo '<div>' . fread($op, filesize($wdir . $doc)) . '</div>';
			}
		}
	?>
</body>

</html>