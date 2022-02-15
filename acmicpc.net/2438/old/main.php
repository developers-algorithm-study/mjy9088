<?php
$N = intval(fgets(STDIN));
for($i = 0; $i < $N; $i++)
{
	for($j = 0; $j <= $i; $j++)
	{
		fwrite(STDOUT, '*');
	}
	fwrite(STDOUT, "\n");
}
?>