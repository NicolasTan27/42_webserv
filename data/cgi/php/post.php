#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	// print_r($BODY);
	$cwd = getcwd();
	$wdir = $cwd . '/data/cgi/php/';
	if ($_SERVER['REQUEST_METHOD'] == 'POST' && $BODY['filename'] != "")
	{
		$nfile = $BODY['filename'];
		$filename =  $wdir . 'saved_files/' . str_replace('"', "", $nfile);;
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
<div> <a href="/cgi/php/main.php">Main</a> <a href="/cgi/php/upload.php">Upload</a> <a href="/cgi/php/post.php">Post</a> <a href="/cgi/php/delete.php">Delete</a> </div>
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
