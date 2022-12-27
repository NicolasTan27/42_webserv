#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	$cwd = getcwd();
	// echo $cwd;
	$wdir = $cwd . '/data/cgi/php/';
	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$filename =  $wdir . 'saved_files/' . $BODY['filename'];
		$file = fopen($filename, "w") or die ("Unable to open file");
		fwrite($file, $BODY['content']);
	}
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<title>Form 42 Webserv</title>
</head>

<body>
<div> <a href="main.php">Main</a> <a href="post.php">Post</a> <a href="delete.php">Delete</a> </div>
	<?php
		$savedir = $wdir . 'saved_files/';
		$dir = scandir($savedir);
		foreach ($dir as $doc)
		{
			if ($doc != '.' && $doc != '..')
			{
				$op = fopen($savedir . $doc, 'r');
				echo '<h1>' . $doc . '</h1>';
				echo '<div>' . fread($op, filesize($savedir . $doc)) . '</div>';
			}
		}
	?>
</body>

</html>