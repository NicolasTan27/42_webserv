#!/usr/bin/php
<?php
$entityBody = stream_get_contents(STDIN);
// echo "Body = ", $entityBody, "\n";
parse_str($entityBody, $BODY);
?>

<?php
	$wdir = '/mnt/nfs/homes/ntan/Desktop/42_webserv/data/cgi/php/saved_files/';
	if ($_SERVER['REQUEST_METHOD'] == 'DELETE' && $BODY['file'] != '')
	{
		unlink($wdir . $BODY['file']);
	}
?>

<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<title>Form 42 Webserv</title>
</head>

<body>
<div> <a href="main.php">Main</a> <a href="post.php">Post</a> <a href="delete.php">Delete</a> </div>
<h1>File Destroyer</h1>

<form action="delete.php" method="post" onsubmit="test()">
 	<label for="file">Select a file to delete:</label>
  	<select name="file" id="file">
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

<script>
	function test() {
		var _body = document.getElementById("file").value;
		fetch("delete.php",
		{
			method: 'DELETE',
			body: 'file=' + _body
		}
		);
	}
</script>

</body>
</html>
