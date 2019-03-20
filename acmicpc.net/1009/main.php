<?php
function solve($a, $b)
{
	if($b == 1)
	{
		return $a % 10;
	}
	if($b % 2)
	{
		return $a * solve(($a * $a) % 10, (int)($b / 2)) % 10;
	}
	else
	{
		return $b ? solve(($a * $a) % 10, (int)($b / 2)) % 10 : 1;
	}
}
$T = fgets(STDIN);
$result = '';
for($i = 0; $i < $T; $i++)
{
	$line = explode(' ', fgets(STDIN));
	$result .= (9 + solve(intval($line[0]), intval($line[1]))) % 10 + 1 . "\n";
}
fwrite(STDOUT, $result);
?>