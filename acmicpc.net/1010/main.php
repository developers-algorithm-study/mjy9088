<?php
function solve($s, $b)
{
	$result = 1;
	$p2 = 0;
	$p3 = 0;
	$p5 = 0;
	$p7 = 0;
	for($i = 0; $i < $s; $i++)
	{
		$tmp = $b - $i;
		while($tmp % 2 == 0) { $p2++; $tmp /= 2; }
		while($tmp % 3 == 0) { $p3++; $tmp /= 3; }
		while($tmp % 5 == 0) { $p5++; $tmp /= 5; }
		while($tmp % 7 == 0) { $p7++; $tmp /= 7; }
		$result *= $tmp;
	}
	for($i = 0; $i < $s; $i++)
	{
		$tmp = $i + 1;
		while($p2 && $tmp % 2 == 0) { $p2--; $tmp /= 2; }
		while($p3 && $tmp % 3 == 0) { $p3--; $tmp /= 3; }
		while($p5 && $tmp % 5 == 0) { $p5--; $tmp /= 5; }
		while($p7 && $tmp % 7 == 0) { $p7--; $tmp /= 7; }
		$result /= $tmp;
	}
	while($p2) { $p2--; $result *= 2; }
	while($p3) { $p3--; $result *= 3; }
	while($p5) { $p5--; $result *= 5; }
	while($p7) { $p7--; $result *= 7; }
	return $result;
}
$T = fgets(STDIN);
$result = '';
for($i = 0; $i < $T; $i++)
{
	$line = explode(' ', fgets(STDIN));
	$result .= solve($line[0], $line[1]) . "\n";
}
fwrite(STDOUT, $result);
?>