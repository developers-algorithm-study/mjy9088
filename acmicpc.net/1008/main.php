<?php
$line = explode(' ', fgets(STDIN));
fwrite(STDOUT, (double) intval($line[0]) / intval($line[1]));
?>