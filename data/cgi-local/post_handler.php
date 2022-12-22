<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Sign up OK</title>
    </head>
    
    <body>
        Hello <?php echo $_POST["username"]; ?><br>
        Your favorite color is : <?php echo $_POST["favcolor"]; ?> <button style="color: <?php echo $_POST["favcolor"]; ?>"> </button><br>
    </body>
</html>