<!DOCTYPE html>
<html lang="en">
	
<head>
<meta charset="UTF-8">
<title>Nicolas 42 Webserv</title>
</head>

<body>
	<form action="post.php" method="post">
	Name: <input type="text" name="filename"><br>
	E-mail: <input type="text" name="content"><br>
	<input type="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  // collect value of input field
  $name = $_POST['filename'];
  if (empty($name)) {
    echo "Name is empty";
  } else {
    echo $name;
  }
}
?>

</body>
</html> 