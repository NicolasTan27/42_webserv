#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	$wdir = '/mnt/nfs/homes/ntan/Desktop/42_webserv/data/cgi-local/saved_files/';
?>

<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<title>Form 42 Webserv</title>
</head>

<body>
<h1>File Destroyer</h1>

<form action="delete.php" method="post">
 	<label for="files">Select a file to delete:</label>
  	<select name="files" if ="files">
  		<option value="">Select a file</option>
		<?php
			$dir = scandir($wdir);
			foreach ($dir as $doc)
			{
				if ($doc != '.' && $doc != '..')
				{
					$op = fopen($wdir . $doc, 'r');
					echo '<option value="' . $doc . '">'. $doc .'</h1>';
				}
			}
		?>

	</select>
	<br><br>
	<input type="submit" value="delete">
</form>

</body>
</html>
