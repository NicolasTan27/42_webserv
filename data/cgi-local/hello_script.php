#!/usr/bin/php
<?php
	$file='/mnt/nfs/homes/ntan/Desktop/42_webserv/data/static/video.mp4';

	header('Content-Type: video/mp4'); #Optional if you'll only load it from other pages
	header('Accept-Ranges: bytes');
	header('Content-Length:'.filesize($file));
	
	readfile($file)
?>
