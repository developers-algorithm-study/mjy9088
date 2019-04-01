n, m = gets.chomp.split(' ').map(&:to_i)

$i = 0
while $i < m do
    puts("*" * n)
    $i += 1
end
