#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	$cwd = getcwd();
	// print_r($_SERVER);
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
		$dir = scandir($wdir);
		foreach ($dir as $doc)
		{
			echo '<h1>' . $doc . '</h1>';
			if ($_SERVER['QUERY_STRING'] == "/")
				echo '<a href="'. $_SERVER['QUERY_STRING'].$doc .'">'.$doc.'</a>';
			else
				echo '<a href="'. $_SERVER['QUERY_STRING']."/".$doc .'">'.$doc.'</a>';
		}
	?>
</body>

</html>